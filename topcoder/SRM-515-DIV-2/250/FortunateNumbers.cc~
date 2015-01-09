
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

class FortunateNumbers
{
public:
	int getLength(int a) {
		int len = 1;
		while(a / 10 > 0) {
			len++;
			a = a/10;

		}
		return len;
	}

	int digitAtPos(int a, int pos) {
		return (a / (int) pow(10, pos)) % 10;
	}

	bool isFortunate(int a) {
		int len = getLength(a);

        cout << "Len = " << len << "\n";
		REP(i, len) {
			int d = digitAtPos(a, i);
            cout << "digit = " << d << "\n";
			if (d != 5 && d!= 8) {
				return false;
			}
		}
		return true;
	}

	int getFortunate(vector <int> a, vector <int> b, vector <int> c)
	{
		set <int>s;
		for (int i = 0; i < a.size(); i++) {
			REP(j, b.size()) {
				REP(k, c.size()) {
					if (isFortunate(a[i] + b[j] + c[k])) {	
						s.insert(a[i] + b[j] + c[k]);
					}
				}
			}
		}

        cout << "Fortunate = " <<isFortunate(58);

		for (set<int>::const_iterator it = s.begin(); it != s.end(); it++) {
			cout << *it<< "\n";
		}
		return s.size();
	}
};

