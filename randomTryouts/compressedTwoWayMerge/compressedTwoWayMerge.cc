#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef vector <int> VI;
const int V1SZ = 300;
const int V2SZ = 500;
class TwoWayInplaceMerger {
    public:
        int v1[V1SZ], v2[V1SZ + V2SZ];
        TwoWayInplaceMerger() {
            memset(v1, -1, sizeof(int) * V1SZ);
            memset(v2, -1, sizeof(int) * (V2SZ + V1SZ));
        }

        void populateVectors() {
            for (int i = 0; i < V1SZ ; i++) { v1[i] = rand(); }
            for (int i = 0; i < V2SZ ; i++) { v2[i] = rand(); }
            sort(v1, v1 + V1SZ);
            sort(v2, v2 + V2SZ);
            cout << " V1 =======\n ";
            for (int i = 0; i < V1SZ ; i++) { cout << v1[i] << " " ;}
            cout << " \nV2 =======\n ";
            for (int i = 0; i < V2SZ ; i++) { cout << v2[i] << " " ;}
            
        }

        void mergeInplace() {
            int insertPos = V1SZ + V2SZ -1;
            int v1Pos = V1SZ - 1;
            int v2Pos = V2SZ -1;
            while (v2Pos >= 0 && insertPos - v2Pos > 1) {
                if (v1[v1Pos] >= v2[v2Pos]) {
                    v2[insertPos] = v1[v1Pos];
                    v1Pos--;
                } else {
                    v2[insertPos] = v2[v2Pos];
                    v2Pos--;
                }
                insertPos--;
            }
            if (v2Pos < 0) {
                while (v1Pos >= 0) {
                    v2[insertPos] = v1[v1Pos];
                    v1Pos--;
                    insertPos--;
                }
            }
        }

        bool isSorted() {
            for (int i = 0 ; i < V1SZ + V2SZ - 1; i++) {
                if (v2[i] > v2[i+1]) {
                    cout << "\n__________" << v2[i] <<  "   comes before " <<  v2[i+1] << "__________\n";
                    return false;

                }
            }
            return true;
        }

        void print() {
            cout  << " \n\n merged =======\n";
            for (int i = 0; i < V1SZ + V2SZ ; i++) { cout << v2[i] << " "; }
        } 
};


int main(int argc, char **argv) {
    TwoWayInplaceMerger merger;
    merger.populateVectors();
    merger.mergeInplace();
    bool sorted = merger.isSorted();
    cout << "\n\n\nSorted = " << sorted << "\n\n\n";
    merger.print();
    return 0;
}

