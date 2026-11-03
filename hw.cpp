#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <set>
#include <cmath>

using namespace std;

// 4x4 K-map 對應格雷碼順序的編號
const int kmapGrid[4][4] = {
    { 0,  1,  3,  2 },
    { 4,  5,  7,  6 },
    { 12, 13, 15, 14 },
    { 8,  9,  11, 10 }
};

struct Group {
    int size;
    vector<int> coveredMinterms;
    string simplifiedTerm;

    Group(int s, vector<int> terms, string term) {
        size = s;
        coveredMinterms = terms;
        simplifiedTerm = term;
    }
};

void FindPosition(int minterm, int &row, int &col) {
    for (int r = 0; r < 4; r++) {
        for (int c = 0; c < 4; c++) {
            if (kmapGrid[r][c] == minterm) {
                row = r;
                col = c;
                return;
            }
        }
    }
}

// 產生化簡後的字串項 (確保 A, B, C, D 順序正確，如 A'B'C'D')
string GenerateSimplifiedTerm(const vector<int>& coveredMinterms) {
    int size = coveredMinterms.size();
    if (size == 16) return "1";

    // 檢查 4 個變數 A, B, C, D 在此群組內是否保持不變
    // A: 8 bits 0, 8 bits 1 -> 依 row/col 對應
    bool a_all_0 = true, a_all_1 = true;
    bool b_all_0 = true, b_all_1 = true;
    bool c_all_0 = true, c_all_1 = true;
    bool d_all_0 = true, d_all_1 = true;

    for (int m : coveredMinterms) {
        // m 的 4 個位元: A = (m >> 3) & 1, B = (m >> 2) & 1, C = (m >> 1) & 1, D = m & 1
        int a = (m >> 3) & 1;
        int b = (m >> 2) & 1;
        int c = (m >> 1) & 1;
        int d = m & 1;

        if (a == 0) a_all_1 = false; else a_all_0 = false;
        if (b == 0) b_all_1 = false; else b_all_0 = false;
        if (c == 0) c_all_1 = false; else c_all_0 = false;
        if (d == 0) d_all_1 = false; else d_all_0 = false;
    }

    string term = "";
    if (a_all_0) term += "A'";
    else if (a_all_1) term += "A";

    if (b_all_0) term += "B'";
    else if (b_all_1) term += "B";

    if (c_all_0) term += "C'";
    else if (c_all_1) term += "C";

    if (d_all_0) term += "D'";
    else if (d_all_1) term += "D";

    return term;
}

// 檢查某個 minterm 集合是否為合法的 K-map 矩形群組 (大小必須是 2 的次方，且在拓撲上相鄰)
bool IsValidGroup(const vector<int>& terms) {
    int sz = terms.size();
    if (sz != 1 && sz != 2 && sz != 4 && sz != 8 && sz != 16) return false;

    // 將所有 minterm 轉成對應的 (r, c)
    set<pair<int, int>> coords;
    for (int m : terms) {
        int r, c;
        FindPosition(m, r, c);
        coords.insert({r, c});
    }

    // 檢查是否所有點都能透過平移構成合法的 2^k 大小群組
    // 簡單方法：檢查是否能找到起始 (sr, sc) 與高寬 (h, w)
    for (int sr = 0; sr < 4; sr++) {
        for (int sc = 0; sc < 4; sc++) {
            for (int h : {1, 2, 4}) {
                for (int w : {1, 2, 4}) {
                    if (h * w != sz) continue;
                    set<pair<int, int>> target;
                    bool possible = true;
                    for (int dr = 0; dr < h; dr++) {
                        for (int dc = 0; dc < w; dc++) {
                            target.insert({(sr + dr) % 4, (sc + dc) % 4});
                        }
                    }
                    if (target == coords) return true;
                }
            }
        }
    }
    return false;
}

// 尋找所有可能的質涵蓋項 (Prime Implicants)
vector<Group*> FindAllPrimeImplicants(const vector<int>& minterms) {
    vector<Group*> allPIs;
    set<set<int>> foundTerms;

    // 產生所有可能的 2^k 組合 (從 16, 8, 4, 2, 1 個格子中尋找)
    // 為了精確，我們直接走訪所有可能大小的方格座標組合
    vector<int> sizes = {16, 8, 4, 2, 1};
    
    // 收集所有合法矩形群組
    vector<vector<int>> allValidGroups;
    for (int h : {1, 2, 4}) {
        for (int w : {1, 2, 4}) {
            int sz = h * w;
            for (int sr = 0; sr < 4; sr++) {
                for (int sc = 0; sc < 4; sc++) {
                    vector<int> groupTerms;
                    for (int dr = 0; dr < h; dr++) {
                        for (int dc = 0; dc < w; dc++) {
                            int r = (sr + dr) % 4;
                            int c = (sc + dc) % 4;
                            groupTerms.push_back(kmapGrid[r][c]);
                        }
                    }
                    // 檢查這個群組裡的所有 minterm 是否都在給定的 minterms 裡面
                    bool allContained = true;
                    for (int t : groupTerms) {
                        if (find(minterms.begin(), minterms.end(), t) == minterms.end()) {
                            allContained = false;
                            break;
                        }
                    }
                    if (allContained) {
                        sort(groupTerms.begin(), groupTerms.end());
                        allValidGroups.push_back(groupTerms);
                    }
                }
            }
        }
    }

    // 過濾掉被其他更大群組完全包含的群組（留下 Prime Implicants）
    for (size_t i = 0; i < allValidGroups.size(); i++) {
        bool isPrime = true;
        for (size_t j = 0; j < allValidGroups.size(); j++) {
            if (i == j) continue;
            // 如果 group i 是 group j 的子集，且 group j 更大，則 group i 不是 PI
            if (allValidGroups[j].size() > allValidGroups[i].size()) {
                set<int> set_i(allValidGroups[i].begin(), allValidGroups[i].end());
                set<int> set_j(allValidGroups[j].begin(), allValidGroups[j].end());
                bool isSub = true;
                for (int val : set_i) {
                    if (set_j.find(val) == set_j.end()) {
                        isSub = false;
                        break;
                    }
                }
                if (isSub) {
                    isPrime = false;
                    break;
                }
            }
        }
        if (isPrime) {
            set<int> s(allValidGroups[i].begin(), allValidGroups[i].end());
            if (foundTerms.find(s) == foundTerms.end()) {
                foundTerms.insert(s);
                string termStr = GenerateSimplifiedTerm(allValidGroups[i]);
                allPIs.push_back(new Group(allValidGroups[i].size(), allValidGroups[i], termStr));
            }
        }
    }

    return allPIs;
}

int main() {
    string input;
    if (!getline(cin, input)) return 0;

    stringstream ss(input);
    vector<int> minterms;
    int val;
    while (ss >> val) {
        minterms.push_back(val);
    }

    if (minterms.empty()) return 0;
    if (minterms.size() == 16) {
        cout << "1" << endl;
        return 0;
    }

    // 找出所有 PIs
    vector<Group*> allPIs = FindAllPrimeImplicants(minterms);

    // 找出 Essential Prime Implicants (EPIs)
    vector<Group*> epis;
    for (int m : minterms) {
        vector<Group*> coveringPIs;
        for (auto pi : allPIs) {
            if (find(pi->coveredMinterms.begin(), pi->coveredMinterms.end(), m) != pi->coveredMinterms.end()) {
                coveringPIs.push_back(pi);
            }
        }
        if (coveringPIs.size() == 1) {
            if (find(epis.begin(), epis.end(), coveringPIs[0]) == epis.end()) {
                epis.push_back(coveringPIs[0]);
            }
        }
    }

    vector<Group*> finalGroups = epis;
    vector<int> uncovered = minterms;

    // 移除已被 EPI 覆蓋的 minterms
    for (auto epi : epis) {
        uncovered.erase(
            remove_if(uncovered.begin(), uncovered.end(), [&](int m) {
                return find(epi->coveredMinterms.begin(), epi->coveredMinterms.end(), m) != epi->coveredMinterms.end();
            }),
            uncovered.end()
        );
    }

    // 貪婪法覆蓋剩餘的 minterms
    while (!uncovered.empty()) {
        Group* bestPI = nullptr;
        int maxCover = -1;

        for (auto pi : allPIs) {
            if (find(finalGroups.begin(), finalGroups.end(), pi) != finalGroups.end()) continue;
            int count = 0;
            for (int m : uncovered) {
                if (find(pi->coveredMinterms.begin(), pi->coveredMinterms.end(), m) != pi->coveredMinterms.end()) {
                    count++;
                }
            }
            if (count > maxCover) {
                maxCover = count;
                bestPI = pi;
            }
        }

        if (bestPI == nullptr) break;
        finalGroups.push_back(bestPI);
        uncovered.erase(
            remove_if(uncovered.begin(), uncovered.end(), [&](int m) {
                return find(bestPI->coveredMinterms.begin(), bestPI->coveredMinterms.end(), m) != bestPI->coveredMinterms.end();
            }),
            uncovered.end()
        );
    }

    // 依照字母或項長度排序輸出，確保格式美觀一致
    vector<string> outputTerms;
    for (auto g : finalGroups) {
        outputTerms.push_back(g->simplifiedTerm);
    }
    sort(outputTerms.begin(), outputTerms.end());

    for (size_t i = 0; i < outputTerms.size(); i++) {
        cout << outputTerms[i];
        if (i < outputTerms.size() - 1) {
            cout << " + ";
        }
    }
    cout << endl;

    for (auto pi : allPIs) delete pi;
    return 0;
}