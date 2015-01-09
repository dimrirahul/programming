
// {{{ Boilerplate Code <--------------------------------------------------
// vim:filetype=cpp:foldmethod=marker:foldmarker={{{,}}}

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()

using namespace std;

// }}}

typedef  int UI;
vector<UI> seive;
class StrongPrimePower
{
    public:
        int binSearch(vector<UI>& v, int elem) {
            int start = 0;
            int end = v.size();
            if (elem < v[start] || elem > v[end-1]) {
                return -1;
            }
            while (start < end) {
                int mid = (start + end )/2;
                if (v[mid] == elem) {
                    return mid;
                }else if(v[mid] > elem) {
                    end = mid;
                }else {
                    start = mid +1;
                }
            }
            return -1;
        }
        double convertStringToDouble(string s) {
            double res = 0;
            REP(i, s.size()) {
                res = res*10 + s[i] - '0';
            }
            return res;
        }

        void populateSeive(UI lim) {
            seive.push_back(2);
            for (UI i = 3; i <= lim; i+= 2) {
                seive.push_back(i);
            }

            vector<UI>::iterator it = seive.begin();
            it++;
            for (; it != seive.end(); it++) {
                for (int i = 3 * (*it); i <= lim; i += *it) {
                    int index = binSearch(seive, i);
                    if (index != -1) {
                        seive.erase(seive.begin() + index);
                    }
                }
            }
        }

        void printSeive() {
            REP(i, seive.size()) {
                cout << seive[i] << " ";
            }
            cout << "\n";
        }

        bool isDivisible(double num, UI divisor) {
            cout << "Divide operation  = " << num/divisor << "\n";
            return fmod(num, divisor) < 1e-9;
        }
        vector <int> baseAndExponent(string n)
        {
            double num = convertStringToDouble(n);
            UI lim = (UI) sqrt(num);
            populateSeive(lim);
            printSeive();
            cout << "Num = " << num;
            cout << "\n";

            int index = 0;
            REP(i, seive.size()) {
                index = i;
                if (isDivisible(num, seive[i])) {
                    break;
                }
            }

            cout << "Index = " << index << "\n";

            int q = 0;
            int iter = 0;
            while (true && iter < 100) {
                q++;
                cout << "Res = " << (num/pow(seive[index], q)) << "\n";
                if ( (num/pow(seive[index], q )) < 1+1e-9) {
                    break;
                }
                iter++;
            }

            if (q == 1) {
                return vector<int>();
            } else {
                vector<int> out;
                out.push_back(q);
                out.push_back(seive[index]);
                return out;
            }
            return vector <int>();
        }
};

