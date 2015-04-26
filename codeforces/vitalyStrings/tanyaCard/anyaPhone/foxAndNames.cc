//#include<bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <queue>
#include <cstring>



#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()

using namespace std;

typedef pair <int, int> PI;
typedef vector <int> VI;
typedef vector <string> VS;

typedef long long LL;
const int SZ = 100000;


class foxAndDots {
    public:
        int idToPos[SZ];
        int posToId[SZ];
        int n, m, k;
        void init() {
            REP (i, SZ) { 
                idToPos[i] = posToId[i] = -1;
            }
        }
        int pressButton(int t) {
            //Get postion of button.
            //Get value of previos position.
            //swap values 
            //update 
            int pos = idToPos[t];
            if (pos != 0) {
                int prev = pos - 1;
                int otherValue = posToId[prev];
                idToPos[otherValue]++;
                idToPos[t]--;
                posToId[pos] = otherValue;
                posToId[prev] = t;
            }
            return (pos/k) + 1;
        }
        void start() {
            init();
            cin >> n >> m >> k;
            REP (i, n) {
                int t;
                cin >> t;
                t--;
                idToPos[t] = i;
                posToId[i] = t;
            }
            int res = 0;
            REP (i, m) {
                int t;
                cin >> t;
                t--;
                res += pressButton(t);
            }
            cout << res << "\n";
        }    
};

foxAndDots t;

int main(int argc, char **argv) {
    t.start();
    return 0;
}
