#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
typedef pair <int, int> PI;
typedef vector < PI > VPI;
typedef pair <PI , PI> PPI;
typedef unsigned long long UL;
class Comp {
    public:
        bool operator()(PI p1, PI p2) const {
            if (p1.second != p2.second) return p1.second < p2.second;
            return p1.first < p2.first;
        }
};
class ClosestPairFinder {
    public:
        void start() {
            VPI x, y;
            int n; cin >> n;
            for (int i = 0; i < n; i++) {
                int p, q;
                cin >> p >> q;
                x.push_back(make_pair(p, q));
                y.push_back(make_pair(p, q));
            }
            sort(x.begin(), x.end());
            sort(y.begin(), y.end(), Comp);
            pair<PI, PI> res = findClosestPts(&x, &y);
            printPts(res.first);
            printPts(res.second);
        }
        void printPts(PI p) {
            cout << "x=" << p.first << "y=" << p.second << "\n";
        }
        UL delta(int x) {
            UL res = x;
            return res * res;
        }
        UL getDistance(PI p1, PI p2) {
            return delta(p1.first - p2.first) + delta(p1.second - p2.second);
        }
        PPI bruteForce(VPI& x) {
            UL maxD = 1e18;
            int idx1 = -1, idx2 = -1;
            for (int i = 0; i < x.size(); i++) {
                for (int j = i+1; j < x.size(); j++) {
                    if ( getDistance(x[i], x[j] < maxD)) {
                        maxD = getDistance(x[i], x[j]);
                        idx1 = i;
                        idx2 = j;
                    }
                }
            }
            return make_pair(x[idx1], x[idx2]);
        }

        void splitXarr(VPI &orig, VPI& left, VPI &right) {
            for (int i = 0; i < orig.size(); i++) {
                if (i < orig.size()/2) left.push_back(orig[i]);
                else right.push_back(orig[i]);
            }
        }
        void splitYarr(VPI& orig, VPI& left, VPI& right, int bound) {
            for (int i = 0; i < orig.size(); i++) {
                if (orig[i].second < bound) left.push_back(orig[i]);
                else right.push_back(orig[i]);
            }
        }
        pair <PI, PI> findClosestPts(VPI& x, VPI& y) {
            if (x.size() == 3) return bruteForce(x);
            //Divide and conquer
            VPI xLeft, xRight, yLeft, yRight;
            splitXarr(x, xLeft, xRight);
            splitYarr(y, yLeft, yRight, x[x.size()/2].first);
            PPI resLeft = findClosestPts(xLeft, yLeft);
            PPI resRight = findClosestPts(xRight, yRight);
            UL minD = min(delta(resLeft.first, resLeft.second), delta(resRight.first, resRight.second);




        }
};
ClosestPairFinder p;
int main(int argc, char **Argv) {
    p.start();
    return 0;
}
