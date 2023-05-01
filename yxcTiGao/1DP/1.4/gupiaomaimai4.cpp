#include<iostream>
#include<cstring>

using namespace std;

const int N = 1e5 + 10 , M = 110;
int w[N];
int n , m;
int f[N][M][2];

int main(){
    cin >> n >> m;
    memset(f , -0x3f , sizeof f);
    for(int i = 0 ; i <= n ; i ++ )f[i][0][0] = 0;

    for(int i = 1 ; i <= n ; i ++ )cin >> w[i];
    for(int i = 1 ; i <= n ; i ++ ){
        for(int j = 1 ; j <= m ; j ++ ){
            f[i][j][0] = max(f[i - 1][j][1] + w[i] , f[i - 1][j][0]);
            f[i][j][1] = max(f[i - 1][j][1] , f[i - 1][j - 1][0] - w[i]);
        }
    }
    int res = 0;
    for(int i = 1 ; i <= m ; i ++ )res = max(res , f[n][i][0]);
    cout << res;
    return 0;
}