#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

class PermuteAll {
    public:
        vector<string> permute(string s) {
            vector<string> res;
            if (s.size() == 1) {
                res.push_back(s);
                return res;
            }
            vector<string> tempRes = permute(s.substr(1));
            for (int i = 0; i < tempRes.size(); i++) {
                for (int j = 0; j < tempRes[i].size(); j++) {
                    res.push_back(tempRes[i].substr(0, j) + s[0] + tempRes[i].substr(j));
                }
                res.push_back(tempRes[i] + s[0]);
            }
            return res;
        }
        void printRes(vector<string> s) {
            printf("Size = %u\n", s.size());
            for (int i = 0; i < s.size(); i++) printf("%s\n", s[i].c_str());
        }

};

PermuteAll pa;
int main(int argc, char **Argv) {
    pa.printRes(pa.permute(string(Argv[1])));
    return 0;
}
