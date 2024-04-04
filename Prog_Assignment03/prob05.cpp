#include <iostream>
#include <vector>
using namespace std;

void makeSegment(vector<vector<int>> &segmentHr, vector<vector<int>> &segmentVt, int N);
vector<vector<int>> intersect(vector<vector<int>> segmentHr, vector<vector<int>> segmentVt);
void sortSegments(vector<vector<int>> &intersectCoordinate);

// vector of vector<int> 사용해 수직, 수평 선분 표현
// 1, 3: x좌표 / 2, 4: y좌표
int main() {
    int N;                                                              // 선분 개수
    cin >> N;
    vector<vector<int>> segmentHr, segmentVt;                           // 수평 선분, 수직 선분
    // makeSegment 함수 접근 위한 빈 벡터 생성
    segmentHr.push_back(vector<int>()); 
    segmentVt.push_back(vector<int>()); 

    // 선분 만들기 
    makeSegment(segmentHr, segmentVt, N);    
    // 교점 찾기
    // 교점을 찾을 수 있는 경우 
    try {
        vector<vector<int>> intersectCoordinate = intersect(segmentHr, segmentVt);
        sortSegments(intersectCoordinate);
    
        for (int i = 0; i < intersectCoordinate.size(); i++) {
            cout << "[";
            for (int j = 0; j < 2; j++) {
                if (j != 1) {
                    cout << intersectCoordinate[i][j] << ", "; 
                }
                else
                    cout << intersectCoordinate[i][j];
            }
            cout << "]" << endl;
        }
    }
    // 교점을 찾을 수 없는 경우
    catch (out_of_range e) {
        cout << "There are only horizontal or vertical segments." << endl;
    }
    return 0;
}
// ============================================================= 함수 정의 ==================================================================================
// 선분 만들기
void makeSegment(vector<vector<int>> &segmentHr, vector<vector<int>> &segmentVt, int N) {
    int hrIndex = 0, vtIndex = 0;
    segmentHr.erase(segmentHr.begin());
    segmentVt.erase(segmentVt.begin());

     for (int i = 0; i < N; i++) {  
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        // 인덱스: x1 -> 0, y1 -> 1, x2 -> 2, y2 -> 3
        // 수평 선분
        if (y1 == y2) {
            segmentHr.push_back(vector<int>());

            segmentHr[hrIndex].push_back(x1);
            segmentHr[hrIndex].push_back(y1);
            segmentHr[hrIndex].push_back(x2);
            segmentHr[hrIndex].push_back(y2);
            
            hrIndex++;
        }
        // 수직 선분 
        else if (x1 == x2) {
            // 첫 번째 차원에 빈 벡터 추가
            segmentVt.push_back(vector<int>());

            segmentVt[vtIndex].push_back(x1);
            segmentVt[vtIndex].push_back(y1);
            segmentVt[vtIndex].push_back(x2);
            segmentVt[vtIndex].push_back(y2);
            vtIndex++;
        } 
    }    
}

// 교차 검사 함수 intersect
vector<vector<int>> intersect(vector<vector<int>> segmentHr, vector<vector<int>> segmentVt) {
    vector<vector<int>> intersectCoordinate;
    int intersectIndex = 0;
    for (int i = 0; i < segmentHr.size(); i++) {
        for (int j = 0; j < segmentVt.size(); j++) {
            // (수직 선분 x값이 수평 선분 x값의 범위에 들어와야 함 && 수평 선분 y값이 수직 선분 y값의 범위에 들어옴) -> 교점 생성
            if ((segmentHr.at(i).at(0) <= segmentVt.at(j).at(0) && segmentHr.at(i).at(2)>= segmentVt.at(j).at(0)) && (segmentVt.at(j).at(1) <= segmentHr.at(i).at(1) && segmentVt.at(j).at(3)>= segmentHr.at(i).at(1))) {
                intersectCoordinate.push_back(vector<int>());
                intersectCoordinate[intersectIndex].push_back(segmentVt[j][0]);
                intersectCoordinate[intersectIndex].push_back(segmentHr[i][1]);
                intersectIndex++;
            }
        }
    }
    return intersectCoordinate;
}

// Bubble Sort Algorithm
void sortSegments(vector<vector<int>> &intersectCoordinate) {
    for (int i = intersectCoordinate.size()-1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (intersectCoordinate[j][0] > intersectCoordinate[j+1][0]) {
                // intersectCoordinate 인덱스 바꾸기
                vector<int> tmp1 = intersectCoordinate[j];
                intersectCoordinate[j] = intersectCoordinate[j+1];
                intersectCoordinate[j+1] = tmp1;   
            }
            else if (intersectCoordinate[j][0] == intersectCoordinate[j+1][0]) {
                if (intersectCoordinate[j][1] > intersectCoordinate[j+1][1]) {
                    vector<int> tmp1 = intersectCoordinate[j];
                    intersectCoordinate[j] = intersectCoordinate[j+1];
                    intersectCoordinate[j+1] = tmp1; 
                }
            }
        }
    }
}
