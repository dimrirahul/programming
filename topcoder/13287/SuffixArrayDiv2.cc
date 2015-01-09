
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
#include <string.h>

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()

using namespace std;

// }}}


typedef vector<int> IV;

class Sorter { 
    public:
        const char *ptr;
        bool operator() (int lhs, int rhs) {
           return strcmp(ptr + lhs, ptr + rhs) < 0 ? true : false;
        }
        Sorter (string &s) {
            ptr = s.c_str();
        }
};

class SuffixArrayDiv2
{
public:

    /*
    void createSubscriptArray(string &s, IV &out) {
        out.clear();
        for( unsigned int i = 0; i <s.size(); i++) {
            out.push_back(i);
        }
        Sorter sorter(s);
        sort(out.begin(), out.end(), sorter);
        for( unsigned int i = 0; i <s.size(); i++) {
            cout << out[i] << " "; 
        }
    }
    */
        
    int findFirstNotA(string& s) {
        int i = 0;
        while ( i < s.size() ) {
            if (s[i] == 'a') {
                i++;
            } else {
                break;
            }
        }
        return i;
    }



	string smallerOne(string s)
	{
        IV subscript;
        //createSubscriptArray(s, subscript);
        int pos = findFirstNotA(s);
        if (pos == s.size()) {
            return "Does not exist";
        } else {
            return "Exists";
        }
		//return string();
	}
};

