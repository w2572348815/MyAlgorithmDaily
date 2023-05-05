#include<iostream>

using namespace std;

const int N = 5e4 + 10;
int w[N],f[N],q[N];

int main()
{
    int n, m;
    scanf("%d%d",&n,&m);
    for(int i = 1 ; i <= n ; i ++ )scanf("%d",&w[i]) , w[i] += w[i - 1];
    int hh = 0 , tt = 0;
    for(int i = 1 ; i <= n ; i ++ )
    {
        if(hh <= tt && q[hh] < i - m)hh++;
        f[i] = max(f[i - 1] , f[q[hh] - 1] + w[i] - w[q[hh]]);
        while(hh <= tt && f[i - 1] - w[i] >= f[q[tt] - 1] - w[q[tt]])tt--;
        q[++tt] = i;
        
    }
    cout << f[n];
    return 0;
}