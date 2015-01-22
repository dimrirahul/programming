#ifndef _LL_H_
#define _LL_H_

#include <iostream>
#include <memory>
#include <vector>
#include <cstdlib>
#include <cstdio>

using namespace std;

class Node;
typedef shared_ptr<Node> NodePtr;

class Node {
    public:
        int v;
        NodePtr next;
        Node() {
            v = 0;
            next = NULL;
        }

        Node(int _v) {
            v = _v;
        }

        void print() {
            printf("[Value = %d ", v);
            if (next != NULL) {
                printf(" Next is Not Null]\n");
            } else {
                printf(" Next is Null]\n");
            }
        }

};

class Ll {
    public:
        NodePtr root;
        NodePtr getNode(int v = 0) {
            return NodePtr(new Node(v));
        }
        void addNode(int v) {
            NodePtr node = getNode(v);
            if (root == NULL) {
                root = node;   
            } else {
                NodePtr t = root;
                while(t->next != NULL){
                    t = t->next;   
                }
                t->next = node;
            }
        }

        void printList() {
            NodePtr t = root;
            while(t != NULL) {
                t->print();
                t = t->next;
            }
        }

        pair<NodePtr, NodePtr> reverseList(NodePtr fakeRoot) {
            if (fakeRoot->next == NULL) return make_pair(fakeRoot, fakeRoot);
            pair<NodePtr, NodePtr> p = reverseList(fakeRoot->next);
            p.second->next = fakeRoot;
            fakeRoot->next = NULL;
            p.second = fakeRoot;
            return p;
        }

        void reverseListIteratively() {
            if (root == NULL || root->next == NULL) return;
            NodePtr n1 = root, n2 = NULL;
            do {
                if (n2 == NULL) {
                    n2 = n1;
                    n1 = n1->next;
                    n2->next = NULL;
                } else {
                    NodePtr n3;
                    n3 = n1->next;
                    n1->next = n2;
                    n2 = n1;
                    n1 = n3;
                }
            } while (n1 != NULL);
            root = n2;
        }
 
        void reverseList() {
            pair<NodePtr, NodePtr> p = reverseList(root);
            root = p.first;
        }

        NodePtr getSegment(NodePtr t, int value) {
            NodePtr p = t;
            if (t == NULL) return t;
            NodePtr prev = NULL;
            do {
                prev = t;
                t = t->next;
            } while(t != NULL && t->v <= value);
            /*
            printf("Adding Following Nodes in this segment\n");
            while(p!= t) {
                p->print();
                p = p->next;
            }
            printf(" Segment print done\n");
            */
            return prev;
        }
        NodePtr mergeList(NodePtr n1, NodePtr n2) {
            if (n1 == NULL) return n2;
            if (n2 == NULL) return n1;
            NodePtr fakeRoot = NULL;
            NodePtr end = NULL;
            if (n1->v < n2->v) {
                fakeRoot = n1;
                end = getSegment(n1, n2->v);
                n1 = end->next;
            } else {
                fakeRoot = n2;
                end = getSegment(n2, n1->v);
                n2 = end->next;
            }
            end->next = mergeList(n1, n2);
            NodePtr p = fakeRoot; 
            return fakeRoot;
        }

        void mergeList(Ll& other) {
            root = mergeList(root, other.root);
        }

        /**
         * Basically points the end-of-list's next to the node.
         */
        void makeListCircular(int nodeValue) {
            NodePtr t = root;
            NodePtr l = NULL;
            while (t->next != NULL) {
                if (t->v == nodeValue) l = t;
                t = t->next;
            }
            t->next = l;
        }

        bool hasLoop() {
            NodePtr fast = root, slow = root;
            bool res = false;
            if (fast == NULL || fast->next == NULL || fast->next->next == NULL) return false;
            while (fast != NULL) {
                if (fast->next == NULL || fast->next->next == NULL) return false;
                fast = fast->next->next;
                slow = slow->next;
                if (slow == fast) return true;
            }
            return false;
        }
};

#endif //_LL_H_
