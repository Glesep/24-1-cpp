#include <iostream>
#include <vector>
using namespace std;

class A
{
public:
    int data;
    A() {
        cout << "constructor1 of A" << endl;
    }
    A(int a): data(a) {
        cout << "constructor2 of A" << endl;
    }
};
class B
{
public:
    vector<A> vec;
    A z;
    B() {
        cout << "constructor1 of B" << endl;
    }
    B(vector<A> v): vec(v) {
        cout << "constructor2 of B" << endl;
    }
};
int main() {
    A x(10);
    vector<A> vec_a;
    A arr[4];
    B y(vec_a);
    return 0;
}
