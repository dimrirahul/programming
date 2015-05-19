#include <bits/stdc++.h>

using namespace std;

class Node {
    public: 
        static int instanceId;
        int v;
        Node() {
            v = Node::instanceId++;
            cout << "Created Node with instance id = " << v << "\n";
        }
        ~Node() {
            cout << "Removing Node with instance id = " << v << "\n";
        }
};

typedef shared_ptr<Node> NodePtr;
int Node::instanceId = 0;
int main(int argc, char **argv) {
    vector<NodePtr> nodeVector(10);
    for (int i = 0; i < 10; i++) {
        nodeVector.push_back(NodePtr(new Node()));
    }
    cout << "Exiting Program\n";
}



