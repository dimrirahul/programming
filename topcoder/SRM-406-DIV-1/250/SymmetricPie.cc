
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

const int MAX_SIZE= 9;
class SymmetricPie
{
    public:
        int numDogs;
        double angles[MAX_SIZE];
        bool visited[MAX_SIZE];

        void init() {
            REP(i, MAX_SIZE) {
                angles[i] = 0.0;
                visited[i] = false;
            }
        }

        bool isOpposite(int pos1, int pos2) {
            double less = min (angles[pos1], angles[pos2]);
            double more = max (angles[pos1], angles[pos2]);

            double delta = more - less;


            bool retValue = abs(180 - delta) < 1e-13;
            //printf("Index pos1=%d, pos2=%d less=%f, more=%f, delta=%f ,returnValue =%d\n", pos1, pos2, less, more, delta, retValue);

            return retValue;
        }

        void fillAngeles(vector<int> &d) {
            REP(i, d.size()) {
                double degree = (double) 3.6 * d[i];
                angles[i+1] = angles[i] + degree;
            }
        }

        int getCount() {
            int count = 0;
            REP(i, numDogs + 1) {
                REP(j, numDogs + 1) {
                    if (visited[i] || visited[j] || i == j) continue;
                    if (isOpposite(i,j)) {
                        count++;
                        visited[j] = true;
                    }
                }
                visited[i] = true;
            }
            return count;
        }

        void printAngles() {
            REP(i, numDogs+1) {
                cout << angles[i] << " ";
            }
            cout << "\n";
        }
        int getLines(vector <int> dogs)
        {
            numDogs = dogs.size();
            sort(ALL(dogs));
            int count = 0;
            do {
                init();
                fillAngeles(dogs);
            //    printAngles();
                count = max(count, getCount());
            }while (next_permutation(ALL(dogs)));
            return count;
        }
};

