#include<iostream>

using namespace std;

const int N = 3e5 + 10;
int s[N];
int q[N];
int n, m;

int main()
{
    scanf("%d%d",&n,&m);
    for(int i = 1 ; i <= n ; i ++ )
    {
        scanf("%d",&s[i]);
        s[i] += s[i - 1];
    }
    int res = -2e9;
    int hh =  0, tt = -1;
    for(int i = 1 ; i <= n ; i ++ )
    {
        if(hh <= tt && q[hh] < i - m)hh ++ ;
        while(hh <= tt && s[q[tt]] >= s[i] )tt--;
        q[++tt] = i;
        res = max(res , s[i] - s[q[hh]]);
    }
    cout << res;
    return 0;
}