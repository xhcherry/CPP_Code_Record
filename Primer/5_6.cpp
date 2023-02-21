#include <iostream>
#include <vector>
#include <string>
//改写5.5，使用条件运算符代替if else语句
using namespace std;

int main() {
    vector<string> scores = {"F", "D", "C", "B", "A", "A++"};
    int grade{0};
    while (cin >> grade) {
        string lettergrade = grade < 60 ? scores[0] : scores[(grade - 50) / 10];
        lettergrade += (grade == 100 || grade < 60) ? "" : (grade % 10 > 7) ? "+" : (grade % 10 < 3) ? "-" : "";
        cout << lettergrade << endl;
    }
    return 0;
}