#include<iostream>
#include<cstring>

using namespace std;

const int N = 10010 , M = 2 * N;
int h[N] , e[M] , ne[M] , w[M] , idx;
int n;
int d1[N] , d2[N] , up[N] , p1[N] , p2[N];
int INF = 0x3f3f3f3f;

void add(int a, int b, int c)
{
    w[idx] = c , e[idx] = b , ne[idx] = h[a] , h[a] = idx++;
}

int dfs_d(int u , int father)
{
    d1[u] = d2[u] = -INF;
    for(int i = h[u] ; i != -1 ; i = ne[i] )
    {
        int j = e[i];
        if(j == father)continue;
        int d = dfs_d(j , u) + w[i];
        if(d > d1[u])d2[u] = d1[u] , d1[u] = d , p2[u] = p1[u] , p1[u] = j;
        else if(d > d2[u])d2[u] = d , p2[u] = j;
    }
    if(d1[u] == -INF)d1[u] = d2[u] = 0;
    return d1[u];
}

void dfs_up(int u , int father)
{
    for(int i = h[u] ; i != -1 ; i = ne[i])
    {
        int j = e[i];
        if(j == father)continue;
        up[j] = -INF;
        if(p1[u] != j)up[j] = max(up[u] , d1[u]) + w[i];
        else  up[j] = max(up[u] , d2[u]) + w[i];
        dfs_up(j , u);
    }
}
int main()
{
    scanf("%d",&n);
    memset(h,-1,sizeof h);
    for(int i = 1 ; i < n ; i ++)
    {
        int a, b, c;
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c) , add(b,a,c);
    }
    dfs_d(1 , -1);
    dfs_up(1 , -1);
    int res = INF;
    for(int i = 1 ; i <= n ; i ++ )res = min(res , max(d1[i],up[i]));
    printf("%d",res);
    return 0;
}
