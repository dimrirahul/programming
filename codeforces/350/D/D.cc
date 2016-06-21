#include <iostream>
#include <vector>


using namespace std;
using VI = vector<int>;
const bool dbg = !true;

struct D {
    int n, k, maxCookies;;
    VI a, b;
    bool canMake(int cks) {
        int rem = k;
        for (int i = 0; i < b.size(); i++) {
            int diff = b[i] - a[i] * cks;
            if (diff >= 0) continue;
            rem -= abs(diff);
            if (rem < 0) return false;
        }
        return true;
    }

    void start() {
        cin >> n >> k;
        maxCookies = 0;
        for (int i = 0; i < n; i++) {
            int t; cin >> t;
            a.push_back(t);
        }
        for (int i = 0; i < n; i++) {
            int t; cin >> t;
            b.push_back(t);
            maxCookies = max(maxCookies, (t + k) / a[i]);
        }
        if (dbg) cout << "maxCookies=" << maxCookies << "\n";
        int start = 0, end = maxCookies + 1, res;
        while (start < end) {
            int mid = (start + end) / 2;
            if (dbg) cout << "Start=" << start << " end=" << end << " res=" << res << " mid=" << mid << "\n";
            if (canMake(mid)) {
                if (dbg) cout << "can make = " << mid << " cookies\n";
                start = mid + 1;
                res = mid;
            } else {
               end = mid;
            }
        }
        cout << res << "\n";
    }

};

D d;
int main(int argc, char **argv) {
    d.start();
    return 0;
};
