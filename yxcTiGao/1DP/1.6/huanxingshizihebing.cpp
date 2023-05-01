#include<iostream>

using namespace std;

const int N = 610;
int a[N];
int f[N][N];

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i ++ ){
        int x;
        scanf("%d",&x);
        a[i] = a[i + n] = x;
    }
    for(int i = 1 ; i < 2 * n ; i ++ )a[i] += a[i - 1];
    for(int len = 1 ; len <= n ; len ++ )
        for(int l = 0 ; l <= 2 * n - len; l ++ ){
            int r = l + len - 1;
            for(int k = l ; k < r ; k ++ ){
                f[l][r] = max(f[l][r] , f[l][k] + f[k + 1][r] + a[r] - a[l - 1]);
            }
        }
    int res = 0;
    for(int i = 0 ; i < n ; i ++ )res = max(res,f[i][i + n - 1]);
    cout << res;
    return 0;
}