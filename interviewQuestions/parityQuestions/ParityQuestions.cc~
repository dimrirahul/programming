#ifndef _PARITY_H
#define _PARITY_H

typedef unsigned long long UL;
class ParityFinder {
    public:
        void isParity(UL n) {
            bool res = false;
            for (int i = 0 ; i < sizeof(UL); i++) {
                if ( 1 << i ) {
                    res = (!res);
                }
            }
            printf(res ? "PARITY", "NOT PARITY");
        
        }
};
#endif //_PARITY_H
