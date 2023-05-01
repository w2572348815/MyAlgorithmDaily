#include<iostream>

using namespace std;

const int N = 210;
int n;
int a[N];
int f[N][N];

int main(){
    scanf("%d",&n);
    for(int i = 1 ; i <= n ; i ++ ){
        int x;
        scanf("%d",&x);
        a[i] = a[i + n] = x;
    }
    for(int len = 3 ; len <= n + 1 ; len ++ )
        for(int l = 1 ; l <= 2*n-len+1 ; l ++ )
        {
            int r = l + len - 1;
            for(int k = l + 1 ; k < r ; k ++ )
            {
                f[l][r] = max(f[l][r] , f[l][k] + f[k][r] + a[l] * a[r] * a[k]);
            }
        }
    int res = 0;
    for(int i = 1 ; i <= n ; i ++ )res = max(res,f[i][i + n]);
    printf("%d",res);
    return 0;
}