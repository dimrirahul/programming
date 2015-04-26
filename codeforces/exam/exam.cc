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
const int SZ = 5002;
class exam {
public:

    int arr[SZ];
    void start() {
        memset(arr, 0, sizeof(int) * SZ);
        int n;
        cin >> n;
        vector<int> res;
        if ( n == 1 || n == 2) res.push_back(1);
        else if (n == 3)  { res.push_back(1); res.push_back(3); }
        else if ( n == 4) { res.push_back(3); res.push_back(1); res.push_back(4); res.push_back(2);}
        else {
            for (int i = 1; i <= n; i += 2) {
                res.push_back(i);
            }
            for (int i = 2; i <= n; i+= 2) {
                res.push_back(i);
            }
        }
        cout << res.size() << "\n";
        REP(i, res.size()) { cout << res[i] << " ";}
        cout << "\n";
    }    
};

exam t;

int main(int argc, char **argv) {
    t.start();
    return 0;
}
