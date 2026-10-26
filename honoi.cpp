#include <iostream>
#include <windows.h> // 需要引入這個標頭檔來支援編碼轉換與暫停

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
    // 1. 強制將終端機編碼設為 UTF-8，解決中文亂碼
    system("chcp 65001 > nul");

    int n;
    cout << "請輸入河內塔的盤子數量: ";
    cin >> n; // 讀取你輸入的數字

    // 2. 執行河內塔計算並印出過程
    hanoi(n, 'A', 'B', 'C');

    // 3. 讓程式暫停，顯示「請按任意鍵繼續...」，避免跑完立刻關閉
    system("pause");

    return 0;
}