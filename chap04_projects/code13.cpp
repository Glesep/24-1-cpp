#include <iostream>
using namespace std;

// class template
template<typename T>
class MyArray {
private:
    T* ptr;             // T 타입의 배열
    int size;

public:
    MyArray(T arr[], int s) {
        ptr = new T[s];
        size = s;
        for (int i = 0; i < size; i++)
            ptr[i] = arr[i];
    }

    void print() {
        for (int i = 0; i < size; i++)
            cout << " " << *(ptr + i);      // 주소로 arr 접근방법
        cout << endl;
    }
};

int main() {
    int arr[5] = { 1, 2, 3, 4, 5 };
    MyArray<int> a(arr, 5);
    a.print();

    return 0;
}