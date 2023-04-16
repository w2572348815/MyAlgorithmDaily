#include<iostream>
#include<cstring>

using namespace std;
const int N = 210;
int h[N],e[N],ne[N],w[N],idx;
int n,m;
int f[N][N];
void dfs(int u ,int father)
{
    for(int i = h[u] ; ~i ; i = ne[i])
    {
        if(e[i] == father)continue;
        int j = e[i];
        dfs(j,u);
        for(int k = m ; k >= 0 ; k -- )
        {
            for(int l = 0 ; l < k ; l ++ )
            {
                f[u][k] = max(f[u][k] , f[u][k - l - 1] + f[j][l] + w[i]);
            }
        }
    }

}
void add(int a, int b, int c)
{
    w[idx] = c,e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
int main()
{
    memset(h,-1,sizeof h);
    scanf("%d%d",&n,&m);
    for(int i = 1 ; i < n ; i ++ )
    {
        int a, b, c;
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c) , add(b,a,c);
    }
    dfs(1,-1);
    cout << f[1][m];
    return 0;
}