#include <iostream>
#include <cstdio>

using namespace std;
typedef unsigned long long UL;
class ExponentialSquarer {
    public:
        UL pow(UL x, int y) {
            if (y == 0) return (UL)1;
            if (y == 1) return x;
            if (y % 2 == 0) return pow(x * x, y/2);
            return x * pow(x * x, y/2);
        }
        
};

ExponentialSquarer es;
int main(int argc, char **argv) {
    printf("Ans=%llu\n", es.pow(5, 9));
}
