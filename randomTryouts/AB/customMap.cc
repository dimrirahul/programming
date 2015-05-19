#include <bits/stdc++.h>

using namespace std;
class Container {
    public:
        int a, b, c;
        Container() {}
        bool operator==(const Container& other) const {
            return a == other.a && b == other.b && c == other.c;
        }
};

class Hasher {
    public:
        size_t operator()(const Container& key) const {
            hash<int> hash_fn;
            return (hash_fn(key.a) << 4) | ( hash_fn(key.b));
        }
};

typedef unordered_map<Container, int, Hasher> ContainerMap;
int main(int argc, char **argv) {
    ContainerMap conMap;
    Container a;
    /*
    Container b;
    Container c;
    */
    conMap[a] = 1;
    return 0;
}
    
