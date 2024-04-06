#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cctype>
using namespace std;

class SalesData {
public:
    string isbn;
    int units_sold = 0;
    double revenue = 0.0;
};

SalesData parse_line(string &line);
void insertRecord(SalesData &record, vector<SalesData> &records);
vector<string> split_line(string line, char delimiter);
void sort_by_average_price(vector<SalesData> &records);
int main() {
    vector <SalesData> records;
    ifstream infile("sales_records.csv");
    string line;

    while(getline(infile, line)) {
        if (line.length() <= 0)
            continue;
        SalesData record = parse_line(line);
        insertRecord(record, records);
    }
    infile.close();

    sort_by_average_price(records);
    for (auto record : records) {
        cout << record.isbn << ":" << record.units_sold << ":" << record.revenue << ":" << record.revenue / record.units_sold << endl;
    }

    return 0;
}

SalesData parse_line(string &line) {
    SalesData record;
    vector<string> tokens = split_line(line, ',');
    record.isbn = tokens[0];
    record.units_sold = stoi(tokens[1]);
    record.revenue = stod(tokens[2]);

    return record;
}

void insertRecord(SalesData &record, vector<SalesData> &records) {
    for (auto it = records.begin(); it != records.end(); it++) {
        if (it->isbn == record.isbn) {                                  // (*it) == it->
            it->units_sold += record.units_sold;
            it->revenue += record.revenue;
            return;                                                     // 아무것도 되돌려주지 않겠다.
        }
    }
    records.push_back(record);
    // int i = 0;
    // for (; i < records.size();) {
    //     if (record.isbn == records[i].isbn) {
    //         records[i].units_sold += record.units_sold;
    //         records[i].revenue += record.revenue;
    //         break;
    //     }
    //     i++;
    // }
    // if (i == records.size()) {
    //     records.push_back(record);
    // }
}

void sort_by_average_price(vector<SalesData> &records) {   
    // Bubble Sort
    for (int i = records.size()-1; i > 0; i--) {
        
        for (int j = 0; j < i; j++) {
            double averagePrice1 = records[j].revenue / records[j].units_sold;
            double averagePrice2 = records[j+1].revenue / records[j+1].units_sold;
            // 내림차순: 값이 큰 것 -> 값이 작은 것
            if (averagePrice1 < averagePrice2) {
                // <algorithm> 의 swap 함수 사용해도 됨 
                SalesData tmp = records[j];
                records[j] = records[j+1];
                records[j+1] = tmp;
            }
        }
    }
}

vector<string> split_line(string line, char delimiter) {
    
    vector<string> tokens;
    // 문자열 line을 하나의 stream 객체로 만들기 >> sstream으로부터 문자열 읽어오기
    stringstream sstream(line);
    string str;

    while (getline(sstream, str, delimiter))        // 구분자 기준으로 잘라 읽기
        tokens.push_back(str);
    
    return tokens;
}