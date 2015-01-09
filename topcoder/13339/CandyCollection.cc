
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
#include <stdio.h>

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()

using namespace std;

// }}}

const int MAX_ELEMENTS = 1001;
typedef pair<int, int> PI;
typedef vector <int> VI;


class Node {
    public:
        int n1, c1, n2, c2;
        int index;
        Node() {
            n1 = c1 = n2 = c2 = index = -1;
        }

        bool isLeft(int otherIndex) {
            return otherIndex == n1;
        }

        bool isRight(int index) {
            return index == n2;
        }

        int getOther(int otherIndex) {
            if (otherIndex == n1) {
                return n2;
            } else {
                return n1;
            }
        }

        int getDistance(int neighbor) {
            if (neighbor == n1) {
                return c1;
            } else {
                return c2;
            }
        }

        void print() {
            printf("Index=%d n1=%d, c1=%d, n2=%d, c2=%d\n", index, n1, c1, n2, c2);
        }

};

class CandyCollection
{
public:

    Node nodes[MAX_ELEMENTS];
    bool isVisited[MAX_ELEMENTS];

    void clearAll() {
        for (int i = 0; i < MAX_ELEMENTS; i++) {
            isVisited[i] = false;
        }
    }

    void insertIntoNodeList(int index, int neighbor, int neighbordistance) {
        nodes[index].index = index;
        if (nodes[index].n1 == -1) {
            nodes[index].n1 = neighbor;
            nodes[index].c1 = neighbordistance;
        } else {
            nodes[index].n2 = neighbor;
            nodes[index].c2 = neighbordistance;
        }
    }

    int doDfs(int i) {
        int sum1, sum2, count;
        sum1 = sum2 = count = 0;
        int prevNodeIndex = -1;
        int cost;
        while (isVisited[i] != true) {
            cout << "Index = " << i <<"PrevNodeIndex = " << prevNodeIndex << "\n";
            Node node = nodes[i];
            node.print();
            int nextNodeIndex;
            if (prevNodeIndex == -1) {
                nextNodeIndex = node.n2;
            } else {
                nextNodeIndex = node.getOther(prevNodeIndex);
            }
            cout << "Next Node index = " << nextNodeIndex << "\n";

            cost = node.getDistance(nextNodeIndex);
            
            cout << "Cost = " << cost << "\n";

            if (count %2 == 0) {
                sum1 += cost;
                cout << "Count is even adding it to sum1 sum1="<< sum1 <<"\n";
            } else {
                sum2 += cost;
                cout << "Count is odd adding it to sum2 sum2 = " << sum2 << "\n";
            }

            prevNodeIndex = i;
            count++;
            i = nextNodeIndex;
            isVisited[prevNodeIndex] = true;
        }
        return min(sum1, sum2);
    }

	int solve(vector <int> t1, vector <int> n1, vector <int> t2, vector <int> n2)
	{
        clearAll();
        for (int i = 0; i < t1.size(); i++) {
            insertIntoNodeList(t1[i], t2[i], max(n1[i], n2[i])+1);
            insertIntoNodeList(t2[i], t1[i], max(n1[i], n2[i])+1);
        }
        int sum = 0;
        for( int i = 0; i < t1.size(); i++) {
            if (isVisited[i] != true) {
                cout << "found disconnected piece\n";
                sum += doDfs(i);
            }
        }
        return sum; 
	}
};

