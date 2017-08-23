#include <iostream>
#include <vector>

using namespace std;

enum Trend {
    INC, EQ, DEC
};

int main() {
    vector<Trend> vi;
    int n; cin >> n;
    int prev;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        if (i != 0) {
            auto f = [t, prev]()->Trend {
                if (t > prev ) return INC;
                if (t == prev ) return EQ;
                return DEC;
            };
            auto res = f();
            if (vi.empty() || *vi.rbegin() != res)  vi.push_back(f());
        }
        prev = t;
    }
    bool good = false;
    if (vi.empty()) {
        good = true;
    } else if ( vi.size() > 3) {
        good = false;
    } else if ( vi.size() == 1 ) {
        good = true;
    } else if (vi.size() == 2) {
        good = !( vi[0] == DEC ||
                (vi[0] == EQ && vi[1] == INC));
    } else {
        good = (vi[0] == INC && vi[1] == EQ && vi[2] == DEC);
    }
    cout << (good ? "YES" : "NO") << "\n";

}

