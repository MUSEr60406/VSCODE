#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <set>

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

// 輔助函式：根據 minterm 編號找到它在 4x4 陣列中的 row, col
void FindPosition(int minterm, int &row, int &col) {
    for (int r = 0; r < 4; r++) {
        for (int c = 0; c < 4; c++) {
            // 修正：必須使用雙中括號 kmapGrid[r][c]
            if (kmapGrid[r][c] == minterm) {
                row = r;
                col = c;
                return;
            }
        }
    }
}

// 根據群組內的 minterms 產生化簡後的字串項
string GenerateSimplifiedTerm(const vector<int>& coveredMinterms) {
    int size = coveredMinterms.size();
    if (size == 16) return "1";

    string aVals[4] = { "A'B'", "A'B", "AB", "AB'" };
    string cVals[4] = { "C'D'", "C'D", "CD", "CD'" };

    set<int> rowsCovered;
    set<int> colsCovered;

    for (int m : coveredMinterms) {
        int r, c;
        FindPosition(m, r, c);
        rowsCovered.insert(r);
        colsCovered.insert(c);
    }

    string result = "";
    if (rowsCovered.size() == 1) {
        result += aVals[*rowsCovered.begin()];
    }
    if (colsCovered.size() == 1) {
        result += cVals[*colsCovered.begin()];
    }

    return result;
}

// 建立群組
Group* BuildGroup(const bool kmap[4][4], int startR, int startC, int rows, int cols) {
    vector<int> coveredMinterms;
    for (int rOffset = 0; rOffset < rows; rOffset++) {
        for (int cOffset = 0; cOffset < cols; cOffset++) {
            int r = (startR + rOffset) % 4;
            int c = (startC + cOffset) % 4;
            
            if (!kmap[r][c]) return nullptr;
            coveredMinterms.push_back(kmapGrid[r][c]);
        }
    }

    string term = GenerateSimplifiedTerm(coveredMinterms);
    int actualSize = rows * cols;
    return new Group(actualSize, coveredMinterms, term);
}

// 尋找所有可能的質涵蓋項 (Prime Implicants)
vector<Group*> FindAllPrimeImplicants(const bool kmap[4][4]) {
    vector<Group*> primeImplicants;
    bool covered[4][4] = { false };

    int sizes[] = { 8, 4, 2, 1 };
    for (int size : sizes) {
        for (int r = 0; r < 4; r++) {
            for (int c = 0; c < 4; c++) {
                vector<Group*> validGroups;

                if (size == 8) {
                    for (int i = 0; i < 4; i++) validGroups.push_back(BuildGroup(kmap, i, 0, 2, 4));
                    for (int j = 0; j < 4; j++) validGroups.push_back(BuildGroup(kmap, 0, j, 4, 2));
                }
                else if (size == 4) {
                    for (int i = 0; i < 4; i++) validGroups.push_back(BuildGroup(kmap, i, 0, 1, 4));
                    for (int j = 0; j < 4; j++) validGroups.push_back(BuildGroup(kmap, 0, j, 4, 1));
                    for (int i = 0; i < 4; i++) {
                        for (int j = 0; j < 4; j++) validGroups.push_back(BuildGroup(kmap, i, j, 2, 2));
                    }
                }
                else if (size == 2) {
                    for (int i = 0; i < 4; i++) {
                        for (int j = 0; j < 4; j++) {
                            validGroups.push_back(BuildGroup(kmap, i, j, 1, 2));
                            validGroups.push_back(BuildGroup(kmap, i, j, 2, 1));
                        }
                    }
                }
                else if (size == 1) {
                    for (int i = 0; i < 4; i++) {
                        for (int j = 0; j < 4; j++) {
                            validGroups.push_back(BuildGroup(kmap, i, j, 1, 1));
                        }
                    }
                }

                for (auto group : validGroups) {
                    if (group != nullptr) {
                        bool isAlreadyCovered = false;
                        for (int m : group->coveredMinterms) {
                            int mr, mc;
                            FindPosition(m, mr, mc);
                            if (!covered[mr][mc]) {
                                isAlreadyCovered = true;
                                covered[mr][mc] = true;
                            }
                        }
                        if (isAlreadyCovered) {
                            primeImplicants.push_back(group);
                        } else {
                            delete group;
                        }
                    }
                }
            }
        }
    }
    return primeImplicants;
}

// 尋找必要質涵蓋項 (Essential Prime Implicants)
vector<Group*> FindEssentialPrimeImplicants(const vector<Group*>& allPIs, const vector<int>& minterms) {
    vector<Group*> epis;
    for (int minterm : minterms) {
        int coverageCount = 0;
        Group* coveringGroup = nullptr;
        for (auto pi : allPIs) {
            if (find(pi->coveredMinterms.begin(), pi->coveredMinterms.end(), minterm) != pi->coveredMinterms.end()) {
                coverageCount++;
                coveringGroup = pi;
            }
        }
        if (coverageCount == 1 && coveringGroup != nullptr) {
            if (find(epis.begin(), epis.end(), coveringGroup) == epis.end()) {
                epis.push_back(coveringGroup);
            }
        }
    }
    return epis;
}

int main() {
    cout << "--- 4-Variable Karnaugh Map (K-Map) Simplifier (C++) ---\n";
    cout << "Enter minterms (space-separated, 0-15): \n";

    string input;
    getline(cin, input);
    if (input.empty()) return 0;

    stringstream ss(input);
    vector<int> minterms;
    int val;
    while (ss >> val) {
        minterms.push_back(val);
    }

    if (minterms.empty()) return 0;

    if (minterms.size() == 16) {
        cout << "\nSimplified SOP Expression:\n1\n";
        return 0;
    }

    bool kmap[4][4] = { false };
    for (int m : minterms) {
        int r, c;
        FindPosition(m, r, c);
        kmap[r][c] = true;
    }

    vector<Group*> allPIs = FindAllPrimeImplicants(kmap);
    vector<Group*> epis = FindEssentialPrimeImplicants(allPIs, minterms);

    vector<int> uncoveredMinterms = minterms;
    for (auto epi : epis) {
        uncoveredMinterms.erase(
            remove_if(uncoveredMinterms.begin(), uncoveredMinterms.end(), [&](int m) {
                return find(epi->coveredMinterms.begin(), epi->coveredMinterms.end(), m) != epi->coveredMinterms.end();
            }),
            uncoveredMinterms.end()
        );
    }

    vector<Group*> finalGroups = epis;
    while (!uncoveredMinterms.empty()) {
        Group* bestGroup = nullptr;
        int maxCovered = -1;

        for (auto pi : allPIs) {
            if (find(finalGroups.begin(), finalGroups.end(), pi) != finalGroups.end()) continue;

            int count = 0;
            for (int m : uncoveredMinterms) {
                if (find(pi->coveredMinterms.begin(), pi->coveredMinterms.end(), m) != pi->coveredMinterms.end()) {
                    count++;
                }
            }

            if (count > maxCovered) {
                maxCovered = count;
                bestGroup = pi;
            }
        }

        if (bestGroup == nullptr) break;

        finalGroups.push_back(bestGroup);
        uncoveredMinterms.erase(
            remove_if(uncoveredMinterms.begin(), uncoveredMinterms.end(), [&](int m) {
                return find(bestGroup->coveredMinterms.begin(), bestGroup->coveredMinterms.end(), m) != bestGroup->coveredMinterms.end();
            }),
            uncoveredMinterms.end()
        );
    }

    cout << "\nSimplified SOP Expression:\n";
    for (size_t i = 0; i < finalGroups.size(); i++) {
        cout << finalGroups[i]->simplifiedTerm;
        if (i < finalGroups.size() - 1) {
            cout << "+";
        }
    }
    cout << endl;

    for (auto pi : allPIs) delete pi;

    return 0;
}