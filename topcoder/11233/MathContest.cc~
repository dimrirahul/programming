
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

class MathContest
{
public:
    string m_str;

    void setStr(string ballSequence, int reps) {
        stringstream ss;
        for (int i = 0; i < reps; i++) {
            ss << ballSequence;
        }
        m_str = ss.str();
    }

    void printMessage(string msg, int start, int end, bool reverse, bool colorFlipped) {
        /*
       cout << msg;
       printf("new values start=%d, end=%d, reverse=%d, colorFlipped=%d\n", start, end, reverse, colorFlipped);
       */
    }


	int countBlack(string bs, int repetitions)
	{
        setStr(bs, repetitions);   
        int start = 0; int end = m_str.size();
        bool reverse = false; bool colorFlipped = false;

        int balls = 0;
        while (start < end) {
        //    printf("Start = %d, end = %d\n", start, end);
            if (!reverse) {
                if ((!colorFlipped && m_str[start] == 'W') || (colorFlipped && m_str[start] == 'B')) {
                    reverse = !reverse;
                    start++;
                    printMessage(string("WhiteBall matched in correct dir"), start, end, reverse, colorFlipped);
                } else {
                    balls++;
                    start++;
                    colorFlipped = !colorFlipped;
                    printMessage(string("Blackball matched in correct dir"), start, end, reverse, colorFlipped);
                }
            } else  {
                if ((!colorFlipped && m_str[end - 1] == 'W') || (colorFlipped && m_str[end -1] == 'B')) {
                    reverse = !reverse;
                    end--;
                    printMessage(string("Whiteball matched in reverse dir"), start, end, reverse, colorFlipped);
                } else {
                    balls++;
                    end--;
                    colorFlipped = !colorFlipped;
                    printMessage(string("Blackball matched in reverse dir"), start, end, reverse, colorFlipped);
                }
            }
        }
		return balls; 
	}
};

