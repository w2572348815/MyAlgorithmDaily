#include<iostream>

using namespace std;

const int N = 1010;
int v[N] , w[N];
int f[N][N];

int main(){
    int n , m;
    cin >> n >> m;
    for(int i = 1; i <= n ; i ++ )cin >> v[i] >> w[i];
    for(int i = 1 ; i<= n ; i++ ){
        for(int j = 0 ; j <= m ; j ++){
            f[i][j] = f[i - 1][j];
            for(int k = 1 ; k * v[i] <= j ; k ++){
                f[i][j] = max(f[i][j] , f[i - 1][j - k * v[i]] +w[i] * k);
            } 
        }
    }
    cout << f[n][m];
    return 0;
}