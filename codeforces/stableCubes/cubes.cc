#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <sstream>
#include <cstdio>
//#include<bits/stdc++.h>

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define mp make_pair
using namespace std;
const int MOD = (int) 1e9 + 9;
class Node {
    public:
        int v, x, y;
        Node(int _v, int _x, int _y) { v= _v; x =_x; y = _y; }
        Node() { v = x = y = -1;}
        bool operator<(Node o) const{
            return v < o.v;
        }
        Node(const Node& o) {
            v = o.v;
            x = o.x;
            y = o.y;
        }
        void print() const {
            printf("x,y,v=[%d, %d, %d] ", x, y, v);
        }
};
typedef pair <int, int> PI;
typedef map <PI, Node> NodeMap;
const bool dbg = false;
class Cubes {
    public:
        NodeMap nbp;
        set<Node> candidateSet, fixedSet;
        int M;

        vector<PI> findBase(int x, int y) const {
            vector<PI> res;
            if (nbp.count(mp(x, y)) == 0) return res;
            int p[] = {-1, 0, 1};
            REP (i, 3) {
                PI pi = mp(x + p[i], y -1);
                if (nbp.count(pi) > 0) {
                    res.push_back(pi);
                }
            }
            return res;
        }
        bool isFixed(int x, int y) const {
            int p[] = {-1, 0, 1};
            REP (i, 3) {
                vector<PI> base = findBase(x + p[i], y+1);
                if (base.size() == 1) return true;
            }
            return false;
        }

        bool isFixed(Node n) const {
            return isFixed(n.x, n.y);
        }
        void preprocess() {
            REP (i, M) {
                int x, y;
                cin >> x >> y;
                Node n(i, x, y);
                nbp[mp(x, y)] = n;
                candidateSet.insert(n);
            }
            for (set<Node>::iterator it = candidateSet.begin(); it != candidateSet.end(); it++) {
                if (isFixed(it->x, it->y)) {
                    fixedSet.insert(*it);
                }
            }

            for (set<Node>::iterator it = fixedSet.begin(); it != fixedSet.end(); it++) {
                candidateSet.erase(*it);
            }
            if (dbg) printMaps();
        }
        int vpick() {
            set<Node>::iterator it = candidateSet.end();
            it--;
            Node n(*it);
            updateSets(n);
            return n.v;
        }

        int ppick() {
            set<Node>::iterator it = candidateSet.begin();
            Node n(*it);
            updateSets(n);
            return n.v;
        }

        void updateSets(Node n) {
            nbp.erase(mp(n.x, n.y));
            candidateSet.erase(n);
            //Move elements from candidate set to fixedSet.
            int p[] = {-1, 0, 1};
            REP(i, 3) {
                PI pi = mp(n.x + p[i], n.y + 1);
                vector<PI> base = findBase(pi.first, pi.second);
                if (base.size() == 1) {
                    candidateSet.erase(nbp[base[0]]);
                    fixedSet.insert(nbp[base[0]]);
                }
            }
            //Move elements from fixedSet to candidate set.
            REP (i, 3) {
                PI pi = mp(n.x + p[i], n.y - 1);
                if (nbp.count(pi) > 0 && fixedSet.count(nbp[pi]) > 0 && !isFixed(nbp[pi])) {
                    fixedSet.erase(nbp[pi]);
                    candidateSet.insert(nbp[pi]);
                } 
            }
            if (dbg) printMaps();
        }
        void printMaps() {
            cout << "NodeMap\n";
            for (NodeMap::const_iterator it = nbp.begin(); it != nbp.end(); it++) it->second.print();
            cout << "\n Removable\n";
            for (set<Node>::const_iterator it = candidateSet.begin(); it != candidateSet.end(); it++) it->print();
            cout << "\n Fixed\n";
            for (set<Node>::const_iterator it = fixedSet.begin(); it != fixedSet.end(); it++) it->print();
            cout << "\n=============\n";
        }
        void start() {
            cin >> M;
            preprocess();
            long long ans = 0;
            int turn = 0;
            while (turn < M) {
                int v;
                if (turn % 2 == 0) {
                    v = vpick();
                } else {
                    v = ppick();
                }
                if (dbg) cout << "picked=" << v << "\n";
                ans = (ans * M) % MOD + v;
                ans %= MOD;
                turn++;
            }
            cout << ans << "\n";
        }

};

Cubes c;
int main() {
    c.start();
    return 0;
}
