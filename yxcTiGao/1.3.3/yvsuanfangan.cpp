#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int N = 32010;
int f[N];
typedef pair<int, int> PII;
PII master[65];
vector<PII> servent[65];

int main()
{
    int n, m;
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
    {
        int v, w, q;
        cin >> v >> w >> q;
        if (q == 0)
            master[i] = {v, v * w};
        else
            servent[q].push_back({v, v * w});
    }
    for (int i = 1; i <= n; i++)
    {   
        if(master[i].first)
        for (int j = m; j >= master[i].first; j--)
        {

            int a, b;
            for (int k = 0; k < 1 << servent[i].size(); k++)
            {
                a = master[i].first, b = master[i].second;
                for (int l = 0; l < servent[i].size(); l++)
                {
                    if (k >> l & 1)
                    {
                        a += servent[i][l].first;
                        b += servent[i][l].second;
                    }
                }
            }
            if (j >= a)
                f[j] = max(f[j], f[j - a] + b);
        }
    }
    cout << f[m];
    return 0;
}