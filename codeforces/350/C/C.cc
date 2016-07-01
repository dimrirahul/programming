#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;
using PI = pair<int, int>;
const int MX_SZ = 200000 + 10;
using VPI = vector<PI>;
const bool dbg = true;

struct C {

    unordered_map<int, int> _peopleByLang;

    int _n;
    int _m;
    void printPi(const PI& pi) {
        cout << "first=" << pi.first << " second=" << pi.second << "\n";
    }
    void start() {
        cin >> _n;
        int maxPeopleByLang = -1;
        for (int i = 0; i < _n; i++) {
            int t;
            cin >> t;
            auto it = _peopleByLang.find(t);
            if ( it == _peopleByLang.end() ) {
                _peopleByLang.insert(make_pair(t, 1));
            } else {
                it->second++;
            }
            if (maxPeopleByLang == -1 || (_peopleByLang[t] > _peopleByLang[maxPeopleByLang])) {
                maxPeopleByLang = t;
            }
        }

        if (dbg) {
            cout << "maxPeopleByLang= " << maxPeopleByLang << "  and their count=" << _peopleByLang[maxPeopleByLang] << "\n";
        }

        cin >> _m;
        VPI movieLangPairs;
        unordered_set<int> secondLang;
        movieLangPairs.reserve(_m);

        for (int i = 0; i < _m; i++) {
            int t;
            cin >> t;
            movieLangPairs[i] = make_pair(t, 0);
        }

        for (int i = 0; i < _m; i++) {
            int t;
            cin >> t;
            movieLangPairs[i].second = t;
            if (movieLangPairs[i].first == maxPeopleByLang) secondLang.insert(t);
        }

        if (dbg) {
            for (auto it : secondLang) {
                cout << " Second language chosen= " << it << "\n";
            }
        }

        int maxPeopleBySecondLang = *secondLang.begin();
        for (auto it : secondLang) {
            if (_peopleByLang[it] > _peopleByLang[maxPeopleBySecondLang]) {
                maxPeopleBySecondLang = it;
            }
        }

        if (dbg) {
            cout << "maxPeopleBySecondLang= " << maxPeopleBySecondLang << " and their count=" << _peopleByLang[maxPeopleBySecondLang] << "\n";
        }

        int res = -1;
        PI resultPi = make_pair(maxPeopleByLang, maxPeopleBySecondLang);
        if (dbg) {
            cout << "Result PI=";
            printPi(resultPi);
        }

        if (dbg) {
            cout << "Movie lang pairs.size = " << movieLangPairs.size() << "\n";
        }
        for (int i = 0; i < _m; i++) {
            if (dbg) printPi(movieLangPairs[i]);
            if (movieLangPairs[i] == resultPi) {
                res = i+1;
                break;
            }
        }

        cout << res << "\n";

    }
};

C c;
int main() {
    c.start();
    return 0;
}

