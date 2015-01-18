#ifndef _PARITY_H
#define _PARITY_H

#include <cstdio>
#include <vector>
#include <string>

using namespace std;
typedef unsigned long long UL;
typedef unsigned int UI;
const UI TABLE_SIZE = 1 << 16;
const int _int16 = 16;
class ParityFinder {
    public:
        UI table[TABLE_SIZE];
        void isParity(vector<UL> v) {
            bool res = false;
            for (int j = 0; j < v.size(); j++) {
                for (int i = 0 ; i < sizeof(UL); i++) {
                    if ( v[j] & (1 << i)) {
                        res = (!res);
                    }
                }
            }
            printf(res ? "PARITY": "NOT PARITY");
        }

        UL bitswapper(UL num, int pos1, int pos2) {
            printf("Pos%d=%d, pos%d=%d\n", pos1, (num & (1 << pos1)) > 0, pos2, (num & (1 << pos2)) > 0);

            bool bit1 = (num & (1 << pos1)) > 0;
            bool bit2 = (num & (1 << pos2)) > 0;
            if (bit1 ^ bit2) {
                if (num & (1 << pos1)) {
                    num = num & (~(1 << pos1));    
                    num = num | (1 << pos2);
                } else {
                    num = num | (1 << pos1);
                    num = num & (~(1<<pos2));
                }
            }
            return num; 
        }

        UL numberSwapper(UL num) {
            for (int i = 0; i < (sizeof(UI)/2); i++) {
                num = bitswapper(num, i, (sizeof(UI) - i - 1));
            }
            return num;
        }

        int getMsb(UI num) {
            int pos = _int16 -1;
            while ( ((1 << pos) & num) == 0) {
                pos--;
            }
            return pos;
        }
        UI getReversedNumber(UI i) {
            if (i == 0) return i;
            if (i == 1) return (1 << (_int16 - 1));
            int msb = getMsb(i);
            UI res = 0;
            res = table[i ^ (1 << msb)];
            res |= (1 << (_int16 -1 - msb));
            return res;
        }

        void buildReverseTable(UI range = TABLE_SIZE) {
            for (UI i = 0; i < range; i++) {
                table[i] = getReversedNumber(i);
            }
        }

        string getNumberAsString(UI num) {
            string s;
            for (int i = 15; i >= 0; i--) {
                s += (num & (1 << i )) ? '1' : '0';
            }
            return s;
        }

        void printTable(UI range = TABLE_SIZE) {
            for (UI i = 0; i < range; i++) {
                printf("number = %d in binary = %s, its reverse = %s\n", i, getNumberAsString(i).c_str(), getNumberAsString(table[i]).c_str());
            }
        }
        
        UL optimizedNumberSwapper() {
            buildReverseTable();
            printTable();
            return 0;
        }

        int getMinWeight(int n1) {
            bool found = false;
            int pos = 1;
            for (; pos < 32; pos++) {
                int bit2 = (n1 & 1 << pos) > 0;
                int bit1 = (n1 & 1 << (pos - 1)) > 0;
                if( bit1 ^ bit2){
                    break;
                }
            }

            printf("Pos = %d\n", pos);

            return bitswapper(n1, pos, pos-1);
        }

        int addPair(int n1, int n2) {
            bool carry = false;
            int res = 0;
            for (int i = 0; i < 31; i++) {
                int b1 = (n1 & (1 << i)) > 0;
                int b2 = (n2 & (1 << i)) > 0;

                int bres = (carry ^ b1 ^ b2);
                if (bres >  0) {
                    res |= (1 << i);
                }
                if (!carry && b1 && b2) {
                    carry = true;
                    continue;
                }
                if (carry && !b1 && !b2) {
                    carry = false;
                    continue;
                }
            }
            return res;
        }

        int multXy(int n1, int n2) {
            if (n2 == 1) return n1;
            if ( n2 %2 == 0) {
                n1 = n1 << 1;
                n2 = n2 / 2;
                return multXy(n1, n2);
            } else {
                return addPair(multXy(n1, n2/2 + 1), n1);
            }
        }

        int substractXy(int x, int y) {
            int msb = 30;
            int mask = (2 << 31) -1; 
            for (; msb >= 0; msb--) {
                if ((x & (1 << msb)) > 0) {
                    break;
                }
                mask ^= (1 << msb);
            }
            
            y = (~y);
            y &= mask;
            y = addPair(y, 1);
            x = addPair(x, y);
            x &= mask;
            return x;
        }

        int div(int x, int y) {
            if (x < y) return x;
            return div(substractXy(x, y), y);
        }


};
#endif //_PARITY_H
