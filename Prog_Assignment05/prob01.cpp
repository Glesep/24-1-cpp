#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class OrderedVecInt {
private:
    int capacity = 0;               // 동적 배열의 길이
    int saveSize = 0;               // 저장된 정수의 개수
    int *arr = nullptr;

public:
    void insertionSort(int k);
    void insert(int k);
    int &operator[](int index);
    int size();
    bool remove_by_val(int remove_val);
    bool remove_by_index(int remove_index);
   
};

int main() {
    srand((unsigned int) time(NULL)); // pseudo-random number generator
    int n, k;
    OrderedVecInt vec;
    cin >> n;

    for (int i=0; i<n; i++) {
        int k = rand() % 1000;
        vec.insert(k); // 정수 k를 삽입한다. 정수들은 정렬되어 저장되어야 한다.
    }

    for (int i=0; i<vec.size(); i++)
        cout << vec[i] << " "; // indexing연산자 []를 제공한다.
    cout << endl;
    
    // 오류!
    if (vec.remove_by_val(vec[2])) // 매개변수로 주어진 정수를 찾아 삭제한다.
        cout << "Remove done" << endl; // 그런 값이 존재하면 true, 
    else // 아니면 false를 반환한다.
        cout << "Remove failed"<< endl;

    if (vec.remove_by_index(4)) // 매개변수로 주어진 인덱스 위치의 정수를 삭제한다.
        cout << "RemoveIndex done" << endl; // 유효한 인덱스이면 true, 
    else // 아니면 false를 반환한다.
        cout << "RemoveIndex failed" << endl;
  
    for (int i = 0; i < vec.size(); i++) // size()는 저장된 정수의 개수를 반환한다. 
        vec[i] -= 10; // 저장된 정수를 수정할 수 있다. 이 경우 정렬이 흐트러질 수 있다.
    
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << endl;

    return 0;
}


// ======================================================== 함수 정의 =======================================================================

    // 한 번밖에 안 이루어짐
    void OrderedVecInt::insertionSort(int k) {
            int j = saveSize-1;
            // 삽입정렬은 항상 앞으로 들어간다.
            while (j >= 0 && arr[j] > k) {
                arr[j+1] = arr[j];
                j--;
            }

            arr[j+1] = k;
        
    }

    // 배열 삽입 함수: 첫 번째 원소가 삽입될 때 길이(capacity)를 1로 만들고, 그 다음부터는 필요 시 길이를 2배로 늘린다.
    // 배열 크기 수정시 새로 동적할당하기, 이미 있던 배열은 delete 꼭 해주기
    void OrderedVecInt::insert(int k) {
        if (saveSize == 0) {
            capacity = 1;                           // 동적 배열의 길이를 1로 설정
            arr = new int [capacity];               // arr 포인터에 이름 없는 int 타입 배열을 동적 할당
            arr[0] = k;                             // 정수를 배열에 저장
            saveSize++;                             // 저장된 정수 개수 refresh
        }
        else {
            // 동적 배열의 길이보다 저장된 정수의 개수가 더 많아진다면 길이를 2배로 늘리기
            if (saveSize+1 > capacity) {
                capacity *= 2;
                // 임시 배열 동적할당
                int *tmp = new int [capacity];

                for (int i = 0; i < saveSize; i++) 
                    tmp[i] = arr[i];
                
                delete[] arr;                           // arr 포인터가 가리키는 주소에 있는 배열 메모리 해제, arr 포인터 변수 자체는 남아있음
                
                arr = tmp;                              // 새로 만든 tmp 포인터 변수가 가리키는 주소를 arr에 대입
            }
                
            // 삽입 정렬
            insertionSort(k);
            saveSize++; 
        }
    }

    // []연산자 오버로딩하면 객체를 배열처럼 사용 가능, 따로 복합대입연산자 오버로딩 안해도 됨
    // []연산자를 오버로딩할 때는 참조에 의한 리턴을 사용해야 함 (요소를 수정할 때)
    int &OrderedVecInt::operator[](int index) {
        return arr[index];                      // 값에 의한 리턴이라면 요소를 수정하지 못함
    }

    int OrderedVecInt::size() {
        return saveSize;
    }

    bool OrderedVecInt::remove_by_val(int remove_val) {
        for (int i = 0; i < saveSize; i++) {
            // 값을 찾았으면 삭제 (바로 뒤 인덱스를 앞의 인덱스로 덮어쓰는 방식으로)
            if (arr[i] == remove_val) {
                // 맨 뒤의 값을 지울 때
                if (i == saveSize-1) {
                    saveSize--;
                    return true;
                }

                int j = i;
                // 한칸 앞의 인덱스로 값 밀어주기
                while (j < saveSize-1) {
                    arr[j] = arr[j+1];
                    j++;
                }
                
                // saveSize
                saveSize--;
    
                return true;
            }
        }

        return false;
    }

    bool OrderedVecInt::remove_by_index(int remove_index) {
        if (remove_index >= saveSize)
            return false;
        
        int j = remove_index;
        while (j < saveSize-1) {
            arr[j] = arr[j+1];
            j++;
        }
        // saveSize
        saveSize--;

        return true;
    }



