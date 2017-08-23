#include <iostream>
#include <vector>

using namespace std;


class Solution {
    public:
	bool isChar(char c) {
	    return (c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A') || (c <= '9' && c >= '0');
	}

	pair<int, int> findWordEnd(int startPos, string& s) { //returns start, end+1;
	    pair<int, int> pi = make_pair(startPos, s.size());
	    while (startPos < s.size() && s[startPos] == ' ') startPos++;
	    pi.first = startPos;
	    while (startPos < s.size() && isChar(s[startPos])) startPos++;
	    pi.second = startPos;
	    return pi;
	}

	void reverseWord(string& s, pair<int, int> pi) {
	    int b = pi.first;
	    int e = pi.second - 1;
	    while (b < e) {
		char t = s[b];
		s[b] = s[e];
		s[e] = t;
		b++;
		e--;
	    }
	}
	bool hasOnlySpaces(const string& s) {
	    for (auto it : s) {
		if (it != ' ') return false;
	    }
	    return true;
	}
	void reverseWords(string &s) {
	    if (hasOnlySpaces(s)) s = "";
	    int pos = 0;
	    while (pos < s.size()) {
		pair<int, int> pi = findWordEnd(pos, s);
		reverseWord(s, pi);
		pos = pi.second;
	    }
	}
};


int main() {
	Solution s;
	string s1 = "the sky is blue";
	cout << "'" << s1 << "'\n";
	s.reverseWords(s1);
	cout << "'" << s1 << "'\n";
	return 0;
}
