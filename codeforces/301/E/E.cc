#include<bits/stdc++.h>

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define FORU(I,A,B) for(unsigned int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define REPU(I,N)   FORU(I,0,N)
#define ALL(A)     (A).begin(), (A).end()

using namespace std;

typedef pair <int, int> PI;
typedef vector <int> VI;
typedef vector <string> VS;

typedef long long LL;
const bool dbg = true;
class Node {
    public:
        int l, r, h, v;
        Node() {
            l = r = -1;
            v = h = 0;
        }
};
typedef map<int, Node> Ftree;
class E {
    public:

        map<int, int> rankByNum;
        map <int, int> posMap;
        Ftree ftree;
        VI inputVector;

        void insertPos() {
            int a, b;
            cin >> a >> b;
            int val1, val2;
            val1 = posMap.count(a) == 0? a : posMap[a];
            val2 = posMap.count(b) == 0? b : posMap[b];

            posMap[a] = val2;
            posMap[b] = val1;

            if (dbg) {
                cout << "Inserted " << val2 << "in pos = " << a << "\n";
                cout << "Inserted " << val1 << "in pos = " << b << "\n";
            }
        }

    //returns the id of the node added.
    int addToTree(int v, int nodeVal=0) {
        //Check if the node exists.
        //if the node exists then go to left or right.
        //if you are going right then increment v.
        if (ftree.count(nodeVal) > 0 ) {
            Ftree::iterator it = ftree.find(nodeVal);
            if (v < it->second.v) {
                it->second.l = addToTree(v, (nodeVal << 1) + 1);
            } else {
                it->second.r = addToTree(v, (nodeVal << 1) + 2);
                it->second.h++;
            }
        } else {
            Node n;
            n.v = v;
            ftree[nodeVal] = n;
        }
        return nodeVal;
        //on returning update the count of elements that are more than the current node.
        //if it does not exist add a new node.
        //and set number of elements more than that as zero.
    }

    //returns the number of elements more than v in the tree.
    int getRank(int v, int nodeVal = 0) {
        int res = 0;
        //look for the node if this is the node then return.
        //if going left then add to res (1 + numNodes in right tree).
        while(ftree[nodeVal].v != v) {
            if (v < ftree[nodeVal].v) {
                res += (ftree[nodeVal].h + 1);
                nodeVal = (nodeVal << 1) + 1;
            } else {
                nodeVal = (nodeVal << 1) + 2;
            }
        }
        res += ftree[nodeVal].h;
        return res;
    }

    /*
    void printTree(int nodeVal=0) { 
        if (ftree.count(nodeVal) > 0) {
            cout << "Node Value = " << ftree[nodeVal].v << " More Nodes = " << ftree[nodeVal].h << "\n";
            printTree((nodeVal << 1) +1);
            printTree((nodeVal << 1) +2);
        }
    }


    void testAddAndGetRank() {
        vector<int> v;
        for (int i = 1; i <= 1000; i++) {
            v.push_back(i);
        }
        random_shuffle(v.begin(), v.end());
        REP(i, v.size()) {
            cout << "Adding to tree " << v[i] << "\n";
            addToTree(v[i]);
        }
        //printTree();
        for (int i = 0; i < v.size(); i++) {
            if (1000 - v[i] != getRank(v[i])) {
                cout << "No match " << v[i] << " gives rank = " << getRank(v[i]) << "\n";
            }
        }
        cout << "Test Done\n";
    }
    */
    void populateInp() {
        for (map<int, int>::const_iterator it = posMap.begin(); it != posMap.end(); it++) {
            inputVector.push_back(it->second);
        }
        calculateReducedVector();
        if (dbg) {
            cout << "\n====== Input Array =====\n";
            REP (i, inputVector.size()) {
                cout << inputVector[i] << " ";
            }
            cout << "\n===========\n";
        }
    }

    void calculateReducedVector() {
        vector<PI> temp;
        REP(i, inputVector.size()) {
            temp.push_back(make_pair(inputVector[i], i));
        }
        sort(ALL(temp));
        REP(i, temp.size()) {
            inputVector[temp[i].second] = i+1;
            rankByNum[temp[i].first] = i+1;
        }
    }


    int solveInversionPair() {
        int res = 0;
        for (int i = inputVector.size() -1; i >= 0; i--) {
            addToTree(inputVector[i]);
            res += (inputVector.size() -1 - i - getRank(inputVector[i]));
        }
        if (dbg) cout << "Inversion Pair res = " << res << "\n";
        return res;
    }

    int solveInversion() {
        int res = 0;
        //This is to find the inversions of a single number with the ones that did not move from their place.
        //Given a misplaced number find inversions, had there been only that number that moved around.
        for (map<int, int>::const_iterator it = posMap.begin(); it != posMap.end(); it++) {
            int num = it->second;
            int deltaPos = abs(num - it->first) -1;
            int elementsInBetween = abs(getRank(rankByNum[it->first]) - getRank(rankByNum[it->second])) -1;
            if (dbg) cout << "index=" << it->first << " num= " << it->second << " delta=" << deltaPos << " elementsInBetween=" << elementsInBetween << "\n";
            res  += (deltaPos - elementsInBetween);
        }
        //Then subtract the numbers that moved in between the original position and the current one.
        if (dbg) cout << "Inversion res = " << res << "\n";
        return res;
    }
    int solve() {
        //Solve input vector for inversion.
        //Solve case only one element has moved.
        int v1, v2;
        v1 = solveInversionPair();
        v2 = solveInversion();
        if (dbg) {
            cout << "V1 = " << v1 << " V2 = " << v2 << "\n";
        }
        return v1 + v2;

    }
    
    void start() {
        int t; cin >> t;
        REP(i, t) {
            insertPos();
        }
        populateInp();       
        cout << solve() << "\n";
    }    
};

E t;

void generateOut() {
    int num = 1e5;
    cout << num << "\n";
    for (int i = 1; i < num+1; i++) {
        cout << i << " " << num-i << "\n";
    }
}

int main(int argc, char **argv) {
    //generateOut();
    t.start();
    //t.testAddAndGetRank();
    return 0;
}
