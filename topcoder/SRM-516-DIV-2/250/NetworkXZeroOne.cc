
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

class NetworkXZeroOne
{
    public:
        string reconstruct(string message)
        {
            int pos = 0;
            REP(i, message.size()) {
                pos= i;
                if (message[i] == 'x' || message[i] == 'o') {
                    break;
                }
            }
            for (int i = pos -1; i >= 0; i--) {
                if (message[i+1] == 'o') {
                    message[i] = 'x';
                } else {
                    message[i] = 'o';
                }
            }

            for (int i = pos + 1; i < message.size(); i++) {
                if (message[i-1] == 'o') {
                    message[i] = 'x';
                } else {
                    message[i] = 'o';
                }
            }

            return message;
        }
};

