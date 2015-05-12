#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef pair <int, int> PI;
const bool dbg = true;
class C {
    public:
        vector<string> cave;
        PI start, end;
        PI dim;
        bool isPossible(PI curr) {
            if (dbg) {
                cout << "Curr = " << curr.first << " " << curr.second << " Start=" << start.first << " " << start.second << "\n";
                printCave();
            }
            if (curr.first < 0 || curr.first >= dim.first || curr.second < 0 || curr.second >= dim.second) return false;
            if (curr ==  end) return true;
            bool res = false;
            if (dbg) cout << "Cave element = " << cave[curr.first][curr.second] << "\n";
            if (cave[curr.first][curr.second] == 'X') {
                if (dbg) cout << "Cntl in if part\n";
                res = false;
            } else {
                if (dbg) cout << "Cntl in else part\n";
                cave[curr.first][curr.second] = 'X';
                bool tRes = false;
                int arr[] = {-1, 1};
                for (int i = 0; i < 2 && !tRes; i++) {
                    tRes = isPossible(make_pair(curr.first + arr[i], curr.second));
                }
                for (int i = 0; i < 2 && !tRes; i++) {
                    tRes = isPossible(make_pair(curr.first, curr.second + arr[i]));
                }
                cave[curr.first][curr.second] = '.';
                res = tRes;
            }
            return res;
        }

        void printCave() {
            for (int i = 0 ; i < cave.size(); i++) {
                cout << cave[i] << "\n";
            }
        }

        void startTest() {
           cin >> dim.first >> dim.second;
           for (int i = 0 ; i < dim.first; i++) {
               string s;
               cin >> s;
               cave.push_back(s);
           }
           cin >> start.first >> start.second;
           cin >> end.first >> end.second;
           start.first--; start.second--;
           end.first--; end.second--;
           cave[start.first][start.second] = '.';
           if (isPossible(start)) {
               cout << "YES\n";
           } else {
               cout << "NO\n";
           }
        }
};

C a;
int main(int argc, char **Crgv) {
    a.startTest();
    return 0;
}
