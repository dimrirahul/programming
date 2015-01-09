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
class CLASSNAME {
public:
    int readNextInteger() {
        int c = getchar();
        bool isLTZ = false;
        while (!(c >= '0' && c <= '9')) { 
            if (c == '-') isLTZ = true;
            c = getchar();
        }
        int sum = 0;
        while ( c >= '0' && c <= '9') {
            sum *= 10;
            sum += c - '0';
            c = getchar();
        }
        if (isLTZ) sum *= -1;
       // printf("read integer = %d\n", sum);
        return sum;
    }

    void doStuff(int s) {
    }

    void start() {
        int b;
        //Update testcase inputs
        scanf("%d\n", &b);
        while (!(b == 0)) {
            doStuff(b);
            scanf("%d\n", &b);
        }
    }    
};

CLASSNAME t;

int main(int argc, char **argv) {
    t.start();
    return 0;
}
