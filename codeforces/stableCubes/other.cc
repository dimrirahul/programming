#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <sstream>
#define MP make_pair
using namespace std;

const int MAXN = 1e5 + 5, mod = 1e9 + 9;
int ix[] = {-1, 0, 1}, dwny = -1, upy = 1, x[MAXN], y[MAXN];
set<int> s;
map<pair<int, int>, int> m; //ÿ�������Ӧ�ı��
bool mark[MAXN];

bool free(int t)
{
    for(int i = 0; i < 3; i++)
    {
        int h = m[MP(x[t] + ix[i], y[t] + upy)] - 1;
        if(h >= 0 && !mark[h])
        {
            int ans = 0;
            for(int j = 0; j < 3; j++)
            {
                int h = m[MP(x[t] + ix[i] + ix[j], y[t])] - 1;
                //int h = m[MP(x[t] + ix[i] + ix[j], y[t] + upy + dwny)] - 1;
                if(h >= 0 && !mark[h])
                    ans++;
            }
            if(ans == 1)
                return false;
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
        m[MP(x[i], y[i])] = i + 1;
    }
    for(int i = 0; i < n; i++)
        if(free(i))
            s.insert(i);
    long long ans = 0, trn = 0;;
    while(s.size())
    {
        int t;
        if(trn % 2 == 0)
            t = *s.rbegin();
        else
            t = *s.begin();
        s.erase(t);
        if(!free(t))
            continue;
        trn++;
        mark[t] = true;
        cout << "Picking t = " << t << "\n";
        ans = (ans * n + t) % mod;
        for(int i = 0; i < 3; i++)
        {
            int h = m[MP(x[t] + ix[i], y[t] + dwny)] - 1;
            if(h >= 0 && free(h) && !mark[h])
                s.insert(h);
        }
    }
    cout << ans << endl;
    return 0;
}
