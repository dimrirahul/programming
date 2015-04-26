#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long UL;
typedef unsigned int UI;
typedef bitset<64> BS;
class ParityHelper {

public:
    unordered_map <UI, int> parityMap;
    const UI MASK = 0xFFFF; 
    void initializeParityMap() {
       for (int i = 0; i < (1 << 16); i++) {
           parityMap[i] = calcParity(i);
           if (parityMap[i] != getParityFromLib(i, false)) {
                cout << "Base Parity Calculator is fucked: " << i << "\n";
           }
       }
    }
        
    int calcParity(int n) {
      int p = 0;
       while (n > 0) {
            p ^= 1;
            n = n & (n-1);
       }
       return p;
    }
    int calcParity32(UI v) {
       int res = parityMap[v & MASK];
       res ^= parityMap[(v >> 16)];
       if (res != getParityFromLib(v, false)) {
            cout << "32 bit calculation fucked up: " << v << "\n";
       }
       return res;
    }
    int calcParity64(UL v) {
       int res = calcParity32((UI)(v >> 32));
       res ^= calcParity32((UI)(v));
       return res;
    }
    
    UL generate64BitRandom() {
       UL res = rand();
       res = res << 32;
       res |= rand();
       return res;
    }
    
    int getParityFromLib(UL inp, bool verbose=true) {
       bitset<64> b(inp);
       if (verbose) {
            cout << "Generated Random number = " << b.to_string() << "\n";
            cout << "Count 1 = " << b.count() << "Parity = " << b.count() % 2 << "\n";
       }
       return b.count() % 2;
    }
    /**
    * Q1.
    */
    void test64BitParity() {
        initializeParityMap();
        for (int i = 0; i < 10; i++) {
            cout << "TestCase: " << i << "\n";
            UL inp = generate64BitRandom();
            UL myAns = calcParity64(inp);
            if (myAns != getParityFromLib(inp, false)) {
                cout << "Wrong answer \n";
                cout << "My ans = " << calcParity64(inp) << "Actual = " << getParityFromLib(inp, false) << "\n";
            }
        }
    }
    /**
    * Q2.
    */
    bool isSet(UL v, int pos) {
       UL one = 1;
       bool res = (v & (one << pos)) != 0;
        return res;
    }
    UL setBit(UL v, int pos) {
        UL one = 1;
        return v | (one << pos);
    }
    UL flipBit(UL v, int pos) {
        UL one = 1;
        return v ^ (one << pos);
    }
    UL flipBits(UL inp, int i, int j) {
        if (isSet(inp, i) ^ isSet(inp, j)) {
            return flipBit(flipBit(inp, i), j);
        }
        return inp;
    }
    UL libFlipBits(UL inp, int i, int j) {
        bitset<64> b(inp);
        if (b.test(i) ^ b.test(j)) {
            b.flip(i);
            b.flip(j);
            return b.to_ullong();
        } else {
            return inp;
        }
    }
    
    void testQ2() {
        for (int i = 0; i < 10; i++) {
            UL inp = generate64BitRandom();
            int posi = rand() % 64;
            int posj = rand() % 64;
            UL myAns = flipBits(inp, posi, posj);
            UL libAns = libFlipBits(inp, posi, posj);
            if (myAns != libAns) {
                cout << "Answers do not match my ans=" << myAns << " libAns=" << libAns << "\n";
                cout << "inp:" << (bitset<64>(inp)).to_string() << " Posi = " << posi << " Posj = " << posj << "\n";
                cout << "Me :" << (bitset<64>(myAns)).to_string() << "\n";
                cout << "Lib:" << (bitset<64>(libAns)).to_string() << "\n"; 
            }
         }
    }
    
    /**
    * Q3 reverse bits.
    */
    UL reverseBits(UL inp) {
        UL res = 0;
        for (int i = 0; i < 16; i++) {
            if (isSet(inp, i)) res = setBit(res, 15-i);
        }
        return res;
    }
    bool areReverse(UL left, UL right) {
        BS lbs(left);
        BS rbs(right);
        string sl = lbs.to_string();
        string sr = rbs.to_string();
        reverse(sl.begin(), sl.end());
        bool res =  sl == sr;
        if (!res) {
            cout << "Left:" << sl << "\n";
            cout << "Righ:" << sr << "\n";
        }
        return res;
    }
    UL reverseBitsUsingHashing(UL inp) {
        UL l1 = parityMap[inp & MASK];
        UL l2 = parityMap[(inp >> 16) & MASK];
        UL l3 = parityMap[(inp >> 32) & MASK];
        UL l4 = parityMap[(inp >> 48) & MASK];
        return (l1 << 48) | (l2 << 32) | (l3 << 16) | l4 ;
    }
    void testQ3() {
        parityMap.clear();
        for (int i = 0; i < (1 << 16); i++) {
            parityMap[i] = (int)reverseBits(i);
        }
        for (int i = 0; i < 10; i++) {
            UL inp = generate64BitRandom();
            UL myAns = reverseBitsUsingHashing(inp);
            if (!areReverse(inp, myAns)) {
                cout << "Not correct \nInp:" << inp << "\nmyA:" << myAns << "\n";
            }
        }
    }
    
    UL getEqW(UL inp) {
        for (int i = 0; i < 63; i++) {
            if (isSet(inp, i) ^ isSet(inp, i+1)) {
                inp = flipBit(inp, i);
                inp = flipBit(inp, i+1);
                return inp;
             }
         }
         throw invalid_argument("Shits fucked up");
    }
    void testQ4() {
        for (int i = 0; i < 10; i++) {
            UL inp = generate64BitRandom();
            UL myAns = getEqW(inp);
            cout << "myAns:" << myAns << " input:" << inp << "\n";
        }
    }
    
    int getMsbPos(UL inp) {
        int res = 0;
        while (inp > 0) {
            res++;
            inp = inp >> 1;
        }
        cout << "MsbPos = " << res << "\n";
        return res;
    }
    UL add(UL v1, UL v2) {
        UL res = 0;
        UI carry = 0;
        UL less = min(v1, v2);
        UL more = max(v1, v2);
        int msbPos = getMsbPos(less);
        for (int i = 0; i < msbPos + 2; i++) {
            //cout << "Loop:" << i << " carry:" << carry << " more:" << isSet(more, i) << " less:" << isSet(less, i);
            if (carry ^ isSet(more, i) ^ isSet(less, i)) {
                res = setBit(res, i);
            }
            if ((carry && isSet(more, i)) || (carry && isSet(less, i)) || (isSet(less, i) && isSet(more, i))) {
                carry = 1;
            } else {
                carry = 0;
            }
            //cout << " Res = " << res << "\n";
        }
        return res;
    }
    void testQ5() {
        for (int i = 0; i < 10; i++) {
            UL v1 = rand();
            UL v2 = rand();
            UL res = add(v1, v2);
            if (res != ((UL)v1 + v2)) {
                cout << "Sums do not match expected:" << v1 + v2 << " Actual:" << res << "\n";
            }
        }
   }
            
};

ParityHelper ph;
int main(int argc, char **argv) {
    //ph.test64BitParity();
    //ph.testQ2();
    ph.testQ5();
    return 0;
}
