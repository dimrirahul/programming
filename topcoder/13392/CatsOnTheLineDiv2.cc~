
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
        int pos;
        int numCats;
        Node(int position, int numberOfCats): pos(position), numCats(numberOfCats) {
        }
        bool operator < (Node other) const {
            return pos < other.pos;
        }

        bool isWideEnough(int space) {
            if (space < numCats - 1) {
                return false;
            } else {
                return true;
            }
        }

        void print() {
            printf("Pos =%d, numCats =%d, \n", pos, numCats);
        }
};

class CatsOnTheLineDiv2
{
public:
    vector <Node> cv;
	string getAnswer(vector <int> position, vector <int> count, int time)
	{
        for (int i = 0; i < count.size(); i++) {
            cv.push_back(Node(position[i], count[i]));
        }
        sort(cv.begin(), cv.end());

        bool possible = cv[0].isWideEnough(2 * time);
        int prev = cv[0].pos - time + cv[0].numCats;
        for (int i = 1; i < cv.size(); i++) {
            Node &node = cv[i];
            cout << "Prev = " << prev << "\n";
            int start = max(prev, node.pos - time);
            cout << "Start = " << start << "\n";
            int space = node.pos + time - start;
            cout << "Space = " << space << "\n";
            if (node.isWideEnough(space)) {
                prev = start + node.numCats;
            }else {
                possible = false;
                cout << "Not wide enough\n";
                break;
            }

        }

        if (possible) {
            return string("Possible");
        } else {
		    return string("Impossible");
        }
	}
};

