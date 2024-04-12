#include <iostream>
#include <vector>
using namespace std;

class CheckOrthogonalpolygon {
public:
    vector<vector<int>> points;
    
    bool checkPoints() {
        // 이웃하는 점끼리 이었을 때 수직 선분인지 수평 선분인지 판단하는 함수 
        // 하나라도 수직 선분이나 수평 선분이 아니라면 false 반환
    }
};

int main() {
    
    int N;
    cin >> N;
    CheckOrthogonalpolygon COP;

    // N개의 점의 좌표를 받기
    int x, y;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        vector<int> tmp = {x, y};
        COP.points.push_back(tmp);
    }

    // 직교 다각형 검사
    if (COP.checkPoints()) 
        cout << "This is orthogonal polygon." << endl;
    
    else
        cout << "This is not orthogonal polygon." << endl;

    return 0;
}