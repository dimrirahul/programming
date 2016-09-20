#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <assert.h>

using namespace std;

const int MAX_SIZE = 2003;
using LL = long long;

using VL = vector<LL>;
using PI = pair<int, int>;

struct Rect {
    Rect(int inpR1, int inpC1, int inpR2, int inpC2) : r1(inpR1), c1(inpC1), r2(inpR2), c2(inpC2) {}
    Rect() : r1(0), c1(0), r2(0), c2(0) {}

    int r1, c1, r2, c2;
};

const bool dbg = !true;
PI matrix[MAX_SIZE][MAX_SIZE]; //first is garlandId, second is position in array.
struct Garland {
    Garland(int inpId): sum(0), lit(true), id(inpId)  {}

    void addCell(int r, int c, int v, int insertPos) {
        sum += v;
        cumSum.push_back(sum);
        matrix[r][c] = make_pair(id, insertPos);
        ptsOnBoard.push_back(make_pair(r, c));
    }

    void readBulb(int insertPos) {
        int r, c, v;
        scanf("%d %d %d\n", &r, &c, &v);
        addCell(r, c, v, insertPos);
    }

    void readGarland() {
        int bulbCount;
        scanf("%d\n", &bulbCount);
        for (int i = 0; i < bulbCount; i++) {
            readBulb(i);
        }
    }

    vector<size_t> getNeighbors(int r, int c) {
        vector<size_t> neighborIdx;
        size_t pos = matrix[r][c].second;
        if (pos != 0) { neighborIdx.push_back(pos - 1); }
        if (pos != ptsOnBoard.size()) { neighborIdx.push_back(pos + 1); }
        return neighborIdx;
    }

    bool isCrossingHorizontalLine(int r, int c, Rect& rect) {
        if ( matrix[r][c].first != id) return false;
        vector<size_t> v = getNeighbors(r, c);
        for (auto it : v) {
            PI &p = ptsOnBoard[it];
            if (p.second == c && ( p.first < rect.r1 || p.first > rect.r2)) return true;
        }
        return false;
    }

    bool isCrossingVerticalLine(int r, int c, Rect& rect) {
        if ( matrix[r][c].first != id) return false;
        vector<size_t> v = getNeighbors(r, c);
        for (auto it : v) {
            PI &p = ptsOnBoard[it];
            if (p.first == r && ( p.second < rect.c1 || p.second > rect.c2)) return true;
        }
        return false;
    }


    void makeCut(Rect& rect) {
        vector<int> v1 = {rect.r1, rect.r2};
        vector<int> v2 = {rect.c1, rect.c2};
        for (int i = rect.r1; i <= rect.r2; i++) {
            for (auto j : v2) {
                if (isCrossingVerticalLine(i, j, rect)) {
                    if (dbg) cout << "For id=" << id << " co-ordinates [" << i << ", " << j << "] has horizontal neighbor\n";
                    cutPoints.push_back(matrix[i][j].second);
                }
            }
        }

        for (auto i : v1) {
            for (int j = rect.c1; j <= rect.c2; j++) {
                if (isCrossingHorizontalLine(i, j, rect)) {
                    if (dbg) cout << "For id=" << id << " co-ordinates [" << i << ", " << j << "] has vertical neighbor\n";
                    cutPoints.push_back(matrix[i][j].second);
                }
            }
        }
    }

    bool isPointInside(int r, int c, Rect& rect) { return r >= rect.r1 && r <= rect.r2 && c >= rect.c1 && c <= rect.c2;}

    LL getSum(LL initValue, bool substract) {
        LL res = initValue;
        vector<int> v;
        sort(cutPoints.begin(), cutPoints.end());
        v.insert(v.end(), cutPoints.begin(), cutPoints.end());
        for (auto it = v.rbegin(); it != v.rend(); it++) {
            if (dbg) cout << "Subs=" << substract << " pos=" << *it << " res=" << res << "\n";
            if (substract) {
                if (*it == 0) continue;
                if (dbg) cout << "In sub block decreasing value by=" << cumSum[*it -1] << "\n";
                res -= cumSum[*it - 1];
            } else {
                if (dbg) cout << "In plus block increasing value by=" << cumSum[*it] << "\n";
                res += cumSum[*it];
            }
            if (dbg) cout << "Curr sum=" << res << "\n";
            substract = (!substract);
        }
        return res;
    }

    LL getSum(Rect& rect) {
        LL res = 0;
        if (!lit) return res;
        auto it = ptsOnBoard.rbegin();
        bool tailIsInside = isPointInside(it->first, it->second, rect);
        if (tailIsInside) {
            res = getSum(sum, true);
        } else {
            res = getSum(0, false);
        }
        return res;;
    }

    void switchLights() { lit = !lit;}

    void printCutPoints() {
        cout << "Cutpoints for garland with id = " << id << "\n";
        for(auto it: cutPoints) cout << it << " ";
        cout << "\n";
    }

    LL sum;
    VL cumSum;
    vector<PI> ptsOnBoard;
    bool lit;
    int id ;
    vector<int> cutPoints;

};


struct Query {
    Query(): switchQuery(false) {}
    void readQuery() {
        string s;
        cin >> s;
        if (s == "SWITCH") {
            scanf("%d\n", &gId);
            switchQuery = true;
        } else {
            scanf("%d %d %d %d\n", &rect.r1, &rect.c1, &rect.r2, &rect.c2);
        }
    }

    int gId;
    bool switchQuery;
    Rect rect;
};

using VG = vector<Garland>;
using VQ = vector<Query>;


void init() {
    for (int i = 0; i < MAX_SIZE; i++)  {
        for (int j = 0; j < MAX_SIZE; j++) {
            matrix[i][j] = make_pair(0, 0);
        }
    }
};

void printMatrix(int n, int m) {
    cout << "\n";
    for (int i = 0 ; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            printf("[%2d %2d] ", matrix[i][j].first, matrix[i][j].second);
        }
        cout << "\n";
    }
}

VG garlandVector;
VQ queryVector;
int main() {
    init();
    int n, m, k, q;
    cin >> n >> m >> k;
    //garlandVector.capcity(k+1);
    for (int i = 0; i < k+1; i++) {
        Garland g(i);
        if (i !=0) g.readGarland();
        garlandVector.push_back(move(g));
    }
    cin >> q;
    //queryVector.capacity(q+1);
    for (int i = 0; i < q+1; i++) {
        Query query;
        if (i != 0) query.readQuery();
        queryVector.push_back(move(query));
    }

    if (dbg) { printMatrix(n, m); }
    for (int i = 1; i < queryVector.size(); i++) {
        for (auto& it : garlandVector) it.cutPoints.clear();
        Query &q = queryVector[i];
        if (q.switchQuery) {
            garlandVector[q.gId].switchLights();
        } else {
            LL sum = 0;
            for (int i = 1; i < garlandVector.size(); i++) {
                garlandVector[i].makeCut(q.rect);
                if(dbg) garlandVector[i].printCutPoints();
                LL partSum = garlandVector[i].getSum(q.rect);
                if (dbg) cout << "Garland=" << i << " has sum=" << partSum << "\n";
                sum += partSum;
            }
            if (dbg) cout << "Final Sum=\n";
            cout << sum << "\n";
        }
    }
    return 0;
}
