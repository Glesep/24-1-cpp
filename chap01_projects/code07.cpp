// if, else if, else�� ��� �����ϴ��� ����� ����!

#include <iostream>
using namespace std;

int main()
{
    int s, t;
    cin >> s >> t; // s, t�� �ٷ� �Է��� �ǹǷ� �ʱ�ȭ�� ��

    // �Ʒ��� �� ������ �Է��� ���� �����Ƿ� ��ü������ �ʱ�ȭ�� ������� ��
    int cnt_2 = 0;
    int cnt_3 = 0;
    int cnt_else = 0;

    if (s <= t)
    {
        for (int i = s + 1; i < t; i++)
        {
            if (i % 2 == 0)
                cnt_2++;
            if (i % 3 == 0) // ����! ** else if�� ������� ���� ���� if���� ���ܵ� �����̹Ƿ� 6�� ��� ����� ���� ���ܵ� ü�� ���´� **
                cnt_3++;
            if (i % 2 != 0 && i % 3 != 0)
                cnt_else++;
        }

        cout << "2�� ����� ����: " << cnt_2 << endl;
        cout << "3�� ����� ����: " << cnt_3 << endl;
        cout << "������ ����: " << cnt_else << endl;
    }

    else
    {
        for (int i = t + 1; i < s; i++)
        {
            if (i % 2 == 0)
                cnt_2++;
            if (i % 3 == 0) // ����! ** else if�� ������� ���� ���� if���� ���ܵ� �����̹Ƿ� 6�� ��� ����� ���� ���ܵ� ü�� ���´� **
                cnt_3++;
            if (i % 2 != 0 && i % 3 != 0)
                cnt_else++;
        }

        cout << "2�� ����� ����: " << cnt_2 << endl;
        cout << "3�� ����� ����: " << cnt_3 << endl;
        cout << "������ ����: " << cnt_else << endl;
    }

    return 0;
}