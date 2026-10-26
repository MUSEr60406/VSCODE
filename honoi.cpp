#include <iostream>
#include <windows.h>
using namespace std;
void hanoi(int n, char from, char aux, char to) {
    // 終止條件：當只剩 1 個盤子時，直接從起始柱移動到目標柱
    if (n == 1) {
        cout << "移動盤子 1 從 " << from << " 柱子到 " << to << " 柱子" << endl;
        return;
    }

    // 步驟 1：將上面 n-1 個盤子從 from 藉由 to 移動到 aux
    hanoi(n - 1, from, to, aux);

    // 步驟 2：將第 n 個盤子從 from 移動到 to
    cout << "移動盤子 " << n << " 從 " << from << " 柱子到 " << to << " 柱子" << endl;

    // 步驟 3：將 n-1 個盤子從 aux 藉由 from 移動到 to
    hanoi(n - 1, aux, from, to);
}
int main()
{
    int n;
    cout << "請輸入河內塔的盤子數量: ";
    cin >> n;

    // 假設三根柱子分別代號為 'A', 'B', 'C'
    // A 是起始柱，B 是輔助柱，C 是目標柱
    hanoi(n, 'A', 'B', 'C');

    return 0;
}