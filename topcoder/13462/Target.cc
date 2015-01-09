
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


const int MAX_SIZE = 51;
char g_arr[MAX_SIZE][MAX_SIZE];
class Target
{

public:
    void printSquare(int start, int length) {
        for (int i = start; i < length + start; i++) {
            if (i == start || i == length + start -1) {
                for (int j = start ; j < length + start; j++) {
                    g_arr[i][j] = '#';
                }
            }

            g_arr[i][start] = g_arr[i][start+length - 1] = '#';
        }
    }
    vector <string> draw(int n)
    {
        for (int i = 0; i < MAX_SIZE; ++i) {
            for (int j = 0; j < MAX_SIZE; ++j) {
                g_arr[i][j] = ' ';
            }
        }
        for (int i = 0; i < n; i += 2) {
            printSquare(i, n- 2*i);
        }

        vector<string> out;
        for (int i = 0; i < n; i++) {
            out.push_back(string(g_arr[i], n));
        }
        /*
        for (int i = 0; i < MAX_SIZE; ++i) {
            for (int j = 0; j < MAX_SIZE; ++j) {
                cout<<g_arr[i][j];
            }
            cout << "\n";
        }
        */
        
        return out;
    }
};
