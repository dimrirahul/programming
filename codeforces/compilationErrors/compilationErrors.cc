#include<bits/stdc++.h>

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()

using namespace std;

typedef pair <int, int> PI;
typedef vector <int> VI;
typedef vector <string> VS;

typedef long long LL;
class compilationErrors {
public:

    vector<int> v1, v2;
    int N;
    void readInput(int d, vector<int>& v) {
        v.clear();
        REP (i, d) {
            int t;
            cin >> t;
            v.push_back(t);
        }
    }

    void printDiff(vector<int>& x, vector<int>& y) {
        REP (i, y.size()) {
            if (x[i] != y[i]) {
                cout << x[i] << "\n";
                return;
            }
        }
        cout << x[y.size()] << "\n";
    }

    void start() {
        N = 0;
        cin >> N;
        readInput(N, v1);
        readInput(N-1, v2);
        sort(ALL(v1));
        sort(ALL(v2));
        printDiff(v1, v2);
        readInput(N-2, v1);
        sort(ALL(v1));
        printDiff(v2, v1);
    }    
};

compilationErrors t;

int main(int argc, char **argv) {
    t.start();
    return 0;
}
