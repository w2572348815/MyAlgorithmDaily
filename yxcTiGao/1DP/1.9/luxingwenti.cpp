#include<iostream>

using namespace std;

const int N = 2e6 + 10;

int o[N],d[N];
int n;
bool st[N];
int q[N];
typedef long long LL;
LL w[N];
int main()
{
    scanf("%d",&n);
    for(int i = 1 ; i <= n ; i ++ )scanf("%d%d",&o[i],&d[i]);
    for(int i = 1 ; i <= n ; i ++ )w[i] = w[i + n] =  o[i] - d[i];
    for(int i = 1 ; i <= 2 * n ; i ++ )w[i] += w[i - 1];
    int hh = 0 , tt = -1;
    for(int i = 1 ; i <= 2 * n ; i ++ )
    {
        if(hh <= tt && q[hh] <= i - n)hh++;
        while(hh <= tt && w[q[tt]] >= w[i])tt--;
        q[++tt] = i;
        if(i >= n && w[q[hh]] - w[i - n] >= 0)st[i - n + 1] = true;
    }
    d[0] = d[n];
    for(int i = 1 ; i <= n ; i ++ )w[i] = w[i + n] = o[i] + d[i - 1];
    for(int i = 1 ; i <= 2 * n ; i ++ )w[i] += w[i - 1];
    hh = 0 , tt = -1;
    for(int i = 1 ; i <= 2 * n ; i ++ )
    {
        if(hh <= tt && q[hh] <= i - n)hh++;
        while(hh <= tt && w[q[tt]] >= w[i])tt--;
        q[++tt] = i;
        if(i >= n && w[i] - w[q[hh]] >= 0)st[i] = true;
    }
    for(int i = 1 ; i <= n ; i ++ )
        if(st[i])cout << "TAK\n";
        else cout << "NIE\n";
    return 0;
}