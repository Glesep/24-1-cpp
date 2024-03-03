// '/' ������ �� �� ���������� Ÿ���� ��������!!

#include <iostream>
#include <cmath> //���� �Լ�

using namespace std;

// const: ��� == ���� ������, �ڵ�󿡼� ���� �Ұ���
const int MIN = 0;
const int MAX = 360;
const int STEP = 10;

int main()
{
    double radian, pi, value;
    pi = 4.0 * atan(1.0); // tan(pi/4) = 1.0, atan ���� double ����

    cout << "Angle : SIN" << endl;

    for (int degree = MIN; degree <= MAX; degree += STEP)
    {
        radian = pi * ((double)degree / 180); // �������� '/' ������ �ϸ� ���� ��ȯ
        value = sin(radian);
        cout << degree << " : " << value << endl;
    }

    return 0;
}