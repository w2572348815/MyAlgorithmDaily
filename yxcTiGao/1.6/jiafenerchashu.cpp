#include<iostream>

using namespace std;

const int N = 40;
int a[N];
int n;
int f[N][N] , g[N][N];
void dfs(int l , int r){
    if(l > r)return;
    cout << g[l][r] << ' ';
    dfs(l , g[l][r] - 1);
    dfs(g[l][r] + 1 , r);
}
int main(){
    scanf("%d",&n);
    for(int i = 1 ; i <= n ; i ++ )scanf("%d",&a[i]);
    for(int len = 1 ; len <= n ; len ++ )
        for(int l = 1 ; l <= n - len + 1; l ++ )
        {
            int r = l + len - 1;
            if(len == 1)
            {
                f[l][l] = a[l];
                g[l][l] = l;
            }
            else{
                for(int k = l ; k <= r ; k ++ ){
                    int left = k == l ? 1 : f[l][k - 1];
                    int right = k == r ? 1 : f[k + 1][r];
                    int x = left * right + a[k];
                    if(f[l][r] < x){
                        f[l][r] = x;
                        g[l][r] = k;
                    }
                }
            }
        }
    
    cout << f[1][n] << endl;
    dfs(1,n);
    return 0;
}