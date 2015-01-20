#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <Vector>

using namespace std;

class BoardGameChecker {

    public:
        bool isWinnable(vector<int>v) {
            return isWinnable(v, 0);
        }

        bool isWinnable(vector<int>v, int pos) {
            if (pos >= v.size()) return true;
            for (int i = 1; i <= v[pos]; i++) {
                if (isWinnable(v, pos + i)) return true;
            }
            return false;
        }
};

class DeleteKeyFromArray {
    public:
        void deleteKeyFromArray(vector<int>& v, int k) {
            int shift = 0;
            for (int i = 0; i < v.size(); i++) {
                if (v[i] == k) {shift++; continue;}
                v[i - shift] = v[i];
            }
            for (int i = 0; i < shift; i++) {
                v[v.size()-i-1] = 0;
            }
        }
};

BoardGameChecker bc;
DeleteKeyFromArray dka;

vector<int> getInputArr() {
    vector <int> res;
    int t;
    while ( cin >> t ) {
        res.push_back(t);
    }
    return res;

}
int main(int argc, char **argv) {
    //cout << (bc.isWinnable(getInputArr(), 0) ? " Winnable": "!Winnable") << "\n";
    vector<int> v = getInputArr();
    dka.deleteKeyFromArray(v, 3);
    for (int i = 0;i < v.size(); i++) cout << v[i] << " ";
    return 0;
}
