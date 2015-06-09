#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <sstream>
#include <set>

using namespace std;
const int SZ = 100;
const int numElements = 10;


class Segment {
    public:
        int start, end;
        Segment(int _start, int _end) {
            start = _start;
            end = _end;
        }

        string getPrintableString() {
            stringstream ss;
            if (start == end) {
                ss << start;
            } else {
                ss << start << "-" << end;
            }
            return ss.str();
        }
};

void printRes(vector<int>& inputNos) {
    cout << "Input Vector\n";
    for(auto& i: inputNos) cout << i << ",";
    cout << "\n";
    bool temp[SZ];
    memset(temp, 0, sizeof(bool) * SZ);
    for (auto& i: inputNos) temp[i] = true;
    vector<Segment> res;
    for(int i = 0; i < SZ;) {
        if (temp[i]) {
            i++;
        } else {
            int start = i;
            while (i < SZ && !temp[i]) i++;
            int end = i-1;
            res.push_back(Segment(start, end));
        }
    }
    if (res.size() > 0) {
        for (int i = 0; i < res.size() - 1; i++) cout << res[i].getPrintableString() << ",";
        cout << res[res.size()-1].getPrintableString();
    } 
}

void printResOptimal(vector<int>& inputNos) {
    int start = 0;
    cout << "\n";
    vector<Segment> res;
    for (auto& i: inputNos) {
        auto _end = i - 1;
        if (_end >= start) {
            res.insert(end(res), Segment(start, _end));
        }
        start = i+1;
    }
    if (start < SZ) res.insert(end(res), Segment(start, SZ-1));
    if (res.size() > 0) {
        for (auto i = 0; i < res.size() - 1; i++) cout << res[i].getPrintableString() << ",";
        cout << res[res.size()-1].getPrintableString();
    }
}

int main(int argc, char **argv) {
    set<int> v;
    for (; v.size() < numElements;) {
        v.insert(rand() % 100);
    }
    vector<int> inputNos {0, 1, 2, 45, 46, 50, 55, 99};
    //inputNos.insert(inputNos.begin(), v.begin(), v.end());
    printRes(inputNos);
    printResOptimal(inputNos);
    return 0;

}
