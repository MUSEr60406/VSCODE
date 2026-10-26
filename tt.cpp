#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 摰�蝢拚�����蝯�瑽�嚗�瘥�韏瑚��蝬剝����������唳�乩葡���嚗�蝺���扯粥閮芣�湔��������
struct Edge {
    int u, v;
    long long w;
};

int main() {
    // ��芸��頛詨�亥撓��粹��摨�
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<Edge> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    // dis ���������憪���� 0嚗�蝑������潔�����頞�蝝�皞�暺������交�����蝭�暺�嚗���賢��蝢�������������������
    vector<long long> dis(n + 1, 0);
    vector<int> parent(n + 1, -1);
    int x = -1;

    // Bellman-Ford 瞍�蝞�瘜�
    // 蝮賢�勗�瑁�� n 甈～����� n-1 甈∠�箸迤撣賊��撘�嚗�蝚� n 甈∠�其��瑼Ｘ葫鞎����
    for (int i = 0; i < n; ++i) {
        x = -1;
        for (const auto& e : edges) {
            if (dis[e.u] + e.w < dis[e.v]) {
                dis[e.v] = dis[e.u] + e.w;
                parent[e.v] = e.u;
                x = e.v; // 閮�������敺�銝�甈∟◤��湔�啁��蝭�暺�
            }
        }
    }

    // 憒����蝚� n 甈⊥�������潛��隞颱����湔�堆��隞�銵冽�����鞎����
    if (x == -1) {
        cout << "NO\n";
    } else {
        // x 銝�銝�摰���刻����唬��嚗���航�賢�芣�臬����啗����啣蔣��踴��
        // 瘝輯�� parent 敺����韏� n 甈∴��蝣箔�����蝯����������蝭�暺�蝯�撠���刻����啣�扼��
        for (int i = 0; i < n; ++i) {
            x = parent[x];
        }

        vector<int> cycle;
        // ���憪���園��鞎���啁��暺�
        for (int v = x;; v = parent[v]) {
            cycle.push_back(v);
            if (v == x && cycle.size() > 1) {
                break;
            }
        }

        // �����箸�臬�����餈賣滲嚗����摨���臬�����嚗����閬����頧�
        reverse(cycle.begin(), cycle.end());

        cout << "YES\n";
        for (int v : cycle) {
            cout << v << " ";
        }
        cout << "\n";
    }

    return 0;
}