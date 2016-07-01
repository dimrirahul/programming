#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using PI = pair<int, int>;

struct C {
    int _n, _m;
    vector<PI> _stk;
    vector<int> _store;
    bool isOfSameTypeAndShorter(const PI& p) {
        const PI& last = *(_store.back());
        return last.first > p.first && last.second == p.second;
    }

    bool isOfDifferentTypeAndShorter(const PI& p) {
        const PI& last = *(_store.back());
        return last.first > p.first && last.second != p.second;
    }

    bool isOfSameTypeAndEqual(const PI& p) {
        const PI& last = *(_store.back());
        return last == p;
    }

    bool isOfDifferentTypeAndEqual(const PI& p) {
        const PI& last = *(_store.back());
        return last.first == p.first && last.second != p.second;
    }

    int findNextLargest(int beg, int end, int val) {
        if (_stk[beg].first <= val) return -1;
        int prevBeg = beg;
        int prevEnd = end;
        while (beg < end) {
            int m = (beg + end) / 2;
            if (_stk[m].first > val) {
                beg = m;
            } else {
                end = m;
            }
            if (prevBeg == beg && prevEnd == end) break;
            prevBeg = beg;
            prevEnd = end;
        }
        return beg;
    }

    void start() {
        cin >> _n >> _m;
        for (int i = 0; i < _n; i++) {
            int t;
            cin >> t;
            _store.push_back(t);
        }

        for (int i = 0; i < _m; i++) {
            int t, v;
            cin >> t >> v;
            PI p = make_pair(v, t);
            if (_stk.empty()) _stk.push_back(p);
            else {
                if (isOfSameTypeAndShorter(p)) {
                    continue;
                } else if (isOfDifferentTypeAndShorter(p)) {
                    _store.push_back(p);
                } else if (isOfSameTypeAndEqual(p)) {
                    //do nothing;
                } else if (isOfDifferentTypeAndEqual(p)) {
                    _stk.pop_back();
                    _stk.push_back(p);
                } else {
                    int pos = findNextLargest(0, _stk.size(), v);
                    if (pos < 0) {
                        //no element found clear vector
                        _stk.clear();
                        _stk.push_back(p);
                    } else {
                        vector<PI>::iterator it = advance(_stk.begin() + pos + 1);
                        _stk.erase(it, _stk.end());
                        //only push if it is of different type
                        if (t != _stk.back()->second) {
                            _stk.push_back(p);
                        }
                    }
                }
            }
        }
    }
};

C t;
int main(int argc, char **argv) {
    t.start();
    return 0;
}
