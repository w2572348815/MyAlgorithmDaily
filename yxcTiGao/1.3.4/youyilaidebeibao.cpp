#include<iostream>
#include<cstring>

using namespace std;

const int N = 110;
int f[N][N];
int e[N] , h[N] , ne[N] , idx , n , m , v[N] , w[N];
void add(int a , int b){
    e[idx] = b , ne[idx] = h[a] , h[a] = idx ++;
}
void dfs(int u){
    for(int i = h[u] ; ~i ; i = ne[i]){
        int son = e[i];
        dfs(e[i]);
        for(int j = m - v[u]; j >= 0 ; j --){
            for(int k = 0 ; k <= j ; k ++ )f[u][j] = max(f[u][j] , f[u][j - k] + f[son][k]);
        }
    }
    for(int i = m ; i >= v[u] ; i --)f[u][i] = f[u][i - v[u]] + w[u];
    for(int i = 0 ; i < v[u] ; i ++ )f[u][i] = 0;
}
int main(){
    cin >> n >> m;
    int root = 0;
    memset(h , -1 , sizeof h);
    for(int i = 1 ; i <= n ;  i ++ ){
        int p;
        cin >> v[i] >> w[i] >> p;
        if(p != -1)add(p , i);
        else root = i;
    }
    dfs(root);
    cout << f[root][m];
    return 0;

}