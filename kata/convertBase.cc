#include <iostream>
#include <cstring>
#include <sstream>
#include <algorithm>

using namespace std;
string getString(int n) {
    stringstream ss;
    while(true) {
        ss << (char) ( (n % 26 ) + 'A');
        n /= 26;
        if (n == 0) break; 
    }
    string s = ss.str();
    reverse(s.begin(), s.end());
    return s;
}
int main(int argc, char **argv) {
    int n; cin >> n;
    cout << getString(n);
    return 0;
}
