#include <iostream>

using namespace std;

// n: ��文����賊��
// from: 韏瑕�����
// aux: 頛���拇��
// to: ��格�����
void hanoi(int n, char from, char aux, char to) {
    // 蝯�甇Ｘ��隞塚����嗅�芸�� 1 �����文�����嚗���湔�亙��韏瑕����梁宏�����啁�格�����
    if (n == 1) {
        cout << "蝘餃����文�� 1 敺� " << from << " ��勗����� " << to << " ��勗��" << endl;
        return;
    }

    // 甇仿�� 1嚗�撠�銝���� n-1 �����文��敺� from ������ to 蝘餃����� aux
    hanoi(n - 1, from, to, aux);

    // 甇仿�� 2嚗�撠�蝚� n �����文��敺� from 蝘餃����� to
    cout << "蝘餃����文�� " << n << " 敺� " << from << " ��勗����� " << to << " ��勗��" << endl;

    // 甇仿�� 3嚗�撠� n-1 �����文��敺� aux ������ from 蝘餃����� to
    hanoi(n - 1, aux, from, to);
}

int main() {
    int n;
    cout << "隢�頛詨�交眾��批�������文����賊��: ";
    cin >> n;

    // ���閮凋����寞�勗�������乩誨������ 'A', 'B', 'C'
    // A ��航絲憪���梧��B ��航����拇�梧��C ��舐�格�����
    hanoi(n, 'A', 'B', 'C');

    return 0;
}