
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
//typedef unsigned int UI;
typedef int UI;
class OrderedSuperString
{
public:

    int findOverlap(string source, string toFind, int posToStart) {
        int res = -1;
        for (int i = posToStart; i < source.size(); i++) {
            bool found = true;
            for (int j = 0; j < toFind.size(); j++ ) {
                if ( i+j == source.size()) {
                    found = true;
                    break;
                }
                if (source[i+j] != toFind[j]) {
                    found = false;
                    break;
                }
            }

            if(found) {
                res = i;
                break;
            }
        }

        return res;
    } 
	int getLength(vector <string> words)
	{
        string s = words[0];
        UI pos = 0;
        //printf("pos = %d\n", pos);
        FOR(i, 1, words.size()) {
            UI nextPos = findOverlap(s, words[i], pos); 
            //printf("Pos=%d, nextPos = %d\n",pos, nextPos);
            if (nextPos == -1) {
                //printf("No overlap for s=%s and word=%s\n", s.c_str(), words[i].c_str());
                pos = s.size();
                //pos += words[i].size();
                s += words[i];
            } else {
                pos = nextPos;
                UI matchLen = s.size() - pos;
                //printf("Pos=%d, matchLen=%d, s=%s, words=%s \n", pos, matchLen, s.c_str(), words[i].c_str());
                if (words[i].size() > matchLen) {
                    s += words[i].substr(matchLen);
                }
            }
        }
        //printf("Answer = %d", s.size());
		return s.size();
	}
};

