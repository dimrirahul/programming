#include <iostream>
#include <vector>

using namespace std;
using VS = vector<string>;

struct A {

    string inp;
    void start() {
        cin >> inp;
        vector<string> res;
        res.push_back("");
        VS ans = consume(0, res);
        for (auto it: ans) {
            cout << it << "\n";
        }
    }

    string appendDigit(const string& str, char digit1, char digit2) {
        string temp = str;
        int d = 0;
        d = digit1 - '1';
        if (digit2 != ' ') {
            if (digit1 == '1') d = 10;
            else d = 20;
            d += digit2 - '1';
        }
        temp.push_back(char('a' + d));
        cout << "Returning temp=" << temp << " for str=" << str << " digit1=" << digit1 << " digit2=" << digit2 << "\n";
        return temp;
    }

    bool areValidDigits(char digit1, char digit2) {
        if (digit1 > '2') return false;
        if (digit1 == '2' && digit2 > '6') return false;
        return true;
    }

    VS consumeOne(int pos, const VS& uptilNow) {
        VS res;
        if (pos >= inp.size()) return res;
        for (auto it : uptilNow) {
            res.push_back(appendDigit(it, inp[pos], ' '));
        }
        return consume(pos + 1, res);
    }

    VS consumeTwo(int pos, const VS& uptilNow) {
        VS res;
        if (pos >= inp.size() - 1 || !areValidDigits(inp[pos], inp[pos+1])) return res;
        for (auto it: uptilNow) {
            res.push_back(appendDigit(it, inp[pos], inp[pos+1]));
        }
        return consume(pos + 2, res);
    }
    VS consume(int pos, VS& uptilNow) {
        if (pos >= inp.size()) return uptilNow;
        VS res = consumeOne(pos, uptilNow);
        VS res2 = consumeTwo(pos, uptilNow);
        res.insert(res.end(), res2.begin(), res2.end());
        return res;
    }


};

A a;
int main(int argc, char **argv) {
    a.start();
    return 0;
}
