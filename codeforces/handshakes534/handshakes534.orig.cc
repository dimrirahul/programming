#include <iostream>
#include <cstring>
#include <cstdlib>
#include <map>
#include <vector>
#include <set>
#include <algorithm>

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define mp make_pair
#define pb push_back 

using namespace std;

typedef pair <int, int> PI;
typedef vector <int> VI;
typedef vector <string> VS;

typedef long long LL;
class panagram {
    public:
        map <int, VI > idByHandshakes;
        int n;

        int searchAndErase(int key) {
            int res = -1;
            map <int, VI>::iterator it = idByHandshakes.find(key);
            res = (it->second)[(it->second).size() - 1];
            (it->second).erase((it->second).end() - 1);
            if ((it->second).size() == 0) idByHandshakes.erase(key);
            return res;
        }

        void start() {
            cin >> n;
            REP (i, n) {
                int t; cin >> t;
                map <int, VI>::iterator it = idByHandshakes.find(t);
                if (it != idByHandshakes.end()) (it->second).push_back(i+1);
                else {
                    vector <int> vt;
                    vt.pb(i+1);
                    idByHandshakes[t] = vt;
                }
            }
            int curr = 0;
            bool feasible = true;
            vector <int> order;
            while (true) {
                if (idByHandshakes.count(curr)) {
                    order.pb(searchAndErase(curr));
                } else {
                    while (idByHandshakes.count(curr - 3) == 0 && curr >= 0) { 
                        curr -= 3;
                    }
                    if (curr >= 0) {
                        order.pb(searchAndErase(curr - 3));
                        curr -= 3;
                    } else {
                        feasible = false;
                        break;
                    }
                }
                curr++;
                if (order.size() == n) break;
            }
            if (feasible) {
                cout << "Possible\n";
                REP(i, order.size()) {
                    cout << order[i] << " ";
                }
            } else {
                cout << "Impossible\n";
            }
        }    
};

panagram t;

int main(int argc, char **argv) {
    t.start();
    return 0;
}
