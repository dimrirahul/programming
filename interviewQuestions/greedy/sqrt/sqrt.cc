#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
class Num {
    public:
        int a, b;
        Num(int _a, int _b) {
            a = _a; b = _b;
        }

        double value() const {
            return (double)b * sqrt(2) + a;
        }

        bool operator<(Num other) const {
            return value() < other.value();
        }

        bool equals(Num other) const {
            return a == other.a && b == other.b;
        }

        void print() {
            cout << a << "+" << b << "sqrt(2) " << value() << "\n";
        }
};
int main(int argc, char **argv) {
    int k;
    cin >> k;
    vector< Num > res;
    res.push_back(Num(0, 0));
    int aIdx = 0, bIdx = 0;
    for (int i = 1; i < k; i++) {
        Num n1(res[aIdx].a + 1, res[aIdx].b);
        Num n2(res[bIdx].a, res[bIdx].b + 1);
        cout << "==\n";
        n1.print();
        n2.print();
        if ( n1.equals(n2)) {
            cout << "Cond3\n";
            bIdx++;
            aIdx++;
            res.push_back(n1);
        } else if (n1 < n2) {
            cout << "Cond1\n";
            aIdx++;
            res.push_back(n1);
        } else {
            cout << "Cond2\n";
            bIdx++;
            res.push_back(n2);
        }
    }
    for (int i = 0; i < res.size(); i++) res[i].print();
    return 0;
}

