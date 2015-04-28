#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;
typedef set <string> VS;

class MatchParens {
    public:
        map < int, VS> cache;
        VS generateStrings(int n) {
            if (cache.count(n) > 0) return cache[n];
            VS res;
            if (n == 0) {
                res.insert("");
                return res;
            }
            VS resMinus1 = generateStrings(n-1);
            for (VS::const_iterator i = resMinus1.begin(); i != resMinus1.end(); i++) {
                res.insert(string("(") + *i + string(")"));
            }
            for (int i = 1; i < n; i++) {
                VS resNMinusI = generateStrings(n-i);
                VS resI = generateStrings(i);
                for (VS::const_iterator j = resNMinusI.begin(); j != resNMinusI.end(); j++) {
                    for (VS::const_iterator k = resI.begin(); k != resI.end(); k++) {
                        res.insert(*j + *k);
                    }
                }
            }
            cache[n] = res;
            return res;
        }

        void printRes(VS inp) {
            for (VS::const_iterator i = inp.begin(); i != inp.end(); i++) cout << *i << "\n";
        }
};

MatchParens p;
int main(int argc, char **argv) {
    int n; cin >> n;
    p.printRes(p.generateStrings(n));
    return 0;
}
