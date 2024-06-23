#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// 데이터 클래스
class Term {
// Polynomial 클래스에서 이 클래스의 private 멤버들에 접근 가능
friend class Polynomial;

// 데이터 멤버를 private로 정의
private:
    int coef;
    int expo;
    // Polynomial 클래스 외엔 이 클래스의 생성자를 만들 수 없다.
    Term() = default;
    Term(int c, int e): coef(c), expo(e) {}

// 최대한 public 멤버를 줄이는 쪽으로 가는 것이 좋다.
public:
    // 다항식의 x에 값을 넣은 것
    int calc(int x) {
        return coef * pow(x, expo);
    }
    void print(ostream &out) {
        out << coef << "x^" << expo;
    }
};
// 데이터 클래스
class Polynomial {
// friend 함수 : 이 함수 내에서 Polynomial 클래스의 private 멤버 엑세스 가능
friend void print_poly(Polynomial p, ostream &out);

private: 
    char name;
    // Term 객체들의 포인터들을 저장하는 벡터
    vector<Term *> terms;

public:
    Polynomial() = default;
    Polynomial(char pname): name(pname) {}

    // 다항식의 이름 받기 (getter)
    char get_name() {
        return name;
    }
    // 다항식의 이름 설정 (setter)
    void set_name(char c) {
        name = c;
    }

    int calc(int x) {
        int result = 0;

        // t == Term의 포인터
        for (auto t : terms) 
            result += t->calc(x);

        return result;
    }

    void add_term(int coef, int expo) {
        auto it = terms.begin();
        while (it != terms.end() && (*it)->expo > expo)         // iterator가 가리키는 것은 포인터! (포인터 -> 포인터 -> 객체)
            it++;
        // 지수 부분이 같을 때
        if (it != terms.end() && (*it)->expo == expo) {
            (*it)->coef += coef;
            // 더한 뒤 계수가 0이라면
            if ((*it)->coef == 0)
                delete (*it);                                   // Garbage 값 주의! 동적 생성된 객체를 쓰지 않을 때 직접 삭제해야 함!!
                terms.erase(it);
        }
        else {
            // expo차 항이 없을 때 추가
            terms.insert(it, new Term(coef,expo));              // 동적 생성된 객체 추가 (포인터 추가)
        }
    }
};

void print_poly (Polynomial p, ostream &out) {
    cout << p.name << "=";
    for (auto t: p.terms) {
        t->print(out);
        out << " + ";
    }
}

// 실행 위한 클래스
class PolyCalculator {
private:
    vector<Polynomial> polys;

    // polys 내의 다항식 이름을 찾기
    vector<Polynomial>::iterator find(char name) {
        for (auto it = polys.begin(); it != polys.end(); it++) {
            if (it->get_name() == name)
                return it;
        }
        return polys.end();
    }

public:
    void create_or_update_poly(char name) {
        Polynomial p(name);
        auto it = find(name);
        // 이미 존재하는 다항식이라면 덮어쓰기
        if (it != polys.end()) 
            *it = p;
        // 없으면 추가하기
        else
            polys.push_back(p);
    }

    void add_term_to(char name, int coef, int expo) {
        auto it = find(name);
        if (it == polys.end())
            cout << "Undefined polynomial!" << endl;
        else
            it->add_term(coef, expo);               // 해당 다항식에 term 추가
    }

    void calc_poly(char name, int x) {
        auto it = find(name);
        if (it == polys.end())
            cout << "Undefined polynomial!" << endl;
        else
            cout << it->calc(x) << endl;            // 해당 다항식에 x값을 넣은 값 출력
    }

    void print_pol(ostream &out, char name) {
        auto it = find(name);
        if (it == polys.end())
            cout << "Undefined polynomial!" << endl;
        else {
            // endl 다는 용도
            print_poly(*it, out);
            out << endl;
        }
    }

    void copy_poly(char name, char new_name) {
        auto it = find(name);
        if (it == polys.end()) {
            cout << "Undefined polynomial!" << endl;
            return;
        }
        
        // 내용 복사 후 이름만 바꾸기
        Polynomial q = *it;
        q.set_name(new_name);
        it = find(new_name);
        if (it == polys.end())
            polys.push_back(q);
        // 새 이름을 정했는데 그게 이미 있다면 덮어쓰기
        else
            *it = q;
    }

    void delete_poly(char name) {
        auto it = find(name);
        if (it == polys.end()) {
            cout << "Undefined polynomial!" << endl;
            return;
        }
        polys.erase(it);
    }

    // 모든 다항함수 출력
    void list_polys(ostream &out) {
        for (auto p: polys) {
            // 다항함수 하나 출력
            print_poly(p, out);
            out << endl;
        }
    }
};

// driver : 전체 프로그램을 조율하는 함수
void process_command(PolyCalculator &calculator) {
    char name, new_name;
    int coef, expo, x;
    string command;
    
    while (true) {
        cout << "$";
        cin >> command;
        if (command == "print") {
            cin >> name;
            calculator.print_pol(cout, name);
        }
        else if (command == "calc") {
            cin >> name >> x;
            calculator.calc_poly(name, x);
        }
        else if (command == "create") {
            cin >> name;
            calculator.create_or_update_poly(name);
        }
        else if (command == "add") {
            cin >> name >> coef >> expo;
            calculator.add_term_to(name, coef, expo);
        }
        else if (command == "copy") {
            cin >> name >> new_name;
            calculator.copy_poly(name, new_name);
        }
        else if (command == "delete") {
            cin >> name;
            calculator.delete_poly(name);
        }
        else if (command == "list") {
            calculator.list_polys(cout);
        }
        else if (command == "exit")
            break;
    }
}

int main() {
    PolyCalculator calculator;
    process_command(calculator);
    return 0;
}