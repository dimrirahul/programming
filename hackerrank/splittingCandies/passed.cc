#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <array>
using namespace std;

const int MX_SIZE = (int)(1e5) + 10;

array<int, MX_SIZE> inp, sdl, sdr;
using LL = long long;
int main() {
    int N; cin >> N;
    for (int i = 0; i < N; i++) cin >> inp[i];
    sdl[0] = sdr[N-1] = 0;
    for (int i = 1; i < N; i++) {
        sdl[i] = inp[i-1] < inp[i] ? sdl[i-1] + 1: 0;
        sdr[N - i - 1] = inp[N - i - 1] > inp[N - i] ? sdr[N-i] + 1: 0;
    }
    LL res = 0;
    for (int i = 0; i < N; i++) res += max(sdl[i], sdr[i]) + 1;
    cout << res << "\n";
    
    return 0;
}
