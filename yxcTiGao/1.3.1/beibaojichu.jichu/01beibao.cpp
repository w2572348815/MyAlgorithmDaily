#include<iostream>

using namespace std;

const int N = 2010;
int v[N] , w[N];
int f[N][N];

int main(){
    int n , k;
    cin >> n >> k;
    for(int i = 1 ; i <= n ; i ++ )cin >> v[i] >> w[i];
    for(int i = 1 ; i <= n ; i ++ ){
        for(int j = 1 ; j <= k ; j ++){
            f[i][j] = f[i - 1][j];
            if(j >= v[i])f[i][j] = max(f[i][j] , f[i - 1][j - v[i]] + w[i]);
        }
    }
    cout << f[n][k];
    return 0;
}