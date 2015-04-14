#include<bits/stdc++.h>

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define FORU(I,A,B) for(unsigned int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define REPU(I,N)   FORU(I,0,N)
#define ALL(A)     (A).begin(), (A).end()

using namespace std;

typedef pair <int, int> PI;
typedef vector <int> VI;
typedef vector <string> VS;

typedef long long LL;
const int SZ = 2 * (1e5) + 4;
class polyCaprusDice {
public:
    int arr[SZ];
    LL sv, A;
    int N;
    int maxLimit(int idx) {
        int res = min((LL)arr[idx] , A - (N - 1));  
        //cout << "MaxLimit = " << res << "for idx = " << idx << "\n";
        return (int)res;
    }

    int minLimit(int idx) {
        int res = max((LL)1, (LL)A - (sv - arr[idx]));
        //cout << "MinLimit = " << res << "for idx = " << idx << "\n";
        return (int) res;
    }

    void start() {
        memset(arr, 0, sizeof(int) * SZ);
        sv = 0;
        cin >> N >> A;
        REP(i, N) {
            int t; cin >> t;
            arr[i] = t;
            sv += t;
        }
        REP(i, N) {
            int res = arr[i] - maxLimit(i) + minLimit(i) - 1;
            cout << res << " ";
        }
        cout << "\n";
    }    
};

polyCaprusDice t;

int main(int argc, char **argv) {
    t.start();
    return 0;
}
