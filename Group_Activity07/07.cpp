class A {
 float d;
public:
 int a;
 void change(int i) {
 a = i;
 }
 void value_a() {
 cout << a << endl;
 }
};
class B: public A {
 int a = 15;
public:
 void print() {
 cout << a << endl;
 }
};
int main() {
 B b;
 b.change(10);
 b.print();
 b.value_a();
 return 0;
}
// 클래스에 속한 함수는 같은 클래스의 변수를 들고온다