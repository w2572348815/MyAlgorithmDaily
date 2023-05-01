#include<iostream>

using namespace std;

int n;
const int N = 110;
int a[N];
int f[N][N];

int main(){
    scanf("%d",&n);
    for(int i = 1 ; i <= n ; i ++ ){
        scanf("%d",&a[i]);
    }
    for(int len = 3 ; len <= n ; len ++ )
        for(int l = 1 ; l <= n-len+1 ; l ++ )
        {
            int r = l + len - 1;
            f[l][r] = 1e9 + 1;
            for(int k = l + 1; k < r ; k ++ )
            {
                f[l][r] = min(f[l][r] , f[l][k] + f[k][r] + a[k] * a[l] * a[r]);
            }
        }

    cout << f[1][n];
    return 0;
}