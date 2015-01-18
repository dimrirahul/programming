#include <iostream>
#include <cstdio>

using namespace std;

class FastDiv {
    public:
        int divide(int num, int den) {
            if (num == den) return 1;
            if (num == 0) return 0;
            int max2pow = 0;
            while ( (den << max2pow) <= num) max2pow++;
            max2pow--;
            return (1 << max2pow) + divide(num - (den << max2pow), den);
        }

        void start() {
            int num, den;
            scanf("%d %d\n", &num, &den);
            cout << divide(num, den);
        }
};

FastDiv fd;
int main(int argc, char **Argv) {
    fd.start();
    return 0;
}
