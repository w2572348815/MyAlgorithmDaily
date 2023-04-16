#include<iostream>
#include<cstring>

using namespace std;

const int N = 1e5 + 10;

int h[N] , w[2 * N] , ne[2 * N] , e[2 * N] , idx;
int n;
int ans;

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}
int dfs(int u , int father)
{
    int dist = 0;
    int d1 = 0 , d2 = 0;
    for(int i = h[u] ; i != -1 ; i = ne[i])
    {
        int j = e[i];
        if(j == father)continue;
        int d = dfs(j , u) + w[i];
        if(d > d1)d2 = d1 , d1 = d;
        else if(d > d2)d2 = d;
        dist = max(dist , d);
    }
    ans = max(ans , d1 + d2);
    return dist;
}
int main()
{
    scanf("%d",&n);
    memset(h, -1, sizeof h);
    for(int i = 1 ; i < n ; i ++ )
    {
        int a, b, c;
        scanf("%d%d%d",&a,&b,&c);
        add(a, b, c);
        add(b, a, c);
    }
    dfs(1 , -1);
    printf("%d",ans);
    return 0;
}
