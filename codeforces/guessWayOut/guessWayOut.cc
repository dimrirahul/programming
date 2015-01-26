#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <stack>

using namespace std;
typedef unsigned long long UL;
class CLASS {
    public:
        UL N;
        int h;
        void start() {
            cin >> h >> N;
            solve();
        }

        void solve() {
            UL res = 0;
            int d = 0;
            UL one = (UL)1;
            N = (one << h) + N -1;
            //cout << "N = " << N << "\n";
            vector<UL> parentV;
            UL t = N;
            while (t > 0) {
                parentV.push_back(t);
                t /= 2;
            }
            /*
            cout << "parent vector \n";
            for (int i = 0 ; i < parentV.size(); i++) cout << parentV[i] << "\n";
            cout << "parent vector end \n";
            */
            //We start off from the parent.
            //Direction of travel from parent is as follows.
            //if parent is rightChild of grandParent then next direction is left.
            //if parent is leftChild of grandParent then next direction is right. 
            //Lets say we are the leftChild and next direction is left then there are no issues, we simply do down one level.
            //but lets say we are the rightChild and next direction is left, this would mean that we will visit all the nodes of the left subtree, before visiting right.
            //in that case we have to increment the visited nodes by number of nodes of left subtree.
            int pos = parentV.size() - 1;
            UL parent = parentV[pos];
            bool wasParentRightChild = true;
            while (pos != 0) {
                //cout << "Spinning\n";
                UL child = parentV[pos - 1];
                bool isLeftChild = parent * 2 == child;
                if ((isLeftChild && wasParentRightChild) || (!isLeftChild && !wasParentRightChild) ) {
                } else {
                    UL nodesInOtherSubtree = (one << (h - d) ) - 1;
                    res += nodesInOtherSubtree;
                }
                d++;
                pos--;
                res++;
                parent = child;
                wasParentRightChild = !isLeftChild;
            }
            cout << res << "\n";

        }

};

CLASS kt;
int main(int argc, char **argv) {
    kt.start();
    return 0;
}
