#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <set>

using namespace std;
const int MAX_SIZE = 16;

class Sorter {
    public:
        const bool operator()(string s1, string s2) {
            if (s1.size() != s2.size()) return (s1.size() > s2.size());
            else return s1 > s2;
        }
};
class BruteForceLcs {
    public:
        char str1[MAX_SIZE];
        char str2[MAX_SIZE];

        set <string, Sorter> vs1;
        set <string, Sorter> vs2;
        void start() {
            scanf("%s\n", str1);
            scanf("%s\n", str2);
            findLcs();
        }

        void generateAllSubsequences(char *s, set<string, Sorter>& res) {
            res.clear();
            int sLen = strlen(s);
            int limit = 1 << (sLen);
            for (int i = 1; i < limit; i++) {
                string t;
                for (int j = 0; j < sLen; j++) {
                    if (i & (1 << j)) {
                        t += s[j];
                    }
                }
                res.insert(t);
            }
        }
        void findLcs() {
            generateAllSubsequences(str1, vs1);
            for (set<string, Sorter>::iterator it = vs1.begin(); it != vs1.end(); it++) cout << *it << "\n";

            cout << "Next String\n";
            generateAllSubsequences(str2, vs2);
            for (set<string, Sorter>::iterator it = vs2.begin(); it != vs2.end(); it++) cout << *it << "\n";

        }
};

BruteForceLcs bf;
int main(int argc, char **Argv) {
    bf.start();
    return 0;
}
