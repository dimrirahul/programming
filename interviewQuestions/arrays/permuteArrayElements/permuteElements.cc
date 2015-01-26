#include <iostream>
#include <cstdio>
#include <vector>
#include <cassert>
#include <sstream>

using namespace std;

class PermuteAccordingToInput {
    public:
        void permute(vector<int>& v, vector<int>& permutation) {
            int nextIndex = permutation[0];
            int value = v[0];
            for (int i = 0; i < permutation.size() - 1; i++) {
                swap(value, v[nextIndex]);
                nextIndex = permutation[nextIndex];
            }
        }

};

vector<int> getVector() {
    string s;
    getline(cin, s);
    stringstream ss(s);
    int t;
    vector<int> res;
    while (ss >> t) {
        res.push_back(t);
    }
    return res;
}

int main(int argc, char **argv) {
    vector<int> v1 = getVector();
    vector<int> v2 = getVector();
    PermuteAccordingToInput pi;
    pi.permute(v1, v2);
    for (int i = 0; i < v1.size(); i++) cout << v1[i] << "  ";
    return 0;
}
