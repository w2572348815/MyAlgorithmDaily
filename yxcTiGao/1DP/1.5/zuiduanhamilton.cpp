#include<iostream>
#include<cstring>

using namespace std;

const int N = 23;
int f[1 << N][N];
int n;
int g[N][N];

int main(){
    cin >> n;
    for(int i = 0 ; i < n ; i ++ )
        for(int j = 0 ; j < n ; j ++ )cin >> g[i][j];
    memset(f , 0x3f , sizeof f);
    f[1][0] = 0;
    for(int i = 0 ; i < 1 << n ; i ++ )
        for(int j = 0 ; j < n ; j ++ ){
            if(i >> j & 1){
                for(int k = 0 ; k < n ; k ++ ){
                    f[i][j] = min(f[i][j] , f[i - (1 << j)][k] + g[j][k]);
                }
            }
        }
    cout << f[(1 << n ) - 1][n - 1];
    return 0;
}