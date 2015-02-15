#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <vector>
#include <cstring>

using namespace std;
const int p1 = 97;
const int p2 = 7919;
typedef long long UL;
const int SZ = 300;
class RabinKarpMatcher {
    public:
        UL powCache[SZ];
        UL pow(UL x, int exp) {
            if (powCache[exp] != 0) return powCache[exp];
            UL res = 1;
            for (int i = 0; i < exp; i++) {
                res *= x;
                res %= p2;
            }
            powCache[exp] = res;
            return res;
        }

        UL modAdd(UL x, UL y, bool isAdd = true) {
            x %= p2;
            y %= p2;
            UL res = (isAdd) ? x + y : x - y;
            if (res < 0) res += p2;
            res %= p2;
            return res;
        }

        UL getHashValue(string s, int pos, int len) {
            UL res = 0;
            for (int i = 0; i < len; i++) {
                res = modAdd(res, (s[pos + i] - 'a') * pow(p1, len -1 -i));
            }
            return res;
        }

        bool isFound(string text, string pat) {
            UL hvp = getHashValue(pat, 0, pat.size());
            UL curr = getHashValue(text, 0, pat.size());
            memset(powCache, 0, sizeof(UL) * SZ);
            int pos = 0;
            do {
                printf("hvp=%lld curr=%lld\n", hvp, curr);
                if (hvp == curr) {
                    cout << "Potential match at pos=" << pos << "\n";
                    if (text.substr(pos, pat.size()) == pat) {return true;}
                } else {
                    curr = modAdd(curr, (text[pos] - 'a') * pow(p1, pat.size() - 1), false);
                    curr *= p1;
                    curr = modAdd(curr, text[pos + pat.size()] - 'a');
                }
                pos++;
            } while (pos + pat.size() <= text.size());

            return false;
        
        }
};

RabinKarpMatcher rk;
int main(int argc, char **argv) {
    string s1, s2;
    cin >> s1 >> s2;
    if (rk.isFound(s1, s2)) {
        cout << s2 << " is a subpattern of  " << s1 << "\n";
    } else {
        cout << s2 << " is NOT subpattern of  " << s1 << "\n";
    }
    return 0;
}
