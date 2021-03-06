
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

class ShipLoading
{
    public:

        vector<int> cr;
        vector<int> box;

        bool test(int time) {
            
            int b = 0; int c = 0; int prevIndex = 0;

            REP(i, cr.size()) {
                REP (j, time) {
                    if (cr[i] >= box[j+prevIndex]) {
                        b++;
                    } else {
                        break;
                    }
                }
                prevIndex = b;
            }
            printf("Time = %d, boxes = %d, result =%d\n", time, b, b >= box.size());
            return b >= box.size();
        
        }

        int minimumTime(vector <int> cranes, vector <string> boxes)
        {
            cr = cranes;
            stringstream ss(accumulate(ALL(boxes), string()));
            int num;
            while (ss >> num) {
                box.push_back(num);
            }

            sort(ALL(box));
            sort(ALL(cr));

            int high = 27 * 50;
            int low = 0;

            while (high > low) {
                int mid = (high + low) >> 1;

                int value = test(mid);

                if (value) {
                    high = mid;
                    
                } else {
                    low = mid +1;
                }

            }
            
            return low;
        }
};

