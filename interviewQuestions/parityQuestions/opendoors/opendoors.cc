#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int MAX_DOORS = 501;

class OpenDoorCalculator {
    public:
        int doors[MAX_DOORS];
        
        int calculateStuff() {
            memset(doors, 0, sizeof(int) * MAX_DOORS);
            int i = 1;
            while ( i <= MAX_DOORS ) {
                for (int j = 1; i * j <= MAX_DOORS; j++) {
                    doors[i*j]++;
                }
                i = i << 1;
            }
            
            int res = 0;
            for ( i = 1; i <= MAX_DOORS; i++) {
                if (doors[i] % 2 == 1) res++;
            }
            
            return res;
        }
 };
 
 OpenDoorCalculator odc;
 int main(int argc, char **argv) {
    printf("%d\n", odc.calculateStuff());
    return 0;
 }
