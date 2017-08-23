#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

#define FORN(I, N) for (int (I) = 0; (I) < (N); (I)++)
#define ALL(X) (X).begin(), (X).end()

const int INF = ((int)1e9) + 30;
const bool dbg = true;

struct D {


    int getOptimalKeyPos(int personPos) {
        if (dbg) cout << "PersonPos=" << personPos + officePos << "\n";
        auto left = keyPosSet.lower_bound(personPos);
        int dLeft;
        if (left == keyPosSet.begin()) {
            if (*left == personPos) dLeft = 0;
            else dLeft = INF;
        } else {
            if (*left == personPos) dLeft = 0;
            else {
                left--;
                dLeft = abs(*left - personPos);
            }
        }
        auto right = keyPosSet.upper_bound(personPos);
        int dRight = right == keyPosSet.end() ? INF: abs(*right - personPos);

        if (dbg) {
            cout << "Left distance=" << dLeft << "\n";
            cout << "Right distance=" << dRight << "\n";
        }

        if (dLeft <= dRight) {
            return *left;
        } else {
            return *right;
        }
    }

    void start() {
        int res = 0;
        int numPersons, numKeys;
        cin >> numPersons >> numKeys >> officePos;
        FORN(i, numPersons) { int t; cin >> t; personPosVector.push_back(t - officePos);}
        FORN(i, numKeys) { int t; cin >> t; keyPosSet.insert(t - officePos);}

        auto cmpF = [](int a, int b)->bool {
            return abs(a) > abs(b);
        };
        sort(ALL(personPosVector), cmpF);

        for (auto it : personPosVector) {
            int k =  getOptimalKeyPos(it);
            if (dbg) cout << "Chosen key=" << k << " K actual= " << k + officePos << "\n";
            int t = abs(it - k) + abs(k);
            res = max(res, t);
            keyPosSet.erase(k);
        }
        cout << res << "\n";

    }

    vector<int> personPosVector;
    set<int> keyPosSet;
    int officePos;
};

D d;
int main() {
    ios_base::sync_with_stdio(false);
    d.start();
    return 0;
}
