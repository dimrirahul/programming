#include <iostream>
#include <vector>

using namespace std;

const bool dbg = false;
class B {
    public:
        vector<int> less; 
        vector<int> more;
        int n, k, p, x, y;
        long long int lessSum, moreSum;
        int lessElementsNeeded, moreElementsNeeded; 
        bool isPossible() {
            lessElementsNeeded = n/2 - less.size();
            moreElementsNeeded = n/2 - more.size() + 1; 
            if (dbg) {
                cout << "LessNeeded:" << lessElementsNeeded << " MoreNeeded:" << moreElementsNeeded << " ";
                cout << "LessSum:" << lessSum <<" MoreSum:" << moreSum << " " << "\n";
            }
            if (lessElementsNeeded < 0 || moreElementsNeeded < 0) return false;
            if (lessElementsNeeded + moreElementsNeeded * y + lessSum + moreSum > x) return false;
            return true;
        }
        void start() {
            lessSum = moreSum = 0;
            lessElementsNeeded = moreElementsNeeded = 0; 
            cin >> n >> k >> p >> x >> y;
            for (int i = 0; i < k; i++) {
                int t; cin >> t;
                if (t < y) {
                    less.push_back(t);
                    lessSum += t;
                } else {
                    more.push_back(t);
                    moreSum += t;
                } 
            }
            if (!isPossible()) {
                cout << "-1\n";
            } else {
                for (int i = 0; i < lessElementsNeeded; i++) {
                    cout << "1 ";
                }
                for (int i = 0; i < moreElementsNeeded; i++) {
                    cout << y << " ";
                }
                cout << "\n";
            }
        }
};

B b;
int main(int argc, char **Argv) {
    b.start();
    return 0;
}
