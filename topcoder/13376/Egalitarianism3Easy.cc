
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
#include <queue>

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()

using namespace std;

// }}}


const int SIZE = 11;
const int MAX_DISTANCE = 100001;
typedef pair<int, int> IntPair;
typedef map<int, int> IntMap;
typedef map<int, bool> VisitedById;
typedef map< IntPair, int > DistanceMap;
typedef queue <IntPair > PQ;


class Sorter {
    public:
        bool operator()(IntPair lhs, IntPair rhs) {
            return lhs.second > rhs.second;
        }
};

class Egalitarianism3Easy
{
public:

    int results[SIZE][SIZE];
    DistanceMap distanceMap;


    void initResults() {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                results[SIZE][SIZE] = MAX_DISTANCE;
            }
        }
    }

    void populateDistanceMap(vector<int> &a, vector<int> &b, vector<int> &len) {
        distanceMap.clear();
        for (int i = 0; i < a.size(); i++) {
            distanceMap[make_pair(a[i] - 1, b[i] - 1)] = len[i];
            distanceMap[make_pair(b[i] - 1, a[i] - 1)] = len[i];
        }
    }

    void addAllNeighbors(int source, int size, VisitedById &visitedMap, PQ &q, int parentCost) {
        for (int i = 0; i < size; i++) {
            int neighborD = 0;
            map<IntPair, int>::iterator it = distanceMap.find(make_pair(source, i));
            if (it != distanceMap.end()) {
                neighborD = it->second;
            }

            if ( i != source  && visitedMap.count(i) == 0 && neighborD > 0 ) {
                q.push(make_pair(i, parentCost + neighborD));
            }
        }
    }
    
    void printResults() {
        for(int i = 0; i < SIZE; i++) {
            for(int j = 0; j < SIZE; j++) {
                cout << results[i][j] << " ";
            }
            cout << "\n";
        }
    }

    void doBfs(int source, int n) {
        VisitedById visitedMap;
        PQ q;
        q.push(make_pair(source, 0));
        while (!q.empty()) {
            IntPair p = q.front();
            q.pop();
            if (visitedMap.count(p.first) > 0) {
                continue;
            }
            visitedMap[p.first] = true;
            int parentCost = p.second;
            results[source][p.first] = parentCost;
            addAllNeighbors(p.first, n, visitedMap, q, parentCost);
        }
    }

    int evaluatePairwiseDistance( int n) {
        typedef map<int, set<int> > PointsByDistance;
        PointsByDistance pointsByDistance;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n ; j++) {
                if (i == j) {
                    continue;
                }
                int d = results[i][j];
                PointsByDistance::iterator it = pointsByDistance.find(d);
                if (it != pointsByDistance.end()) {
                    bool equidistant = true;
                    for (set<int>::iterator it1 = (it->second).begin(); it1 != (it->second).end(); it1++) {
                        if (*it1 == i || *it1 == j) {
                            continue;
                        }
                        if (!(d == results[*it1][i] && d == results[*it1][j])) {
                            equidistant = false;
                            break;
                        }
                    }
                    if (equidistant) {
                        (it->second).insert(i);
                        (it->second).insert(j);
                    }
                } else {
                    set<int> s;
                    s.insert(i);
                    s.insert(j);
                    pointsByDistance[d] = s;
                }
            }
        }

        size_t maxCount = 1;
        for (PointsByDistance::iterator it = pointsByDistance.begin(); it != pointsByDistance.end(); it++) {
            maxCount = max((it->second).size(), maxCount);
        }
        return (int) maxCount;
    }

    int maxCities(int n, vector <int> a, vector <int> b, vector <int> len)
    {
        initResults();
        populateDistanceMap(a, b, len);
        for(int i = 0; i < n; i ++) {
            doBfs(i, n);
        }
        printResults();
        return evaluatePairwiseDistance(n);
	}
};

