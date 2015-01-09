
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

class CubeStickers
{
public:
    string isPossible(vector <string> sticker)
    {
        map<string, int > s;
        map<string, int>::iterator it;
        for (int i = 0; i < sticker.size(); i++)  {
            it = s.find(sticker[i]);
            if (it == s.end()) {
                //cout << "Inserting into set =" << sticker[i] << "\n";
                s[sticker[i]] = 1;
            } else {
                it->second++;
            }
        }
        int m = 0;
        for (it = s.begin(); it != s.end(); it++) {
            //cout << "Color = " << it->first << " Count =" << it->second << "\n";
            if (it->second > 1) {
                m += 2;
            } else {
                m++;
            }
        }
        if (m > 5) {
            return "YES";
        } else {
            return "NO";
        }
    }
};

