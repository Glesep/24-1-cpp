#include <iostream>
#include <vector>
using namespace std;

void compute_set(vector<int> &A, vector<int> &B) {
    for (int i = 0; i < B.size(); i++) {
        auto iterA = A.begin();
        // 삽입 또는 삭제가 되었는가?
        bool isInsertOrErase = false;
        for (int j = 0; j < A.size(); j++) {
            if (*iterA == B[i]) {
                // 같은 때 지우기
                A.erase(iterA);
                isInsertOrErase = true;
                break;
            }

            if (*iterA > B[i]) {
                A.insert(iterA, B[i]);
                isInsertOrErase = true;
                break;
            }
            iterA++;
        }
        // 삽입이 안된 경우(맨 뒤에 와야됐을 경우)
        if (!isInsertOrErase) {
            A.push_back(B[i]);
        }
    }
}

// void compute_set(vector<int> &A, vector<int> &B) {
//     auto it1 = A.begin(), it2 = B.begin();
//     while (it1 != A.end() && it2 != B.end()) {
//         if (*it1 < *it2)
//             it1++;
//         else if (*it1 > *it2) {
//             it1 = A.insert(it1, *it2);
//             it2++;
//         }
//         else {
//             it1 = A.erase(it1);
//             it2++;
//         }
//     }
//     while (it2 != B.end()) {
//         A.insert(A.end(), *it2);
//         it2++;
//     }
// }

int main() {
    int m, n, k;
    vector<int> first, second;
    cin >> m;
    // m개의 정수가 오름차순으로 정렬되어 입력된다.
    for (int i = 0; i < m; i++) {
        cin >> k;
        first.push_back(k);
    }
    cin >> n;
    // n개의 정수가 오름차순으로 정렬되어 입력된다.
    for (int i=0; i<n; i++) {
        cin >> k;
        second.push_back(k);
    }

    compute_set(first, second);

    for (auto item: first)
        cout << item << " ";
    cout << endl;
    return 0;
}