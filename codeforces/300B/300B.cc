#include<bits/stdc++.h>

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define FORU(I,A,B) for(unsigned int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define REPU(I,N)   FORU(I,0,N)
#define ALL(A)     (A).begin(), (A).end()

using namespace std;

typedef pair <int, int> PI;
typedef vector <int> VI;
typedef vector <string> VS;

typedef long long LL;
const bool dbg = false;
class xx300B {
    public:
        string convertNumToString(int n) {
            stringstream ss;
            ss << n;
            return ss.str();
        }

        pair<int, string> highBit(int n) {
            string numAsStr = convertNumToString(n);
            int highBit = -1;
            REP(i, numAsStr.size()) {
                if (numAsStr[i] > '1') {
                    highBit = i;
                    break;
                }
            }
            return make_pair(highBit, numAsStr);
        }

        int stringToNum(string s) {
            int res = 0;
            reverse(s.begin(), s.end());
            for (int i = s.size() - 1; i >= 0; i--) {
                res *= 10;
                res += s[i] - '0';
            }
            return res;
        }

        string formString(string inp, int hb) {
            string res;
            REP(i, inp.size()) {
                if (i < hb) {
                    res.push_back(inp[i]);
                } else {
                    res.push_back('1');
                }
            }
            return res;
        }


        VI solve(int n) {
            VI res;
            if (dbg) cout << "Solving for N = " << n << "\n";
            pair <int, string> p = highBit(n);
            int hb = p.first;
            if (hb == -1) {
                res.push_back(n);
                return res;
            }
            string maxNumAsStr = formString(p.second, hb);
            int maxNum = stringToNum(maxNumAsStr);
            if (dbg) cout << "MaxNumAsStr = " << maxNumAsStr << " HB = " << hb << " MaxNum = " << maxNum << "\n";
            if (dbg && n - maxNum < 0 ) cout << "Fucked \n";
            res.push_back(maxNum);
            VI recRes = solve(n - maxNum);
            recRes.push_back(maxNum);
            return recRes;
        }
        void start() {
            int N;
            cin >> N;
            VI res = solve(N);
            cout << res.size() << "\n";
            REP(i, res.size()) {
                cout << res[i] << " ";
            }
            cout << "\n";
        }    
};

xx300B t;
void test();
int main(int argc, char **argv) {
    //t.start();
    test();
    return 0;
}

bool validate(VI v, int num) {
    int res = 0;
    for (int i = 0; i < v.size(); i++) {
        res += v[i];
        cout << v[i] << " ";
    }
    cout << "\n===============\n";
    return res == num;
}
void test() {
    for (int i = 0; i < 100; i++) {
        int num = rand();
        num %= (int)(1e6);
        VI res = t.solve(num);
        if(!validate(res, num)) {
            cout << "Wrong Ans for input " << num << "\n";
        } else {
            cout << "Success for " << num << "\n";
        }
    }
}
