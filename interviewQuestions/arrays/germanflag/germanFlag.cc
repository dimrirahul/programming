#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <iostream>

using namespace std;
class GermanFlag {
    public:
        void swap(int &a, int &b) {
            int t = a;
            a = b;
            b = t;
        }
        
        int findNextInList(int start, int num, vector<int>& v, int mode) {
            for (; start <= v.size(); start++) {
                if (mode == 0 && v[start] < num) break;
                if (mode == 1 && v[start] == num) break;
                if (mode == 2 && v[start] > num) break;
            }
            return start;
        }
        void sortAsGermanFlag(vector<int> v, int num) {
            int less, equal, more;
            less = equal = more = 0;
            for (int i = 0; i < v.size(); i++) {
                if (v[i] < num) less++;
                else if (v[i] == num) equal++;
                else more++;
            }
            printf("less=%d, equals=%d, more=%d\n", less, equal, more);
            int lpos = findNextInList(0, num, v, 0);
            int epos = findNextInList(0, num, v, 1);
            int gpos = findNextInList(0, num, v, 2);
            for (int i = 0; i < v.size(); i++) {
                printf("\nIteration = %d [lpos=%d, epos=%d, gpos=%d] ", i, lpos, epos, gpos);
                for (int i = 0 ; i < v.size(); i++) printf("%d ", v[i]);
                
                if (i < less) {
                    if ( i == lpos) {
                        lpos = findNextInList(lpos + 1, num, v, 0);
                    } else {
                        swap(v[i], v[lpos]);
                        if (v[lpos] == num) {
                            epos = findNextInList( i +1, num, v, 1);
                        } else if (v[lpos] > num && lpos < gpos) {
                            gpos = findNextInList( i +1, num, v, 2);
                        }
                        lpos = findNextInList(lpos+1, num, v, 0);
                    }
                } else if ( i >= less && i < (less + equal)) {
                    if (i == epos) {
                        epos = findNextInList(epos+1, num, v, 1);
                    } else {
                        swap(v[i], v[epos]);
                        gpos = findNextInList( i +1, num, v, 2);
                        epos = findNextInList(epos + 1, num, v, 1);
                    }
                } else {
                    break;
                }
            }
            
            for (int i = 0 ; i < v.size(); i++) printf("%d\n", v[i]);
        }
        
        void sortAsGermanFlagByBook(vector<int> &v, int num) {
            int s, e, l;
            s = e = 0;
            l = v.size();
            while (e < l) {
                if (v[e] < num) {
                    swap(v[e], v[s]);
                    e++; s++;
                } else if (v[e] == num) e++;
                else {
                    swap(v[e], v[l-1]);
                    l--;
                }
            }
            printf("\n");
            for (int i = 0; i < v.size(); i++) printf("%d ", v[i]);
        }
};

GermanFlag gf;
pair < vector<int>, int> getInput() {
    vector<int> res;
    int p;
    int p2;
    scanf("%d\n", &p2);
    scanf("%d\n", &p);
    for (int i = 0; i < p; i++) {
        int t;
        scanf("%d ", &t);
        res.push_back(t);
    }
    return make_pair(res, p2);
}
int main(int argc, char **argv) {
    pair< vector<int> , int> p = getInput();
    gf.sortAsGermanFlagByBook(p.first, p.second);
    return 0;
 }
