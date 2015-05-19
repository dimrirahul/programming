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
typedef long long int UI;
class B {
public:

    int lessCount, moreCount, equalCount;
    UI lessSum, moreSum, equalSum;
    int moreNumbersToPick, lessNumbersToPick;
    int n, k, p, x, y;
    bool isPossible() {
        if (lessCount > n/2) return false;
        moreNumbersToPick = max((n+1)/2 - (moreCount + equalCount), 0);
        lessNumbersToPick = n - (moreCount + equalCount + moreNumbersToPick + lessCount);
        return (moreNumbersToPick * y + lessNumbersToPick + moreSum + lessSum + equalSum <= x);
    }

    void start() {
        lessSum = moreSum = equalSum = 0;
        lessCount = moreCount = equalCount = 0;
        cin >> n >> k >> p >> x >> y;
        REP(i, k) {
            int t; cin >> t;
            if (t < y) {
                lessSum += t;
                lessCount++;
            } else if ( t == y ) {
                equalSum += t;
                equalCount++;
            } else {
                moreSum += t;
                moreCount++;
            }
        }
        if (isPossible()) {
            REP(i, lessNumbersToPick) cout << "1 ";
            REP(i, moreNumbersToPick) cout << y << " ";
        } else {
            cout << "-1";
        }
        cout << "\n";
    }    
};

B t;

int main(int argc, char **argv) {
    t.start();
    return 0;
}
