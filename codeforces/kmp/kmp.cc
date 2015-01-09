#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
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
#include <string>
#include <utility>
#include <vector>
#include <stdio.h>


#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()

using namespace std;

typedef pair <int, int> PI;
typedef vector <int> VI;
typedef vector <string> VS;

typedef long long LL;
const int PATTERN_SIZE = 100;
const int TEXT_SIZE = 100 * PATTERN_SIZE;
class kmp {
public:
    char pattern[PATTERN_SIZE];
    char text[TEXT_SIZE];
    int lookupTable[PATTERN_SIZE];
    int patternLen;
    int textLen;

    void prepareTable() {
        patternLen = strlen(pattern);
        
    }

    void start() {
        scanf("%s\n", pattern);
        scanf("%s\n", text);
        prepareTable();
        match();
    }    
};

kmp t;

int main(int argc, char **argv) {
    t.start();
    return 0;
}
