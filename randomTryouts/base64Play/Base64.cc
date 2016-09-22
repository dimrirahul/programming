#include <assert.h>
#include <array>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct Base64 {
  bool isBitSet(const string& input, int pos) {
    int bytePos = pos / 8;
    int bitPos = pos % 8;
    int p = 1 << 7;
    return input[bytePos] & (p >> bitPos);
  }

  void pushChar(int k, string& out) {
    char c;
    if (k < 26) {
      c = 'A' + k;
    } else if (k < 52) {
      c = 'a' + (k - 26);
    } else if (k < 62) {
      c = '0' + (k - 52);
    } else if (k == 62) {
      c = '+';
    } else if (k == 63) {
      c = '/';
    } else {
      assert(0);
    }
    out.push_back(c);
  }

  bool encodeString(const string& input, string& out) {
    int t;
    for (int i = 0; i < input.size() * 8; i++) {
      if (i % 6 == 0) {
        if (i != 0) {
          pushChar(t, out);
        }
        t = 0;
      }
      t = t << 1;
      if (isBitSet(input, i)) {
        t = t | 1;
      }
    }
    for (int i = input.size() * 8; i % 6 != 0; i++) t = t << 1;
    pushChar(t, out);
    while (out.size() % 4 != 0) out.push_back('=');
    return true;
  }

  bool decodeString(const string& input, string& out) { return false; }
};

int main() {
  Base64 b;
  string s;

  getline(cin, s);
  string out;
  if (b.encodeString(s, out)) {
    cout << "Encoded string :" << out << "\n";
  } else {
    cout << "Encoding failed\n";
  }
  return 0;
}
