#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
const int SZ = 51;
class AB {
    public:
        int canFit(int n, int k) {
            for (int i = 1; i <= n; i++) {
                if (i * (n-i) >= k) {
                    return i;
                }
            }
            return -1;
        }
        int N, K;
        string createString(int _N, int _K ) {
            N = _N;
            K = _K;
            int bCount;
            if ((bCount = canFit(N, K)) < 0) return string();
            int excess = ((N - bCount) * bCount) - K;
            string s;
            for (int i = 0; i < N; i++) {
                if (i < (N - bCount)) s += 'A';
                else s += 'B';
            }
            int bMoves = 0;
            for (int i = 0; excess > 0; i++) {
                if (excess > (N - bCount)) {
                    swap(s[bMoves], s[N - bCount + bMoves]);
                    bMoves++;
                    excess -= (N - bCount);
                } else {
                    swap(s[N - bCount + bMoves], s[N - bCount + bMoves - excess]);
                    excess = 0;
                }
            }
            return s;
        }

        bool isValidSoln(string s, int n, int k) {
            int res = 0;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < i; j++ ) {
                    if (s[j] < s[i]) res++;
                }
            }
            return res == k;
        }

        string createString(int n, int k, bool validate) {
            string s = createString(n, k);
            cout << "String s = " << s;
            if (isValidSoln(s, n, k)) {
                cout << "This is Valid\n";
            } else {
                cout << "This is NOT Valid";
            }
            return s;
        }

};

AB ab;
int main(int argc, char **Argv) {
    cout << ab.createString(3, 2, true) << "\n";
    cout << ab.createString(2, 0, true) << "\n";
    cout << ab.createString(5, 8, true) << "\n";
    cout << ab.createString(10, 12, true) << "\n";
    cout << ab.createString(3, 1, true) << "\n";
    return 0;
}

