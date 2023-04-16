#include<iostream>
#include<cstring>

using namespace std;

const int N = 23;
int f[N][1 << N];
int n;
int g[N][N];

int main(){
    cin >> n;
    for(int i = 0 ; i < n ; i ++ )
        for(int j = 0 ; j < n ; j ++ )cin >> g[i][j];

    memset(f,0x3f,sizeof f);
    f[0][1] = 0;
    for(int j = 0 ; j < 1 << n ; j ++ )
        for(int i = 0 ; i < n ; i ++ )
            if(j >> i & 1)
                for(int k = 0 ; k < n ; k ++ ){
                    f[i][j] = min(f[i][j] , f[k][j - (1 << i)] + g[i][k]);
                }
    cout << f[n - 1][(1 << n ) - 1];
    return 0;
}