#include <iostream>

using namespace std;

// 河內塔遞迴函數
void hanoi(int n, char from, char aux, char to) {
    if (n == 1) {
        cout << "移動盤子 1 從 " << from << " 柱子到 " << to << " 柱子" << endl;
        return;
    }
    hanoi(n - 1, from, to, aux);
    cout << "移動盤子 " << n << " 從 " << from << " 柱子到 " << to << " 柱子" << endl;
    hanoi(n - 1, aux, from, to);
}

int main() {
    int n;
    cout << "請輸入河內塔的盤子數量: ";
    cin >> n; // 讀取你輸入的數字

    // 2. 執行河內塔計算並印出過程
    hanoi(n, 'A', 'B', 'C');


    return 0;
}