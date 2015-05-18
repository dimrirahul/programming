#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int K = 10;
const int SZ = 100;

typedef pair <int, int> PI;
class Sorter {
    public:
        bool operator()(PI p1, PI p2) {
            if (p1.first != p2.first) return p1.first > p2.first;
            return p1.second > p2.second;
        }
};
class KwayMerger {
    public:
        vector <int> vecs[K];
        void populateVectors() {
            for (int i = 0; i < K; i++) {
                for (int  j = 0; j < SZ; j++) {
                    vecs[i].push_back(rand());
                }
                sort(vecs[i].begin(), vecs[i].end());
            }
        }

        vector <int> merge() {
            int pos[K];
            vector <int> out;
            memset(pos, 0, sizeof(int) * K);
            priority_queue< PI, vector< PI >, Sorter > pq;
            for (int i = 0; i < K; i++) {
                pq.push(make_pair(vecs[i][0], i));
            }
            while (!pq.empty()) {
                pair <int, int> e = pq.top();
                pq.pop();
                out.push_back(e.first);
                pos[e.second]++;
                if (pos[e.second] < SZ) {
                    pq.push(make_pair(vecs[e.second][pos[e.second]], e.second));
                }
            }
            return out;
        }

        bool isSorted(vector<int>& v) {
            for (int i = 0; i < v.size()-1; i++) {
                if (v[i] > v[i+1]) return false;
            }
            return true;
        }

};

KwayMerger kw;
int main(int argc, char **argv) {
    kw.populateVectors();
    vector<int> o = kw.merge();
    cout << "is Sorted = " << kw.isSorted(o) << "\n";
    //for (int i = 0; i < o.size(); i++) cout << o[i] << "\n";

}
