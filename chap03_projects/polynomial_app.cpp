// // 다 완성해보기
// #include <iostream>
// #include <vector>
// using namespace std;

// class Polynomial {
// private:
//     char name;
//     vector<Term *> terms;
//     void clearMembers() {
//         for (auto p: terms)
//             delete p;
//         // 길이를 0으로
//         terms.clear();
//     }
// public:
//     Polynomial() = default;
//     Polynomial(char pname): name(pname) {}

//     Polynomial(const Polynomial &p): name(p.name) {
//         for (auto &pt: p.terms)
//             terms.push_back(new Term(*pt));
//     }
//     Polynomial &operator=(const Polynomial &p) {
//         clearMembers();
//         name = p.name;
//         for (auto &pt: p.terms)
//             terms.push_back(new Term(*pt));
        
//         return *this;
//     }
//     ~Polynomial() {
//         clearMembers();
//     }
// };
// int main()
// {
    
    
//     return 0;
// }
