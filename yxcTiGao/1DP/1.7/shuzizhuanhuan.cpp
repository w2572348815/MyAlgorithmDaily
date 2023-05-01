#include<iostream>
#include<cstring>

using namespace std;

const int N = 5e4 + 10;
int h[N],e[N],ne[N],idx;
bool st[N];
int n , sum[N];
int ans;

void add(int a , int b)
{
    e[idx] = b,ne[idx] = h[a],h[a] = idx++;
}

int dfs(int u)
{
    st[u] = true;
    int dist = 0;
    int d1= 0 , d2 = 0;
    for(int i = h[u] ; i != -1 ; i = ne[i])
    {
        int j = e[i];
        int d = 1 + dfs(j); 
        if(d > dist)dist = d;
        if(d > d1)d2 = d1 , d1 = d;
        else if(d > d2)d2 = d;
    }
    ans = max(ans , d1 + d2);
    return dist;
}

int main()
{
    scanf("%d",&n);
    memset(h,-1,sizeof h);
    for(int i = 1 ; i <= n ; i ++ )
        for(int j = 2 ; j <= n / i ; j ++ )
        {
            sum[i * j] += i;
        }
    for(int i = 1 ; i <= n ; i ++ )
    {
        if(sum[i] < i)
        {
            add(sum[i] , i);
        }
    }
    for(int i = 1 ; i <= n ; i ++ )
    {
        if(!st[i])dfs(i);
    }
    cout << ans;
    return 0;
}
