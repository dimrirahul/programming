#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>

using namespace std;
using VI = vector<int>;
using LL = long long;
using PI = pair<int, int>;
using MI = map<int, int>;


struct State {
    State() : countQ(0) {}
    unordered_map<int, int> countAlphabets;
    int countQ;

    bool isPossible() {
        return countAlphabets.size() + countQ == 26;
    }

    void updateIncoming(char c) {
        if (c == '?') {
            countQ++;
        } else {
            int k = c - 'A';
            auto it = countAlphabets.find(k);
            if (it == countAlphabets.end()) countAlphabets.insert(make_pair(k, 1));
            else it->second++;
        }
    }

    void updateOutgoing(char c) {
        if (c == '?') countQ--;
        else {
            int k = c - 'A';
            auto it = countAlphabets.find(k);
            it->second--;
            if (it->second == 0) countAlphabets.erase(it);
        }
    }

    set<int> getRemaining() {
        set<int> s;
        for (int i = 0; i < 26; i++) {
            if (countAlphabets.find(i) == countAlphabets.end()) s.insert(i);
        }
        return s;
    }

};

struct A {
    State state;
    void start() {
        string s;
        cin >> s;
        string res = s;
        bool possible = false;
        for (int i = 0; i < s.size(); i++) {
            state.updateIncoming(s[i]);
            if (i - 26 >= 0) state.updateOutgoing(s[i - 26]);
            if (state.isPossible()) {
                set<int> rem = state.getRemaining();
                auto it = rem.begin();
                for (int j = i - 25; j <= i; j++) {
                    if (res[j] == '?') {
                        res[j] = (char)(*it + 'A');
                        it++;
                    }
                }
                possible = true;
                break;
            }
        }
        if (possible) {
            for (auto& it : res) {
                if (it == '?') it = 'A';
            }
            cout << res << "\n";
        } else {
            cout << "-1\n";
        }
    }
};

A a;
int main() {
    a.start();
    return 0;
}
