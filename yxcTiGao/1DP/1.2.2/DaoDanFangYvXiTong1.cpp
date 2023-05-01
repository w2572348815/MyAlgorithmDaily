#include<iostream>

using namespace std;

const int N = 55;
int a[N],up[N],down[N];
int res;
int n;
void dfs(int u , int upi , int downi){
    if(upi + downi >= res)return;
    if(u == n)res = upi + downi;
    //把这个点放到上升子序列里面
    int i = 0;
    while(i < upi && a[u] > up[i])i++;
    int t = up[i];
    up[i] = a[u];
    if(i == upi)dfs(u + 1 , upi + 1 , downi);
    else dfs(u + 1 , upi , downi);
    up[i] = t;
    //把这个点放到下降子序列里面
    i = 0;
    while(i < downi && a[u] > down[i])i++;
    t = down[i];
    down[i] = a[u];
    if(i == downi)dfs(u + 1 , upi , downi + 1);
    else dfs(u + 1 , upi , downi);
    down[i] = t;
}
int main(){
    while(cin >> n , n){
        for(int i = 0 ; i < n ; i ++ )cin >> a[i];
        res = n;
        dfs(0 , 0 , 0);
        cout << res << endl;
    }    
    return 0;
}