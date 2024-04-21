#include <iostream>
#include <vector>
using namespace std;

class Interval {
public:
    int x;
    int y;

 Interval() = default;
 Interval(int a, int b) : x(a), y(b) {};
};

int calc_overlap (Interval p, Interval q) {
    if (p.y <= q.x || p.x >= q.y)
        return 0;
    else
        return min(p.y, q.y) - max(p.x, q.x);
}
int main() {
    int N;
    cin >> N;
    int x, y;
    vector <Interval> intervals;
    for (int i = 0 ; i < N; i++) {
        cin >> x >> y;
     Interval tmp(x, y);
        intervals.push_back(tmp); 
    }

    int max_length = 0;
    Interval result1, result2;
    for (int i = 0; i < (int)intervals.size()-1; i++){
        for (int j = i+1; j < (int)intervals.size(); j++) {
            if (max_length < calc_overlap(intervals[i], intervals[j])) {
                max_length = calc_overlap(intervals[i], intervals[j]);
                result1 = intervals[i];
                result2 = intervals[j];
            }  
        }
    }

    cout << "[" << result1.x << ", " << result1.y << "]" << endl;
    cout << "[" << result2.x << ", " << result2.y << "]" << endl;
}