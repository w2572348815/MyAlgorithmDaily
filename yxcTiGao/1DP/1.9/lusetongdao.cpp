#include<iostream>

using namespace std;

const int N = 5e4 + 10;
int q[N],w[N],f[N];

int n ,m;
bool check(int x)
{
    int hh = 0 , tt = 0;
    for(int i = 1 ; i <= n ; i ++ )
    {
        if(q[hh] < i - x - 1)hh++;
        f[i] = f[q[hh]] + w[i];
        while(hh <= tt && f[q[tt]] >= f[i])tt--;
        q[++tt] = i;
    }
    for(int i = n - x ; i <= n ; i ++ )
        if(f[i] <= m)
            return true;
    return false;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i = 1 ; i <= n ; i ++ )scanf("%d",&w[i]);
    int l = 0 , r = n;
    while(l < r)
    {
        int mid = l + r >> 1;
        if(check(mid)){
            r = mid;
        }else {
            l = mid + 1;
        }
    }
    cout << l;
    return 0;
}