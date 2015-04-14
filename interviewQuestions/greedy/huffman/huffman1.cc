#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#include <queue>
#include <sstream>
#include <cstdio>

using namespace std;
typedef pair <int, int> PI;
typedef unsigned long long UL;

class Node {
    public:
        int id, pid, lid, rid, w, key;
        Node(int _id, int _w, int _key) {
            id = _id;
            w = _w;
            key = _key;
            pid = lid = rid = -1;
        }
        Node(const Node& o) {
            id = o.id;
            w = o.w;
            lid = o.lid;
            rid = o.rid;
            pid = o.pid;
            key = o.key;
        }

        Node() {
            id = w = lid = rid = pid = key = -1;
        }
        
        bool operator<(Node o) const {
            return w < o.w;
        }

        void print() const{
            printf("[id=%d, key=%c,w=%d,  pid=%d, lid=%d, rid=%d]\n", id, key, w, pid, lid, rid);
        }
};

class Comp {
    public:
        bool operator ()(Node n1, Node n2) const {
            return n1.w > n2.w;
        }
};
class Huffman {
    public:
        priority_queue< Node, vector<Node>, Comp > pq;
        int gId;
        map <int, Node> store;
        int N;
        void start() {
            gId = 0;
            cin >> N;
            for (int i = 0; i < N; i++) {
                char c; int fq;
                cin >> c >> fq;
                int id = gId++;
                Node n(id, fq, c);
                store[n.id] = n;
                //store.insert(make_pair(id, Node(id, fq, c)));
                pq.push(Node(id, fq, c));
            }
           // printStore();
            generateAndPrintBook();
        }

        void generateAndPrintBook() {

            while (!pq.empty()) {
                Node n1 = pq.top();
                cout << "Pop1\n";
                n1.print();
                pq.pop();
                if (!pq.empty()) {
                    Node n2 = pq.top();
                    cout << "Pop2\n";
                    n2.print();
                    pq.pop();
                    int id = gId++;
                    Node n3(id, n1.w + n2.w, 'x');
                    n3.lid = n1.id; n1.pid = n3.id;
                    n3.rid = n2.id; n2.pid = n3.id;
                    store.erase(n2.id); store[n2.id] = n2;
                    store.erase(n1.id); store[n1.id] = n1;
                    store[n3.id] = n3;
                    pq.push(n3);
                } else {
                    break;
                }
            }
            printBook();
        }

        void printBook() {
            cout << "Print Book" << "\n";
            printStore();
            for (int i = 0; i < N; i++) {
                printPrefix(i);
            }
        }

        void printStore() {
            for (map<int, Node>::const_iterator iter = store.begin(); iter != store.end(); iter++) {
                cout << "Key=" << iter->first << " Node=";
                iter->second.print();
            }
        }
        void printPrefix(int id) {
            stringstream ss;
            map<int, Node>::const_iterator node = store.find(id);
            char c = (node->second).key;
            cout << "Prexix printing\n";
            node->second.print();
            while ((node->second).pid != -1) {
                map<int, Node>::const_iterator parent = store.find(node->second.pid);
                if (parent->second.lid == id) {
                    ss << "0";
                } else {
                    ss << "1";
                }
                id = parent->second.id;
                node = store.find(id);
                node->second.print();
            }
            string res = ss.str();
            reverse(res.begin(), res.end());
            cout << "Key = " << c << " string= " << res << "\n";
        }
};

Huffman h;
int main(int argc, char **argv) {
    h.start();
    return 0;
}
