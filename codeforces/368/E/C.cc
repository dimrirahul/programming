#include <iostream>
#include <vector>

using namespace std;


char alterChar(char it) {
    char c;
    if (it == 'a') c = 'z';
    else c = it -1;
    return c;
}

int main() {
    string s;
    cin >> s;
    string sCpy;
    for (auto it : s) {
        sCpy.push_back(alterChar(it));
    }

    string res;
    size_t pos = 0;
    bool hasInserted = false;
    while (pos < s.size() && s[pos] <= sCpy[pos]) {
        res.push_back(s[pos++]);
    }
    while(pos < s.size() &&  sCpy[pos] <= s[pos]) {
        res.push_back(sCpy[pos++]);
        hasInserted = true;
    }
    while(pos < s.size()) {
        res.push_back(s[pos++]);
    }
    if (!hasInserted) {
        auto it = res.rbegin();
        *it = alterChar(*it);
    }
    cout << res << "\n";
    return 0;
}
