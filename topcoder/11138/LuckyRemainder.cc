
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
#include <stdio.h>

using namespace std;

// }}}


class Node {
    public:
        int a, b, d;
        Node () {
            a = b = d = 0;
        }
        Node (int x, int y, int z) {
            a = x;
            b = y;
            d = z;
        }

        bool operator <(Node other) const {
            if ( a != other.a) {
                return a < other.a;
            }
            if ( b!= other.b) {
                return b < other.b;
            }
            return d < other.d;
        }

        void print() const{
            printf("a=%d, b=%d, d=%d", a, b, d);
        }
        
};

map <Node, int> g_resultMap;
class LuckyRemainder
{
    public:
        int getLuckyRemainder(string X)
        {
            for (int i = 0; i < X.size(); i++) {
                Node n(i, i, 0);
                g_resultMap[n] = (X[i] - '0') % 9;
            }


            int s = X.size();
            for (int d = 0; d < s - 1; d++) {
                for (int i = 0; i < s -d -1; i++) {
                    for (int j = i + d + 1; j < s; j++){ 
                        int v = g_resultMap[Node(i, d + i, d)] + g_resultMap[Node(j, j, 0)];
                        v = v % 9;
                        Node t (i, j, d + 1);
                        g_resultMap[t] = v;
                    }
                }
            }

            int sum = 0;
            for (map<Node, int>::const_iterator it = g_resultMap.begin(); it != g_resultMap.end(); it++) {
                it->first.print(); 
                printf(" %d\n", it->second);
                sum += it->second;
            }
            return sum%9;
        }
};

