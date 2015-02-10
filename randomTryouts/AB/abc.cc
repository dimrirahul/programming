#include <iostream>
#include <cstdio>

using namespace std;
class Prod3 {
    public:
        Prod3(){
        }
        void getMax(int r, int s) {
            int mx, my, mz;
            mx = my = mz = -1;
            int maxV = 0;
            int t;
            for (int i = 0; i <= r; i++) {
                for (int j = 0; j <= r; j++) {
                    for (int k = 0; k <= r; k++) {
                        if (  (i + j + k <=s ) &&(t = (i * j) + (i * k) + (j * k)) > maxV ) {
                            maxV = t;
                            mx = i;
                            my = j;
                            mz = k;

                        }
                    }
                }
            }
            cout << mx << " " << my << " " << mz << "\n";
        }
};

Prod3 p;
int main(int argc, char **Argv) {
    p.getMax(100, 90);
    return 0;
}
