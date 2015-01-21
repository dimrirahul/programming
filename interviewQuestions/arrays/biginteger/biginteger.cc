#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstring>

using namespace std;
class BigInteger {
    public:
        vector<int> addOne(vector<int>& v) {
            int carry = 1;
            vector<int> res;
            for (int i = 0; i < v.size(); i++) {
                int n = carry + v[i];
                if (n > 9) {
                    carry = 1;
                    n -= 10;
                } else {
                    carry = 0;
                }
                res.push_back(n);
            }
            if (carry) res.push_back(1);
            return res;
        }

        string multiply(string s1, string s2) {

            bool isPositive = true;
            if (s1[0] == '-') {
                isPositive = !isPositive;
                s1 = s1.substr(1);
            }

            if (s2[0] == '-') {
                isPositive = !isPositive;
                s2 = s2.substr(1);
            }

            reverse(s1.begin(), s1.end());
            reverse(s2.begin(), s2.end());
            int res[200];
            memset(res, 0, sizeof (int) * 200);
            
            for (int i = 0; i < s1.size(); i++) {
                for (int j = 0; j < s2.size(); j++) {
                    res[i + j] += (s1[i] - '0') * (s2[j] - '0');
                    res[i + j + 1] += res[i + j]/10;
                    res[i +j] %= 10;
                }
            }

            stringstream ss;
            bool isFirstNum = false;
            for (int i = 199; i >= 0; i--) {
                if (res[i] != 0) isFirstNum = true;
                if (isFirstNum) {
                    ss << res[i];
                }
            }

            string out;
            if(!isPositive) {
                out += '-';
            }
            out += ss.str();
            return out;
        }
};

vector<int> getVector() {
    int p, t;
    scanf("%d\n", &p);
    vector<int> res;
    for (int i = 0; i < p; i++) {
        scanf("%d ", &t);
        res.push_back(t);
    }
    reverse(res.begin(), res.end());
    return res;
}
BigInteger bi;
int main(int argc, char **Argv) {
    /*
    vector<int> input = getVector();
    for (int i = 0; i < input.size(); i++) printf("%d", input[i]);
    printf("\n");
    vector<int> res = bi.addOne(input);
    for (int i = res.size()-1; i >= 0; i--) printf("%d", res[i]);
    printf("\n");
    */
    cout << bi.multiply(string("193707721"), string("-761838257287"));
    return 0;
}
