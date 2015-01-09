
// {{{ Boilerplate Code <--------------------------------------------------
// vim:filetype=cpp:foldmethod=marker:foldmarker={{{,}}}

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>
#include <string.h>

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()

using namespace std;

// }}}

class Twain
{
    public:
        string applyRules(string w, int years) {
            string wc = w;
            stringstream ss;
            for(int i = 1; i <= years; i++) {
                switch (i) {
                    case 1: {
                                for (int j = 0; j < wc.size(); j++) {
                                    if (wc[j] == 'x') {
                                        if ( j == 0) {
                                            ss << 'z';
                                        } else {
                                            ss << "ks";
                                        }
                                    } else {
                                        ss << wc[j];
                                    }
                                }
                            }
                            break;
                    case 2:
                            {
                                for (int j = 0; j < wc.size(); j++) {
                                    if (wc[j] == 'y') {
                                        ss << 'i';
                                    } else {
                                        ss << wc[j];
                                    }
                                }
                            }
                            break;
                    case 3:
                            {
                                for (int j = 0; j < wc.size(); j++) {
                                    if (j != wc.size() - 1 && wc[j] == 'c' && (wc[j+1] == 'e' || wc[j+1] == 'i')) {
                                        ss << 's';
                                    } else {
                                        ss << wc[j];
                                    }
                                }
                            }
                            break;
                    case 4:
                            {
                                stack<char> s;
                                int j = wc.size() - 1;
                                while ( j >= 0 ) {
                                    s.push(wc[j]);
                                    if ( wc[j] == 'k') {
                                        while( j >=1 && wc[j-1] == 'c') {
                                            j--;
                                        }
                                    }
                                    j--;
                                }
                                while (!s.empty()) {
                                    ss << s.top();
                                    s.pop();
                                }
                            }
                            break;
                    case 5:
                            {
                                int j = 0;
                                while ( j < wc.size() ) {
                                    if (wc.size() >= 3 && j == 0 &&  wc[j] == 's' && wc[j +1] == 'c' && wc[j + 2] == 'h') {
                                        ss << "sk";
                                        j+= 2;
                                    } else if ( j < wc.size() -2 &&  wc[j] == 'c' && wc[j+1] == 'h' &&  wc[j+2] == 'r') {
                                        ss << "kr";
                                        j+=2;
                                    } else if( wc[j] == 'c') {
                                        if (j == wc.size() - 1 || wc[j+1] != 'h') {
                                            ss << 'k';
                                        } else {
                                            ss << wc[j];
                                        }
                                    } else {
                                        ss << wc[j];
                                    }
                                    j++;
                                }
                            }
                            break;
                    case 6:
                            {
                                int j = 0;
                                while ( j < wc.size()) {
                                    if (wc.size() >= 2 && j == 0 && wc[j] == 'k' && wc[j + 1] == 'n') {
                                        j += 1;
                                    }
                                    ss << wc[j];
                                    j++;
                                }
                            }
                            break;
                    case 7:
                            {
                                int j = 0;
                                while ( j < wc.size()) {
                                    char c = wc[j];
                                    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                                    } else {
                                        while ( j < wc.size() -1 && c == wc[j+1] ) {
                                            j++;
                                        }
                                    }
                                    ss << wc[j];
                                    j++;
                                }
                            }
                            break;
                };
                wc = ss.str();
                ss.str("");
            }
            return wc;
        }

        void parseStrings(string input, vector<string>& out) {
            out.clear();
            char delim[] = " ";
            char buffer[100];
            sprintf(buffer,"%s", input.c_str());
            char *ptr = strtok(buffer, delim);
            while (ptr != NULL) {
                string s(ptr);
                cout << "Extracted String = " << s << "\n";
                ptr = strtok(NULL, delim);
                out.push_back(s);
            }
        }

        string getNewSpelling(int year, string phrase)
        {
            vector<string> out;
            stringstream ss;
            parseStrings(phrase, out);
            vector<string> transformed;
            for (vector<string>::iterator it = out.begin(); it != out.end(); it++) {
                transformed.push_back(applyRules(*it, year));
            }

            int i = 0;
            int word = 0;
            while ( i < phrase.size()) {
                if (phrase[i] == ' ') {
                    ss << ' ';
                    i++;
                } else {
                    ss << transformed[word];
                    i += out[word].size();
                    word++;
                }
            }
            return ss.str();
        }
};

