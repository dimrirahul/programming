#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <array>
#include <set>
#include <stack>


#define REP(I, N) for (int (I) = 0; (I) < (N); I++)
#define RI(I) int (I); cin >> (I);
using namespace std;
using VI = vector<int>;
using STK = stack<int>;

const int SZ = (int)2e5 + 5;
const bool dbg = !true;
class D {
    public:
        VI inp, left, right;
        array<int, SZ> maxVBylen{};

        void start() {
            RI(t);
            REP(i, t) {
                RI(u);
                inp.insert(end(inp), u);
            }
            fillLeftAndRight();
            maxVBylen.fill(0);
            findLeftEndpoints();
            findRightEndpoints();
            updateMaxValueByLen();
        }

        void fillLeftAndRight() {
            REP(i, inp.size()) {
                left.insert(end(left), -1);
                right.insert(end(right), inp.size());
            }
        }

        void updateMaxValueByLen() {
            REP(i, inp.size()) {
                int len = right[i] - left[i] -1;
                if (dbg) {
                    printf("value=%d, index=%d, leftIdx=%d, rightIdx=%d, len=%d prevMaxV=%d", inp[i], i, left[i], right[i], len, maxVBylen[len]);
                }
                maxVBylen[len] = max(maxVBylen[len], inp[i]);
                if (dbg) {
                    printf(" After update maxV=%d\n", maxVBylen[len]);
                }
            }
            int prev = 0;
            for (int i = inp.size(); i >= 1; i--) {
                maxVBylen[i] = max(prev, maxVBylen[i]);
                prev = maxVBylen[i];
            }
            for (int i = 1; i <= inp.size(); i++) cout << maxVBylen[i] << " "; 

        }

        void findLeftEndpoints() {
            STK stk;
            REP(i, inp.size()) {
                findMaxLeast(i, stk, left, true);
            }
        }

        void findRightEndpoints() {
            STK stk;
            for (int i = inp.size() - 1; i >= 0; i--) {
                findMaxLeast(i, stk, right, false);
            }
        }

        void findMaxLeast(int idx, STK& stk, VI& v, bool isLeft) {
            int t = isLeft ? -1: inp.size();
            if (!stk.empty()) {
                t = stk.top();
                while (inp[t] >= inp[idx]) {
                    stk.pop();
                    if (!stk.empty()) {
                        t = stk.top();
                    } else {
                        t = isLeft ? -1: inp.size();
                        break;
                    }
                }
            } 
            v[idx] = t;
            stk.push(idx);
        }

};

D d;
int main(int argc, char **argv) {
    d.start();
    return 0;
}
