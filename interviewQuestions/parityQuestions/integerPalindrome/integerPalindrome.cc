#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char **argv) {
    int input = atoi(argv[1]);
    cout << "input=" << input << "\n"; 
    int bitPos = 0;
    int div = 1;
    while (input / div > 0) {
        bitPos++;
        div *= 10;
    } 
    bitPos--;
    cout << "bitpos=" << bitPos << "\n";
    int start = 0;
    while (bitPos > start) {
        if ((input / (int) pow(10, bitPos)) != (input % 10 )) {
            cout << "No match\n";
            return 0;
            break;
        }
        input /= 10;
        bitPos -= 2;
        start++;
    }
    cout << "Match\n";
    return 0;

}
