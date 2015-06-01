#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

typedef vector<int> VI;
typedef VI::iterator VIter;

void updateInterval(VI &inp, int interval) {
    if (inp.size() == 0) return;
    sort(inp.begin(), inp.end());
    int lc = 1;
    int sv = inp[0];
    for (VIter i1 = inp.begin(); i1 != inp.end();) {
        VIter i2 = i1;
        i2++;
        if (i2 != inp.end()) {
            if (*i2 != sv + lc * interval) {
                i1 = inp.insert(i2, 0);
            } else {
                i1++;
            }
        } else break;
        lc++;
    }
}

pair <VI, int> t1Input() {
    VI v;
    v.push_back(5);
    v.push_back(10);
    v.push_back(20);
    v.push_back(35);
    v.push_back(45);
    return make_pair(v, 5);
}

pair <VI, int> t2Input() {
    VI v;
    v.push_back(5);
    v.push_back(45);
    v.push_back(100);
    return make_pair(v, 5);
}

int main(int argc, char **argv) {
    pair <VI, int> p = t1Input();
    updateInterval(p.first, p.second);
    for (int i = 0; i < p.first.size(); i++)  {
        printf("[%d * %d = %d , val in arr = %d]\n", p.second, i+1, p.second * (i+1), p.first[i]);
    }
    return 0;
}
