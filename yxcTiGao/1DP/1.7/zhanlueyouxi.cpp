#include<iostream>
#include<cstring>

using namespace std;

const int N = 1510;
int n;
int h[N],e[N],ne[N],idx;
bool st[N];
int f[N][2];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u)
{
    f[u][0] = 0;
    f[u][1] = 1;
    for(int i = h[u] ; ~i ; i = ne[i])
    {
        int j = e[i];
        dfs(j);
        f[u][0] += f[j][1];
        f[u][1] += min(f[j][0],f[j][1]);
    }
}
int main()
{
    
    while(cin >> n)
    {
        memset(h,-1,sizeof h);
        memset(st,false,sizeof st);
        int x;
        for(int i = 0 ; i < n ; i ++ )
        {
            int id, cnt;
            scanf("%d:(%d)",&id,&cnt);
            while(cnt--)
            {
                int ver;
                scanf("%d",&ver);
                add(id,ver);
                st[ver] = true;
            }
        }
        int root = 0;
        while(st[root])root++;
        dfs(root);
        printf("%d\n",min(f[root][0],f[root][1]));
    }
    return 0;
}