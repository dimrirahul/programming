
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

typedef vector<int> VI;
typedef vector<string> VS;
typedef pair <int, int> PI;
class Node {
    public:
        int type, value, time;
        Node(int typeP, int valueP,int timeP) {
            type = typeP;
            value = valueP;
            time = timeP;
        }

        Node (const Node& other){
            type = other.type;
            value = other.value;
            time = other.time;
        }

        bool operator<(Node other) const{
            if (value != other.value) {
             return !(value < other.value);
            }
            return !(time < other.time);
        }

        PI getRange() {
            return make_pair(time -value, time);
        }

};
typedef vector<Node> VN;
class Undo
{

    public:


        PI parseCommand(string s) {
            PI ret;
            if (s.substr(0, 4) == string("type") )  {
                ret = make_pair(1, s[5]);
            } else {
                ret = make_pair(2, atoi(s.c_str() + 5));
            }
            return ret;
        }
        string getText(vector <string> commands, vector <int> time)
        {
            vector<Node> comQ, undoQ;
            REP(i, commands.size()) {
                PI p = parseCommand(commands[i]);
                Node n(p.first, p.second, time[i]);
                if (n.type == 2) {
                    undoQ.push_back(n);
                } 
                comQ.push_back(n);
            }

            set<int> invalidSet;
            for(VN::reverse_iterator it = undoQ.rbegin(); it != undoQ.rend(); it++){
                if (invalidSet.count(it->time) != 0) continue;
                PI range = it->getRange();
                printf("range.first = %d, range.second=%d\n", range.first, range.second);
                REP(j, comQ.size()) {
                    if ( comQ[j].time >= range.first && comQ[j].time <= range.second ) {
                        invalidSet.insert(comQ[j].time);
                    }
                }
            }

            string res = "";
            REP(i, comQ.size()) {
                if (invalidSet.count(comQ[i].time) == 0) {
                    res += (char) comQ[i].value;  
                }
            }
            return res;
        }
};

