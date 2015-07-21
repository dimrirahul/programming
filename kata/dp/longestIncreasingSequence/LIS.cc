#include <bits/stdc++.h>

using namespace std;
using PI = pair<int, int>;
using VPI = vector<PI>;
using VI = vector<int>;
#define REP(I, N) for (int (I) = 0; (I) < (N); (I++))
#define REPS(I, S, N) for (int (I) = (S); (I) < (N); (I++))

struct LIS {
    VI longestIncreasingSequece(VI& inp) {
        VPI dp(inp.size());
        dp[0] = PI({1, -1});
        PI maxLen({1, 0});
        REPS(i, 1, inp.size()) {
            PI p({1, -1});
            REP(j, i) {
                if (inp[j] <= inp[i]) {
                    if (dp[j].first + 1 > p.first) {
                        p.first = dp[j].first + 1;
                        p.second = j;
                    }
                }
            }
            dp[i] = p;
            if (p.first > maxLen.first) {
                maxLen.first = p.first;
                maxLen.second = i;
            }
        }
        VI res;
        int pos = maxLen.second;
        while(pos != -1) {
            res.push_back(pos);
            pos = dp[pos].second;
        }
        reverse(begin(res), end(res));
        return res;    
    }

    /*
    int binSearch(VI& inp, int s, int e, int k) {
        while (s < e) {
            if (k <= inp[m]) e = m;
            else s = m+1;
        }
        return s;
    }

    VI longestIncreasingSequeceBinSearch(const VI& inp) {
        VI M(inp.size()), P(inp.size());
        M[0] = 0; M[1] = inp[0];
        int L = 0;
        REPS(i, 1, inp.size()) {
            M[1] = min(M[1], inp[i]);

        }
    }
    */
};
LIS lis;
int main(int argc, char **argv) {
    VI input({0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15});
    VI res = lis.longestIncreasingSequece(input);
    for (auto& i: res) cout << input[i] << " ";
    return 0;
}
