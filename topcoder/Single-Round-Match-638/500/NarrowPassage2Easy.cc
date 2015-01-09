
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

class Node {
    public:
        int m_value;
        int m_index;
        Node(int value, int index) {
            m_value = value;
            m_index = index;
        }
        bool operator<(Node other) const {
            return m_value < other.m_value;
        }
};
class NarrowPassage2Easy
{
public:

    void printVector(vector<Node> &v, string message) {
        cout << message << "\n";
        REP(i, v.size()) {
            printf("value=%d, index=%d\n", v[i].m_value, v[i].m_index);
        }
        cout << "\n";
    }
    int findNewIndex(int index, vector<Node>& c) {
        REP(i, c.size()) {
            if (c[i].m_index == index) {
                return i;
            }
        }
        return -1;
    }
    bool isPossible(vector<Node> &c, vector<Node> &o, int maxSizeSum) {
        printVector(o, string("Original vector"));
        printVector(c, string("Copy vector"));
        REP(i, o.size()) {
            int pos = findNewIndex(i, c);
            cout << "Original index = " << i << " Pos in copy = " << pos << "\n";
            for ( int j = min(i, pos); j <= max(pos, i); j++) {
                if (j == i) continue;
                if (o[j].m_value + o[i].m_value > maxSizeSum) {
                    printf("Original index =%d has value =%d traversalindex=%d has value=%d maxsum=%d\n", i, o[i].m_value, j, o[j].m_value, maxSizeSum);
                    return false;
                } 
            }
        }
        cout << "Returning true " << "\n";
        return true;
    }
	int count(vector <int> v, int maxSizeSum)
	{
        vector<Node> orig;
        vector<Node> copy;
        int res = 0;
        REP(i, v.size()) {
            Node n(v[i], i);
            orig.push_back(n);
            copy.push_back(n);
        }

        sort(ALL(copy));
        do {
            if (isPossible(copy, orig, maxSizeSum)) {
                res++;
            }
        } while(next_permutation(ALL(copy)));

        return res;
	}
};
