#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>


using namespace std;
const int MAX_LEN = 11;
class PM {
    public:
        char buff[MAX_LEN];
        bool isPalindrome(string s) {
            for (int i = 0; i < s.size()/2 ; i++) {
                if (s[i] != s[s.size() - i -1]) return false;
            }
            return true;
        }

        void start() {
            scanf("%s\n", buff);
            string s(buff);
            if (isPalindrome(s)) {
                if (s.size() % 2 == 0) {
                    s.insert(s.begin() + s.size()/2, 'a');
                } else {
                    s.insert(s.begin() + s.size()/2, s[s.size()/2]);
                }

                cout << s << "\n";
                return;
            }

            for (int i = 0; i <= s.size(); i++) {
                for (int j = 0 ; j < 26; j++) {
                    string t = s;
                    t.insert(t.begin() + i, 'a' + j);
                    if (isPalindrome(t)) {
                        cout << t << "\n";
                        return;
                    }
                }
            }

            cout << "NA\n";
        }
};
PM pm;
int main(int argc, char **Argv) {
    pm.start();
    return 0;
}
