#include <iostream>
#include <unordered_map>
#include <array>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    string str1, str2, str3;
    cin >> str1 >> str2 >> str3;
    vector<pair<char, char>> vpi;
    for (int i = 0; i < 26; i++) {
        vpi.push_back(make_pair(str1[i], str2[i]));
    }
    sort(vpi.begin(), vpi.end());
    for (auto it : str3) {
        if (it <= '9' && it >= '0') {
            cout <<  it;
            continue;
        }
        bool isCaps = it <= 'Z' && it >= 'A';
        int offset = (isCaps) ? it - 'A' : it - 'a';
        char c = vpi[offset].second;
        if (isCaps) c += 'A' - 'a';
        cout << c;
    }
    cout << "\n";
    return 0;
}
