#include <iostream>
#include <cstring>
#include <sstream>
#include <algorithm>

using namespace std;
int getPow(int e);

int getLen(int n) {
    int p = 0;
    int s = 0;
    while ( s <= n) {
        p++;
        s += getPow(p);
    }
    cout << "Len  of " << n << " == " << p << "\n";
    return p;
}

int getPow(int e) {
    int res = 1;
    for (int i = 0; i < e; i++) res *= 26;
    return res;
}

string getString(int n) {
    string s;
    if (n < 26) {
        s += 'A' + n;
    } else {
        int l = getLen(n);
        for (int i = 1; i < l; i++) {
            n -= getPow(i);
        }
        cout << "N=" << n << "\n";
        while(true) {
            s += (char) ( (n % 26 ) + 'A');
            n /= 26;
            cout << "S= :"<< s << " n= " << n <<"\n";
            if (n == 0) break; 
        }
        reverse(s.begin(), s.end());
        while (s.size() < l) { 
            s = string("A") + s;
        }
    }
    return s;
}

int main(int argc, char **argv) {
    int n; cin >> n;
    cout << getString(n);
    return 0;
}
