#include <iostream>
#include <cmath>

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()

using namespace std;

typedef pair <int, int> PI;

typedef long long LL;
const int SZ = 51;

class date {
    public:
        void start() {
            int a, b, s;
            cin >> a >> b >> s;
            int d = abs(a) + abs(b);
            if (d > s) {
                cout << "No\n";
                return;
            }
            if ( (d - s ) % 2 == 0) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        }    
};

date t;

int main(int argc, char **argv) {
    t.start();
    return 0;
}
