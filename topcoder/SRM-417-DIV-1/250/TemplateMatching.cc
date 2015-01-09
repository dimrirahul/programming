
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

class TemplateMatching
{
public:



    int findPrefixScore(string prefix, string text) {
        int score = 0; int len = 1;
        while (len <= min(text.size(), prefix.size())) {
            if (prefix.substr(prefix.size()- len) == text.substr(0, len)) {
                //cout << " PrefixString = " <<  prefix.substr(prefix.size() -len) <<  ", textString = " << text.substr(0, len) << ", Score= " << len << "\n";
                score = len;
            }
            len++;
        }
        return score;
    }
    string bestMatch(string text, string prefix, string suffix)
    {

        //cout << "Score =" << findPrefixScore(string("awesome"), string("something"));
        int optSuffixScore = 0; int optPrefixScore = 0; string opts;
        for (int i = 0; i < 26; i++) opts += 'z'; 
        for (int i = 0; i < text.size(); i++) {
            for (int j = i; j < text.size(); j++) {
                string s;
                for (int k = i; k <= j; k++) s+=text[k];
                int prefixScore = findPrefixScore(prefix, s);
                int suffixScore = findPrefixScore(s, suffix);

                if (prefixScore + suffixScore > optSuffixScore + optPrefixScore) {
                    opts = s;
                    optSuffixScore = suffixScore;
                    optPrefixScore = prefixScore;
                } else if (prefixScore + suffixScore == optSuffixScore + optPrefixScore) {
                    if (prefixScore > optPrefixScore) {
                        opts = s;
                        optSuffixScore = suffixScore;
                        optPrefixScore = prefixScore;
                    }else if(prefixScore == optPrefixScore) {
                        opts = min (s, opts);
                    }
                }
            }
        }
        return opts;
    }
};

