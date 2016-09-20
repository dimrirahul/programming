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


struct A {

    bool checkAndSet(const string& s, int pos, string& out) {
        out = s;
        if (s[pos] == s[pos+1] && s[pos+1] == 'O') {
            out[pos] = out[pos+1] = '+';
            return true;
        }
        return false;
    }

    bool hasAdjSeats(const string& s, string& out) {
        return checkAndSet(s, 0, out) || checkAndSet(s, 3, out);
    }

    void start() {
        int n;
        vector<string> res;
        bool success = false;
        cin >> n;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            string modSeats;
            if (!success && hasAdjSeats(s, modSeats)) {
                success = true;
                res.push_back(modSeats);
            } else {
                res.push_back(s);
            }
        }

        if (success) {
            cout << "YES\n";
            for (auto it : res) cout << it << "\n";
        } else {
            cout << "NO\n";
        }
    }
};

A a;
int main() {
    a.start();
    return 0;
}
