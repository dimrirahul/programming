#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int PATTERN_SIZE = 51;
const int TEXT_SIZE = PATTERN_SIZE * 100;
class NaiveStringMatching {
    public:
        char text[TEXT_SIZE];
        char pattern[PATTERN_SIZE];

        void start() {
            scanf("%s\n", pattern);
            scanf("%s\n", text);

            int patternLen = strlen(pattern);
            int textLen = strlen(text);

            for (int i = 0; i < textLen; i++) {
                bool match = true;
                for (int j = 0; j < patternLen && i + j < textLen; j++) {
                    if (text[i+j] != pattern[j]) {
                        match = false;
                        break;
                    }
                }
                if (match) {
                    printf("Match found in text position starting %d\n", i);
                }
            }
        }
        
        void generateBadStrings() {
            string s;
            for (int i = 0; i < 25; i++) {
                s += 'a' + i;
                s += 'A' + i;
            }
            cout << s << "\n";
            for (int i = 0; i < 9; i++) {
                cout << s << (char)('0' + i);
            }
            cout << "\n";
        }

};

NaiveStringMatching naive;
int main(int argc, char **argv) {
    naive.start();
    //naive.generateBadStrings();
    return 0;
}
