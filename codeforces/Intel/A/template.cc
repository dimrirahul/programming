#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;
using VI = vector<int>;
using LL = long long;
using PI = pair<int, int>;
using MI = map<int, int>;

const bool dbg = !true;

struct A {
    A() {
        months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    }

    int getMod(int x) {
        int res = x % 7;
        return (res >= 0) ? res : res + 7;
    }

    int getDay(string s) {
        if (s =="monday") return 0 ;
        if (s =="tuesday") return 1;
        if (s =="wednesday") return 2 ;
        if (s =="thursday") return 3;
        if (s =="friday") return 4;
        if (s =="saturday") return 5 ;
        return 6;
    }
    void start() {
        string s1; cin >> s1;
        int d1 = getDay(s1);
        cin >> s1;
        int d2 = getDay(s1);
        bool found = false;
        for (auto it : months) {
            if (dbg) cout << "d2=" << d2 << " d1=" << d1 << " exp=" << (it %7) << "\n";
            if (d2 != getMod(d1 + getMod(it))) continue;
            found = true;
            break;
        }
        cout << (found ? "YES" : "NO") << "\n";
    }

    VI months;


};

A a;
int main() {
    a.start();
    return 0;
}
