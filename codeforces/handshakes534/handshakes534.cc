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

const int SZ = 2 * 1e5 + 4;
typedef long long LL;
class panagram {
    public:
        VI idByHandshakes[SZ];
        int n;

        int searchAndErase(int key) {
            int res = -1;
            if (idByHandshakes[key].size() == 0) return -1;
            res = idByHandshakes[key][idByHandshakes[key].size() - 1];
            idByHandshakes[key].erase(idByHandshakes[key].end() - 1);
            return res;
        }

        void start() {
            cin >> n;
            REP (i, n) {
                int t; cin >> t;
                idByHandshakes[t].push_back(i+1);
            }
            int curr = 0;
            bool feasible = true;
            vector <int> order;
            while (true) {
                if (idByHandshakes[curr].size() > 0) {
                    order.pb(searchAndErase(curr));
                } else {
                    while (idByHandshakes[curr - 3].size() == 0 && curr >= 0) { 
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
