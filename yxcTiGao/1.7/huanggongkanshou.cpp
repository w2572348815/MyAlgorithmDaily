#include<iostream>
#include<cstring>

using namespace std;

const int N = 1510;

int h[N],ne[N],e[N],idx,id[N];
int n;
int f[N][3];
bool st[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u)
{
    f[u][2] = id[u];
    for(int i = h[u] ; i != -1 ; i = ne[i])
    {
        int j = e[i];
        dfs(j);
        f[u][0] += min(f[j][2],f[j][1]);
        f[u][2] += min(min(f[j][0],f[j][1]),f[j][2]);
    }
    f[u][1] = 1e9 + 10;
    for(int i = h[u]; i != -1 ; i = ne[i] )
    {
        int j = e[i];
        f[u][1] = min(f[u][1] , f[j][2] + f[u][0] - min(f[j][1],f[j][2]));
    }
}

int main()
{
    memset(h,-1,sizeof h);
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i ++ )
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        id[a] = b;
        for(int j = 0 ; j < c ; j ++ )
        {
            int d;
            scanf("%d",&d);
            add(a,d);
            st[d] = true;
        }
    }
    int root = 1;
    while(st[root])root ++;
    dfs(root);
    cout << min(f[root][1],f[root][2]);
    return 0;
}