#include <iostream>
#include <vector>

using namespace std;

class SomeClass {
public:
    void someFunction(int i) {}
    void someFunction() {}
};

SomeClass someObject;
vector<int> intVector;
int main() {
    someObject.someFunction();
    someObject.someFunction(6);
    for(int i = 0; i < 100; intVector.push_back(i), i++);
    cout << "Hello, World!" << endl;
    for (int i = 0; i < intVector.size(); i++, cout << i << " ");
    return 0;
}