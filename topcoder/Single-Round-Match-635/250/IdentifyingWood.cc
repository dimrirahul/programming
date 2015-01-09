
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

class IdentifyingWood
{
public:

    bool isPresent(string& longer, string& shorter, int longPos, int shortPos) {
        if (shortPos == shorter.size()) {
            return true;
        }

        if (longPos == longer.size()) {
            return false;
        }
        //printf("Entering function\n");
        if ((longer.size() - longPos) < (shorter.size() - shortPos)) {
            return false;
        }

        bool found = false;

        int j = shortPos;
        for (int i = longPos; i < longer.size(); i++) {
            //printf("i = %d, j = %d, charAt[i]=%c charAt[j]=%c\n", i, j, longer[i], shorter[j]);
            if (longer[i] == shorter[j]) {
                bool res = isPresent(longer, shorter, i+1, j+1);
                //printf("Result = %d\n", res);
                if (res) {
                    found = true;
                    break;
                }
            }
        }


        return found;
    }

	string check(string s, string t)
	{
		return (isPresent(s, t, 0, 0)) ? "Yep, it's wood." : "Nope.";
	}
};
