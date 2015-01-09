
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


typedef set<int> SI;
typedef vector<int> VI;
typedef stack<int> StackInt;
const int MAX_SIZE = 600;

/**
 * Global array to hold votes.
 */
int g_voteArray[MAX_SIZE];

class Comparator {
    public:
        bool operator()(int a, int b) {
            return g_voteArray[a] > g_voteArray[b];
        }
};

typedef priority_queue<int, VI, Comparator> PQ;


class MafiaGame
{
public:

    
    void clearVoteArray() {
        for (int i = 0; i < MAX_SIZE; i++) {
            g_voteArray[i] = 0;
        }
    }

    int updateFirmDescisions(SI &vs, VI& d ) {
        int match = 0;
        clearVoteArray();
        for (VI::const_iterator it = d.begin(); it != d.end(); it++) {
            if (vs.count(*it) == 1) {
                match++;
                g_voteArray[*it]++;
            }
        }
        return match;
    }
    
    void createPQ(SI& vs, PQ& pq) {
        while (!pq.empty()) {
            pq.pop();
        }
        for (SI::const_iterator it = vs.begin(); it != vs.end(); it++) {
            pq.push(*it);
        }
    }

    void updateVS(SI &vs, PQ &q) {
        vs.clear();
        StackInt intStack;
        while (!q.empty()) {
            intStack.push(q.top());
            q.pop();
        }

        int top = intStack.top();
        intStack.pop();
        vs.insert(top);
        while (!intStack.empty() && g_voteArray[intStack.top()] == g_voteArray[top]) {
            vs.insert(intStack.top());
            intStack.pop();
        }
    }

    void printSnapshot(SI &vs, PQ &pq, int n) {
        for (int i = 0; i < n ; i++) {
            cout << g_voteArray[i] << " ";
        }
        cout << "\n";

        cout << "Set = \n";
        for (SI::const_iterator it = vs.begin(); it != vs.end(); it++) {
            cout << *it << " ";
        }

        cout << "\n PQ top = " << pq.top() << "\n";
    
    }

    bool areAllVotesSame(SI& vs) {
        SI::const_iterator it = vs.begin();
        int vote = g_voteArray[*it];
        it++;
        bool retValue = true;
        while( it != vs.end()) {
            if (g_voteArray[*it] != vote) {
                retValue = false;
                break;
            }
            it++;
        }
        return retValue;
    }
    
	double probabilityToLose(int N, vector <int> decisions)
	{
        SI vs;
        PQ pq;
        for (int i = 0; i < N; i++) {
            vs.insert(i);
        }
        int prevCount = vs.size();
        double retValue = 0;
        bool loop = true;
        bool votesEqual = false;
        int  countOfPeople ;
        while (loop) {
            int voted = updateFirmDescisions(vs, decisions);
            int pending = N - voted;
            if (areAllVotesSame(vs)) {
                if (!votesEqual) {
                    votesEqual = true;
                    countOfPeople = vs.size();
                }
            }
            createPQ(vs, pq);
            printSnapshot(vs, pq, N);
            while (pending != 0) {
                int index = pq.top();
                pq.pop();
                g_voteArray[index]++;
                pq.push(index);
                pending--;
            }

            updateVS(vs, pq);
            printSnapshot(vs, pq, N);
            if (prevCount == vs.size()) {
                retValue = 0l;
                loop = false;
            }

            if (vs.size() == 1) {
                if (votesEqual) {
                    return (double)1/countOfPeople;
                } else {
                    retValue = 1l;
                }
                loop = false;
            }

            prevCount = vs.size();
        }

		return retValue; 
	}
};

