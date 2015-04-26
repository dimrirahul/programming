#include<bits/stdc++.h>

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define FORU(I,A,B) for(unsigned int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define REPU(I,N)   FORU(I,0,N)
#define ALL(A)     (A).begin(), (A).end()

using namespace std;

typedef pair <int, int> PI;
typedef vector <int> VI;
typedef vector<PI> VPI;
typedef vector <string> VS;

typedef long long LL;
class clique {
public:
    VPI vpi;
    void start() {
        int n;
        cin >> n;
        REP(i, n) {
            int  p, q;
            cin >> p >> q;
            vpi.push_back(make_pair(p+q, p-q));
        }
        sort(ALL(vpi));
        int res = 1;
        PI last = vpi[0];
        for (int i = 1; i < vpi.size(); i++) {
            if (vpi[i].second >= last.first) {
                res++;
                last = vpi[i];
            }
        }
        cout << res << "\n";
    }    
};

clique t;

int main(int argc, char **argv) {
    t.start();
    return 0;
}
