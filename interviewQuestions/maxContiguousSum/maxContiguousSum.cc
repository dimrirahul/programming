#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;
const int MIN_VALUE = -100000;
class Segment {
    public:
        int start, end, value;
        Segment() {
            start = end = -1;
            value = 0;
        };

        Segment(int s, int e, int v) {
            start = s;
            end = e;
            value = v;
        }

        void print() {
            printf("start=%d , end=%d, value=%d\n", start, end, value);
        }
};
class MaxConsecutiveSum {
    public:
        vector <int> numV;
        void start() {
            int t;
            scanf("%d\n", &t);
            for (int i = 0;i < t; i++) {
                int p;
                scanf("%d ", &p);
                numV.push_back(p);
            }
            //solveBruteForce();
            solveGreedy();
        }

        void solveBruteForce() {
            int maxV = MIN_VALUE;
            int start, end;
            start = end = 0;
            for (int i = 0; i < numV.size(); i++) {
                int sum = 0;
                for (int j = i; j < numV.size(); j++) {
                    sum += numV[j];
                    if (sum > maxV) {
                        maxV = sum;
                        start = i;
                        end = j;    
                    }
                }
            }

            printf("Max contiguous sum is=%d, start=%d, end=%d\n", maxV, start, end);
        }

        void solveGreedy() {
            vector<Segment> segmentVector;
            int start;
            int sum;
            for (int i = 0; i < numV.size(); i++) {
                if (numV[i] == 0) continue;
                if ( i == 0 ) {
                    sum = numV[i];
                    start = 0;
                } else if (numV[i-1] * numV[i] < 0) {
                    Segment s(start, i, sum);
                    segmentVector.push_back(s);
                    sum = numV[i];
                    start = i;
                } else if (numV[i - 1] * numV[i] > 0) {
                    sum += numV[i];
                }

                if (i == numV.size() -1) {
                    Segment s(start, i + 1, sum);
                    segmentVector.push_back(s);
                }
            }

            for (int i = 0; i < segmentVector.size(); i++) segmentVector[i].print();

            //collese the segments.
            Segment res;
            if (segmentVector.size() == 1) res = segmentVector[0];
            else if (segmentVector.size() == 2) res = segmentVector[0].value > segmentVector[1].value ? segmentVector[0]: segmentVector[1];
            else {
                res = segmentVector[0].value > segmentVector[1].value ? segmentVector[0]: segmentVector[1];
                for (int i = 2; i < segmentVector.size(); i++) {
                    if (segmentVector[i-2].value + segmentVector[i].value + segmentVector[i-1].value > max(segmentVector[i-2].value, segmentVector[i].value)) {
                        segmentVector[i].value += (segmentVector[i-1].value + segmentVector[i -2].value);
                        segmentVector[i].start = segmentVector[i-2].start;
                    }
                    if (res.value < segmentVector[i].value) {
                        res = segmentVector[i];
                    }
                }
            }
            printf("Answer=\n");
            res.print();

        }
            
};

MaxConsecutiveSum mcs;
int main(int argc, char **argv) {
    mcs.start();
    return 0;
}
