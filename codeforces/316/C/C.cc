#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <stdio.h>
#include <unordered_map>
#include <cassert>


#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()

using namespace std;

using PI = pair <int, int>;
using VI = vector <int>;
using VS = vector <string>;
using PM = map <int, PI>;
const bool dbg = !true;

typedef long long LL;
struct C {
    PM _table;
    int _sum;
    string _str;
    int _len, _queries;

    int getMoves(int len) {
        int res = 0;
        int rem = 0;
        while (len > 1) {
            if (len & 1) rem = 1;
            else rem = 0;
            len /= 2;
            res += len;
            len += rem;
        }
        return res;
    }

    int findLen(int startPos) {
        int res = 0;
        while(startPos < _str.size() && _str[startPos++] == '.') res++;
        return res;
    }

    void preProcess() {
        int pos = 0;
        while (pos < _len) {
            if (_str[pos] == '.') {
                auto len = findLen(pos);
                insertIntoTableAndUpdateSum(pos, len);
                pos += len;
            }
            pos++;
        }
    }

    void printMap() {
        for (auto &it: _table) {
            cout << "Pos = " << it.first << " len = " << (it.second).first << " Sum = " << (it.second).second << "\n";
        }
    }
    
    bool isDot(char val) { return val == '.'; }

    void insertIntoTableAndUpdateSum(int startPos, int len) {
        int sum = getMoves(len);
        _sum += sum;
        if (dbg) cout << "Updating " << startPos << " with len = " << len << " sum = " << sum << "\n";
        _table[startPos] = make_pair(len, sum);
    }

    void handleContained(PM::iterator &iter, int pos, char val) {
        assert(!isDot(val));
        int l1 = pos - iter->first;
        int l2 = (iter->first + iter->second.first - (pos+1));
        _sum -= iter->second.second;

        int s1 = iter->first;
        int s2 = pos + 1;
        _table.erase(iter);
        if (l1 > 0) {
            insertIntoTableAndUpdateSum(s1, l1);
        }
        if (l2 > 0) {
            insertIntoTableAndUpdateSum(s2, l2);
        }
    }

    void printIterator(PM::iterator it, string msg = string()) {
        cout << msg <<  " Pos: " << it->first << " len = " << it->second.first << " sum: " << it->second.second << "\n";
    }

    void handleLeftAndRight(PM::iterator &left, PM::iterator &right, int pos, char val) {
       
        if (dbg) {
            cout << "Handle left and right \n";
            printIterator(left, "left");
            printIterator(right, "right");
        }
        assert(isDot(val));
        if (left->first + left->second.first + 1 == right->first) {
            _sum -= left->second.second;
            _sum -= right->second.second;
            int l = left->second.first + right->second.first + 1;
            int start = left->first;
            _table.erase(left);
            _table.erase(right);
            insertIntoTableAndUpdateSum(start, l);
        } else if (canMergeWithLeft(left, pos)) {
            handleLeft(left, pos, val);
        } else if (canMergeWithRight(right, pos)) {
            handleRight(right, pos, val);
        } else {
            insertIntoTableAndUpdateSum(pos, 1);
        }
    }

    bool canMergeWithLeft(PM::iterator &left, int pos) {
        return left->first + left->second.first == pos;
    }

    bool canMergeWithRight(PM::iterator &right, int pos) {
        return pos + 1 == right->first;
    }
    void handleLeft(PM::iterator &left, int pos, char val) {
        assert(isDot(val));
        if (canMergeWithLeft(left, pos)) {
            int nl = left->second.first + 1;
            int start = left->first;
            _sum -= left->second.second;
            _table.erase(left);
            insertIntoTableAndUpdateSum(start, nl);
        } else {
            insertIntoTableAndUpdateSum(pos, 1);
        }
    }

    void handleRight(PM::iterator &right, int pos, char val) {
        assert(isDot(val));
        if (canMergeWithRight(right, pos)) {
            int nl = right->second.first + 1;
            int start = pos;
            _sum -= right->second.second;
            _table.erase(right);
            insertIntoTableAndUpdateSum(start, nl);
        } else {
            insertIntoTableAndUpdateSum(pos, 1);
        }
    }

    void start() {
        cin >> _len >> _queries >> _str;
        preProcess();
        REP(i, _queries) {
            int pos; char val;
            cin >> pos >> val;
            pos--;

            if ( (_str[pos] == '.' && val == '.') ||
                    (_str[pos] != '.' && val != '.')) {
            } else {
                bool hasLeft = false, hasRight = false, isContained = false;
                PM::iterator next = _table.lower_bound(pos);
                PM::iterator containedIter = _table.end();

                if (next != _table.end()) hasRight = true;
                if (next != _table.begin()) hasLeft = true;

                PM::iterator prev = next;
                if (hasLeft) {
                    prev--;
                    if (prev->first + prev->second.first > pos) {
                        isContained = true;
                        containedIter = prev;
                    }
                }
                if (hasRight && next->first == pos) {
                    isContained = true;
                    containedIter = next;
                }

                if (isContained) handleContained(containedIter, pos, val);
                else if (hasLeft && hasRight) handleLeftAndRight(prev, next, pos, val);
                else if (hasLeft) handleLeft(prev, pos, val);
                else handleRight(next, pos, val);
            }
            _str[pos] = val;
            cout << _sum << "\n";
            if (dbg) {
                cout << "Str = " << _str << "\n";
                printMap();
            }
        }
    }    
};

C t;

int main(int argc, char **argv) {
    t.start();
    return 0;
}
