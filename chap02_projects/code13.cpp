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

    // 윈쪽 피연산자는 자기 자신, 오른쪽 피연산자는 매개변수로 받는다.
    bool operator<(Date &rhs) {
        return year < rhs.year ||
                (year == rhs.year && month < rhs.month) ||
                (year == rhs.year && month == rhs.month && day < rhs.day);
    }

    bool operator>(Date &rhs) {
        return year > rhs.year ||
                (year==rhs.year && month > rhs.month) ||
                (year == rhs.year && month == rhs.month && day > rhs.day);
    }

    bool operator==(Date &rhs) {
        return year == rhs.year && month == rhs.month && day == rhs.day;
    }

    // delegation -> == 에게 일을 대신 하게 시킴
    bool operator!=(Date &rhs) {
        return !(*this == rhs);     // 포인터 this는 항상 자기 자신을 가리킨다.
    }

    bool operator<=(Date &rhs) {
        return *this < rhs || *this == rhs;
    }

    bool operator>=(Date & rhs) {
        return *this > rhs || *this == rhs;
    }

    // 증감연산 (++, --)는 자신의 참조를 반환하여야 한다.
    // 전위 증가 연산자
    Date &operator++() {
        if (last_day_of_year()) {
            year++, month = 1, day = 1;
        }
        else if (last_day_of_month()) {
            month++, day = 1;
        }
        else {
            day++;
        }
       return *this;               // 값에 의한 리턴을 할 경우 복사본을 리턴하기 때문에 계산에 문제가 생길 수 있음
    }

    // 후위 증가 연산자 ((int)로 표시)
    Date operator++(int) {
        // 연산 수행 전의 값을 복사해 둔다.
        Date ret = *this;

        if (last_day_of_year()) {
            year++, month = 1, day = 1;
        }
        else if (last_day_of_month()) {
            month++, day = 1;
        }
        else {
            day++;
        }

        return ret;                 // 참조에 의한 리턴을 할 경우 함수 끝날 시 변수 ret이 삭제되므로 오류
    }

    int operator-(Date &rhs) {
        if (*this == rhs)
            return 0;

        else if (*this <rhs) {
            Date temp = *this;      // 객체의 내용이 변경되어서는 안되므로 복사본을 만들어서 작업한다.
            int diff = 0;
            while (temp < rhs) {
                temp++;
                diff++;
            }
            return -diff;
        }

        else {
            Date temp = rhs;        // 객체의 내용이 변경되어서는 안되므로 복사본을 만들어서 작업한다.
            int diff = 0;
            while (*this > temp) {
                temp++;
                diff++;
            }
            return diff;
        }
    }

    // 날짜에 k일을 더한 날짜를 반환
    Date operator+(int k) {
        Date temp = *this;

        for (int i = 0; i < k; i++)
            ++temp;
        return temp;
    }

    // d + 3과 3 + d 둘 다 가능하게 할려면...
    // Date operator+(Date &lhs, int k);
    // Date operator+(int k, Date &rhs);

    void print(ostream &out) {
        out << year << "/" << month << "/" << day; 
    }
};

void sort_dates(vector<Date> &dates) {
    for (int i = dates.size()-1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (dates.at(j) > dates.at(j+1))
                swap(dates.at(j), dates.at(j+1));
        }
    }
}

int main() {
    vector<Date> dates;
    ifstream infile("dates.txt");
    int y, m, d;
    while (infile >> y >> m >> d) {
        dates.push_back(Date(y,m,d));
    }
    infile.close();

    sort_dates(dates);

    for (Date &d: dates) {
        d.print(cout);
        cout << endl;
    }

    cin >> y >> m >> d;
    Date theDay(y, m, d);
    int min_diff = abs(dates[0] - theDay);
    Date closet_day = dates[0];
    for (Date &dt : dates) {
        int diff = abs(dt-theDay);
        if (diff < min_diff) {
            min_diff = diff;
            closet_day = dt;
        }
    }

    closet_day.print(cout);
    cout << " with difference " << min_diff << " days." << endl;

    return 0;
}

