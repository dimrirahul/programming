#include <iostream>
#include <cmath>
#include <cstring>

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()

using namespace std;

typedef pair <int, int> PI;

typedef long long LL;
const int SZ = 101;

class date {
    public:
        int exp[10];
        void increaseExp(int v) {
            if (v == 4) {
                exp[2] += 2;
            } else if (v == 6) {
                exp[2]++;
                exp[3]++;
            } else if (v == 8) {
                exp[2] += 3;
            } else if (v == 9) {
                exp[3] += 2;
            } else {
                exp[v]++;
            }
        }

        void processDigit(int d) {
            for (int i = 1; i <= d; i++) {
                increaseExp(i);
            }
        }

        int getMaxV() {
            int primes[] = {2, 3, 5, 7};
            for (int i = 0; i < 4; i++) {
                if (exp[primes[i]] == 0) {
                    if (i == 0) return -1;
                    else return primes[i-1];
                };
            }
            return 7;
        }

        void decreaseCount(int d) {
            if (d == 4) {
                exp[2] -= 2;
            } else if (d == 6) {
                exp[2]--;
                exp[3]--;
            } else if (d == 8) {
                exp[2] -= 3;
            } else if (d == 9) {
                exp[3] -= 2;
            } else {
                exp[d]--;
            }
        }
        void start() {
            REP (i, 10) exp[i] = 0;
            int junk;
            string s;
            cin >> junk;
            cin >> s;
            REP (i, s.size()) {
                processDigit(s[i] - '0');
            }
            int mv = 0;
            string res;
            while ((mv = getMaxV()) != -1) {
                res += (mv + '0');
                for (int i = 1; i <= mv; i++) {
                    decreaseCount(i);
                }
            }
            cout << res << "\n";
        }
};

date t;

int main(int argc, char **argv) {
    t.start();
    return 0;
}
