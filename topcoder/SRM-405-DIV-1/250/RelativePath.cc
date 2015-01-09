#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <sstream>

using namespace std;

typedef vector<int> VI;
typedef vector<string> VS;



class RelativePath {
    int findCommonLength(string path, string currentDir) {
        int pos = 0;
        int slashPath = 0;
        while (path[pos] == currentDir[pos] && pos < min(path.size(), currentDir.size())) {
            if (path[pos] == '/') {
                slashPath = pos;
            }
            pos++;
        }
        return slashPath;

    }
    public:
        string makeRelative(string path, string currentDir) {
            if (currentDir == string("/")) {
                return path.substr(1);
            }
            currentDir += '/';
            int pos = findCommonLength(path, currentDir);
            if (pos == currentDir.size() -1) {
                return path.substr(pos + 1);
            }

            int slashCountCurrentDir = 0;
            for(int j = currentDir.size()-2; j > pos; j--) {
                if (currentDir[j] == '/') {slashCountCurrentDir++;}
            }

            string slashes = "../";
            for (int i = 0; i < slashCountCurrentDir; i++) {
                slashes += "../";
            }

            string finalPath = slashes + path.substr(pos + 1);
            return finalPath;

        }
};
