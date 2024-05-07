#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

class Date {
private: 
    int year, month, day;
    vector<int> short_months {4, 6, 9, 11};     // 30일까지 있는 달
    bool is_short_month() {
        return find(short_months.begin(), short_months.end(), month) != short_months.end();
    }

    bool last_day_of_month() {
        return month == 2 && day == 28 || is_short_month() && day == 30 || day == 31;
    }

    bool last_day_of_year() {
        return month == 12 && day == 31;
    }

public:
    Date() = default;
    Date(int y, int m, int d): year(y), month(m), day(d) {}

    bool operator<(Date &rhs) {
        return year < rhs.year ||
                (year == rhs.year && month < rhs.month) ||
                (year == rhs.year && month == rhs.month && day < rhs.day);
    }

    bool operator>(Date &rhs) {
        ret
    }
};

