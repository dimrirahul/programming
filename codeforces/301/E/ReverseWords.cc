#include <bits/stdc++.h>


using namespace std;

static bool iswordchar(char c) {
    return ( (c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A') || c == '\'');
}

void reverseWord(char *s, int posStart, int posEnd ) {
    while (posStart < posEnd) {
        swap(s[posStart], s[posEnd]);
        posStart++;
        posEnd--;
    }
}

int findEnd(char *s, int startPos) {
    while (s[startPos] != '\0' && iswordchar(s[startPos])) startPos++;
    return startPos;
}

// Viewing the string as a sentence, reverse the words within the string
// input:  "  Hello it's dev at   Splunk!!"
// output: "  olleH s'ti ved ta   knulpS!!"
static void reversewords(char *s)
{
    int posStart, posEnd, nextStart;
    posStart = posEnd = nextStart = 0;
    while (s[posStart] != '\0') {
        posEnd = findEnd(s, posStart);
        if (posEnd == posStart) { posStart++;}
        else {
            posEnd--;
            reverseWord(s, posStart, posEnd);
            posEnd = posStart = posEnd+1;
        }
    }
}

int main(int argc, char **argv) {
    char buffer[100];
    string s(" Hello it's dev at   Splunk!!");

    for (int i = 0; i < s.size(); i++) {
        buffer[i] = s[i];
    }
    buffer[s.size()] = '\0';
    reversewords(buffer);
    printf("%s\n", buffer);
    return 0;
}
