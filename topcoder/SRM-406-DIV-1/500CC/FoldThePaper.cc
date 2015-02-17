
// {{{ Boilerplate Code <--------------------------------------------------
// vim:filetype=cpp:foldmethod=marker:foldmarker={{{,}}}

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
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
#include <utility>
#include <vector>

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()

using namespace std;

// }}}

const int NA = -1000;
class Node {
    public:
        int r, c;
        vector <int> v;
        Node() {
            r = c = -1;
        }
        bool operator <(Node other) const {
            if (r != other.r) return r < other.r;
            if (c != other.c) return c < other.c;
            return v < other.v;
        }

        int getMax() {
            if (v.size() == 0) return NA;
            int res = NA;
            REP (i, v.size()) {
                res = max(res, v[i]);
            }
            return res;
        }
        
        pair<int, int> convertToRC(int pos) {
            return make_pair( pos/r, pos % r );
        }

        int convertToPos(int _r, int _c) {
            return _r * c + _c;
        }

        void foldAlongVertical(int col, Node& other) {
            other.r = r;
            if (col <= c/2) {
                other.c = c - col;
                REP (i, r) {
                    for (int j = col; j < c; j++) {
                        other.v.push_back(v[convertToPos(i, j)]);
                    }
                }
                REP (i, r) {
                    for (int j = col -1 ; j >= 0; j--) {
                        int d = col - j -1;
                        other.v[other.convertToPos(i, d)] += v[convertToPos(i, j)];
                    }
                }
            } else {
                other.c = col;
                REP (i, r) {
                    for (int j = 0; j < col; j++) {
                        other.v.push_back(v[convertToPos(i, j)]);
                    }
                }
                REP (i, r) {
                    for (int j = col; j < c; j++) {
                        int d = j - col;
                        other.v[other.convertToPos(i, col - 1 - d)] += v[convertToPos(i, j)];
                    }
                }
            }

        }

        void foldAlongHorizontal(int row, Node& other) {
            other.c = c;
            if (row <= r/2) {
                other.r = r - row;
                for (int i = row; i < r; i++) {
                    for (int j = 0; j < c; j++) {
                        other.v.push_back(v[convertToPos(i, j)]);
                    }
                }

                for (int i = row -1 ; i >= 0; i--) {
                    int d = row - i - 1;
                    REP (j , c) {
                        other.v[other.convertToPos(d, j)] += v[convertToPos(i, j)];
                    }
                }
            } else {
                other.r = row;
                REP (i, row) {
                    REP (j, c) {
                        other.v.push_back(v[convertToPos(i, j)]);
                    }
                }

                for (int i = row; i < r; i++) {
                    int d = i - row;
                    REP (j, c) {
                        other.v[convertToPos(row - d -1, j)] += v[convertToPos(i, j)];
                    }
                }
            }
        }

        void print() {
            REP (i, v.size()) {
                printf("%2d ", v[i]);
                if ( (i + 1) % c == 0) {
                    cout << "\n";
                }
            }
        }
};
class FoldThePaper
{
public:
    map <Node, int> cache;
    vector<int> parseInput(vector<string>& paper) {
        vector <int> res;
        REP (i, paper.size()) {
            istringstream ss(paper[i]) {
                int t;
                while (ss >> t) {
                    res.push_back(t);
                }
            }
        }
        return res;
    }

    void populateMap(Node n) {
        if (cache.find(n) > 0) return;
        for (int i = 1; i < n.c - 1; i++) {
            Node other;
            n.foldAlongVertical(i, other);
            populateMap(other);
        }
        for (int i = 1; i < n.r -1; i++) {
            Node other;
            n.foldAlongHorizontal(i, other);
            populateMap(other);
        }
        int res = n.getMax();
        cache[n] = res;
    }
	int getValue(vector <string> paper)
	{
        Node n;
        vector<int> v = parseInput(paper);
        n.r = paper.size();
        n.c = v.size() / n.r;
        n.v.insert(n.v.end(), ALL(v));
        populateMap(n);
        int res = NA;
        for (map<Node, int>::const_iterator it = cache.begin(); it != cache.end(); it++) {
            res = max(res, it->second);
        }
		return res;
	}
};

