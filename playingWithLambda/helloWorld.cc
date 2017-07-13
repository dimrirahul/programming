#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
#define ALL(X) (X).begin(),(X).end()

int main() {
    auto helloLambda = []() {cout << "Hello world\n";};
    helloLambda();

    auto sumLambda = [](int x, int y) { return x + y;};
    auto sumLambda1 = [](int x) { return x + x; };
    cout << sumLambda(2, 4) << "\n";
    cout << sumLambda1(2) << "\n";

    long sum = 0;
    vector<int> vi;
    for (int i = 0; i < 50; i++) vi.push_back(i+1);

    auto sv = [&sum] (int x) { sum += x; };
    for_each(vi.begin(), vi.end(), sv);

    cout << "Sum=" << sum << "\n";

    sum = 0;
    sum = accumulate(ALL(vi), 0);
    cout << "Sum=" << sum << "\n";




    return 0;
}
