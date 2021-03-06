#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;
using VI = vector<int>;
using LL = long long;
using PI = pair<int, int>;
using MI = map<int, int>;

const bool dbg = !true;
struct A {

  LL getSq(int p) {
    LL res = p;
    return res * res;
  }

  LL getCount(int currLevel, LL &currVal) {
    int nextLevel = currLevel + 1;
    LL moves = (getSq(nextLevel) * currLevel) - (currVal / currLevel);
    currVal = nextLevel;
    currVal *= currLevel;
    return moves;
  }

  void start() {
    int n;
    cin >> n;
    LL res = 0;
    LL curr = 2;
    for (int i = 1; i <= n; i++) {
      res = getCount(i, curr);
      cout << res << "\n";
    }
  }
};

A a;
int main() {
  a.start();
  return 0;
}
