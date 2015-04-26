#include <bits/stdc++.h>

using namespace std;

const bool dbg = true;
class Esre {
    public:
        string pattern, text;
        bool esreMatch(int patPos, int textPos) {
            return sreMatch(patPos, textPos);
        }

        bool isNextCharStar(int p) {
            return (p < pattern.size() - 1 && pattern[p+1] == '*');
        }

        bool sreMatch(int patPos, int textPos) {
            if (dbg) printf("New loop entered patPos=%d, textPos=%d\n", patPos, textPos);
            if (textPos == text.size()) {
                return patPos == pattern.size();
            }
            if (patPos == pattern.size()) return true;
            bool res = false;
            for (int j = textPos; j < text.size() && !res; j++) {
                if (dbg) cout << "patPos=" << patPos << "\n";
                if (isNextCharStar(patPos)) {
                    res = false;
                    for (int i = j; i < text.size(); i++) {
                        if (dbg) cout << "I=" << i << " PatPos= " << patPos << "\n";
                        if (pattern[patPos] == '.' || text[i] == pattern[patPos]) {
                            res |= sreMatch(patPos+2, i+1);
                            if (res) {
                                break;
                            }
                        }
                    } 
                    if (!res) {
                        patPos = 0;
                    }
                } else {
                    if (pattern[patPos] == text[j] || pattern[patPos] == '.') {
                        res = sreMatch(patPos+1, j+1);
                    } else {
                        res = false;
                        patPos = 0;
                    }
                }
            }
            return res;
        }
        bool esreMatch(string _pattern, string _text) {
            pattern = _pattern; text = _text;
            return esreMatch(0, 0);
        }
};

Esre p;

void printRes(int expected, int actual) {
    if (expected == actual) {
        cout << "Success\n";
    } else {
        cout << "Fail\n";
    }
}
void testBothSame() {
    string s1("abc");
    string s2("abc");
    printRes(1, p.esreMatch(s1, s2));
}

void test2() {
    string s1("abc");
    string s2("someshitabc");
    printRes(1, p.esreMatch(s1, s2));
}

void test3() {
    string s1("abc");
    string s2("absomeshitabc");
    printRes(1, p.esreMatch(s1, s2));
}
void test4() {
    string s1("abc");
    string s2("absomeshitabac");
    printRes(1, p.esreMatch(s1, s2));
}

void test5() {
    string s1("a*");
    string s2("aaaaaa");
    printRes(1, p.esreMatch(s1, s2));
}

void test6() {
    string s1("b*");
    string s2("aaaaaa");
    printRes(0, p.esreMatch(s1, s2));
}

void test7() {
    string s1("ab*c");
    string s2("abbbbc");
    printRes(1, p.esreMatch(s1, s2));
}

void test8() {
    string s1("ab*cd");
    string s2("abbbbd");
    printRes(0, p.esreMatch(s1, s2));
}

void test9() {
    string s1("ab*cbcda*");
    string s2("abbbbcbcdaaaaaaaaaa");
    printRes(1, p.esreMatch(s1, s2));
}

int main(int argc, char **argv) {
    //testBothSame();
    //test3();
    test9();
    return 0;
}

