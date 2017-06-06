#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using VI = vector<int>;
using LL = long long;
using VL = vector<LL>;

#define ALL(X) (X).begin(), (X).end()

struct C {
    int numInput;
    VI inp;
    VI deltaPrevElement;
    VL kadeneMax;
    VL kadeneMin;

    void start() {
        cin >> numInput;
        for (int i = 0; i < numInput; i++) {
            int t;
            cin >> t;
            inp.push_back(t);
            if (i != 0) {
                int d = abs(t - inp[i-1]);
                if (i %2 != 0) d *= -1;
                deltaPrevElement.push_back(d);
            }
        }
        for (int i = 0; i < deltaPrevElement.size(); i++) {
            kadeneMax.push_back(0);
            kadeneMin.push_back(0);
        }

        cout << doKadene() << "\n";
    }

    LL doKadene() {
        kadeneMax.push_back(deltaPrevElement[0]);
        kadeneMin.push_back(deltaPrevElement[0]);

        for (int i = 1; i < deltaPrevElement.size(); i++) {
            kadeneMax.push_back(deltaPrevElement[i] + (max(kadeneMax[i-1], (LL)0)));
            kadeneMin.push_back(deltaPrevElement[i] + (min(kadeneMin[i-1], (LL)0)));
        }

        LL v1 = *(max_element(ALL(kadeneMax)));
        LL v2 = *(min_element(ALL(kadeneMin)));

        return max(abs(v1), abs(v2));
    }

};

C c;
int main() {
    c.start();
    return 0;
}
