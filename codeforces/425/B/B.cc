#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <iterator>

using namespace std;
const bool dbg = true;
struct B {

    bool exitEarly(char c1, char c2) const {
        if (c1 != '?' && c1 != c2) {
            if (dbg) cout << "Exit early for c1=" << c1 << " and c2=" << c2 << "\n";
            return true;
        }
        if (c1 == '?' && isBad(c2)) {
            if (dbg) cout << "Exit early for c1=" << c1 << " and c2=" << c2 << "\n";
            return true;
        }
        return false;
    }

    bool verdict(const string& s) {
        if (starPos == pattern.size()) {
            if (s.size() != pattern.size()) {
                if (dbg) cout << "There is no * and strings have unequal length" << "\n";
                return false;
            }
        } else if (s.size() < pattern.size()-1) {
            if (dbg) cout << "Text has size=" << s.size() << " which is smaller than pattern size=" << pattern.size() << "\n";
            return false;
        }

        int pl = 0, sl = 0, pr = pattern.size() - 1, sr = s.size() - 1;
        while (pl < starPos) {
            if (exitEarly(pattern[pl], s[sl])) {
                if (dbg) cout << "Exiting early traversing right at pos=" << pl << "\n";
                return false;
            }
            pl++, sl++;
        }
        if (dbg) cout << "After moving right pl, pr, sl, sr =[" << pl << "," << pr << "," << sl << "," << sr << "]\n";

        while (pr > starPos) {
            if (exitEarly(pattern[pr], s[sr])) {
                if (dbg) cout << "Exiting early traversing right at string pos=" << sr << " and pattern pos=" << pr <<  "\n";
                return false;
            }
            pr--, sr--;
        }
        if (dbg) cout << "After moving left pl, pr, sl, sr =[" << pl << "," << pr << "," << sl << "," << sr << "]\n";

        while (sl <= sr) {
            if (isGood(s[sl])) {
                if (dbg) cout << " Encountered good char at pos=" << sl << " in text when matching for bad chars\n";
                return false;
            }
            sl++;
        }

        return true;
    }

    void start() {
        string s;
        cin >> s;
        for (auto &it : s) good.insert(it);
        cin >> pattern;
        starPos = pattern.find('*');
        if (starPos == string::npos) starPos = pattern.size();
        int ntc;
        cin >> ntc;
        for (int i = 0; i < ntc; ++i) {
            string s1;
            cin >> s1;
            cout << (verdict(s1) ? "YES" : "NO") << "\n";
        }

    }
    string pattern;
    set<char> good;
    size_t starPos;


    bool isGood(char c) const { return good.count(c) > 0; }
    bool isBad(char c) const { return !isGood(c); }

};

B b;
int main() {
    ios_base::sync_with_stdio(false);
    b.start();
    return 0;
}
