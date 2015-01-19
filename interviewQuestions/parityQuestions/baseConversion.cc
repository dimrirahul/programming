#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;
typedef unsigned long long UL;
class BaseConversion {
    public:
        int getValueOfChar(int c) {
            if (c >= '0' && c <= '9') return c - '0';
            return c - 'A' + 10;
        }

        int getCharFromInt(int v) {
            if (v <= 9 && v >= 0) return '0' + v;
            return 'A' + v - 10;
        }
        string convertBase(string num, int b1, int b2) {
            int sum = 0;
            for (int i = 0; i < num.size(); i++) {
                sum +=  ((int) pow(b1, i)) * getValueOfChar(num[num.size() -i -1]);
            }

            string res;
            int j = 30;
            cout << "Sum = " << sum << "\n";
            while ( (int) pow(b2, j) < 0 || sum < (int)pow(b2, j)) j--;
            while ( sum > 0) {
                int expValue = (int) pow(b2, j);
                int q = sum / expValue;
                sum -= (q * expValue);
                j--;
                res += (char) getCharFromInt(q);
            }

            while (j >= 0) {
                res += '0';
                j--;
            }

            return res;

        }

        
};

BaseConversion es;
int main(int argc, char **argv) {
    string s1("10110101011");
    cout << "Converting " << s1 << "base 2 to base 16 " << es.textBookConvertBase(s1, 2, 16) << "\n";
    return 0;
}
