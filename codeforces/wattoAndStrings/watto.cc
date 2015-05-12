#include <iostream>
#include <map>
#include <vector>

using namespace std;

const int P = 10000019;
typedef unsigned int UI;
const bool dbg = true;
class W {
    public:
        map<UI, vector<string> > hashTable;
        int N, M;
        map<UI, UI> powMap;

        UI getPow(int p) {
            if (powMap.count(p) > 0) return powMap[p];
            if (p == 0) {
                powMap[0] = 1;
            } 
            UI k = powMap.rbegin()->first;
            UI v = powMap[k];
            for (; k <= p; k++) {
                v *= 3;
                v %= P;
                powMap[k+1] = v;
            }
            return v;
        }

        UI getHashKey(string s) {
            int res = 0;
            for (int i = 0; i < s.size(); i++) {
                res *= 3;
                res %= P;
                res += s[i] - 'a';
                res %= P;
            }
            if (dbg) cout << "String s'" + s + "' has hv=" << res << "\n";
            return res;
        }

        void start() {
            cin >> N >> M;
            for (int i = 0; i < N; i++) {
                string s;
                cin >> s;
                UI hashKey = getHashKey(s);
                if (hashTable.count(hashKey) == 0) {
                    vector <string> v;
                    hashTable[hashKey] = v;
                }
                map<UI, vector<string>>::iterator it = hashTable.find(hashKey);
                it->push_back(s);
            }

            for (int i = 0 ; i < M; i++) {
                string s;
                cin >> s;
                UI hashKey = getHashKey(s);
                for (int i = s.size() - 1; i >= 0; i--) {
                    if 
                }
            }
        }

};

W w;
int main(int argc, char **argv) {
    w.start();
    return 0;
}
