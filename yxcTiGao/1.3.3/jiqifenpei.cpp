#include<iostream>

using namespace std;

const int N = 20;
int w[N][N] , f[N][N] , num[N];

int main(){
    int n , m;
    cin >> n >> m;
    for(int i = 1 ; i <= n ;  i ++ ){
        for(int j = 1 ; j <= m ; j ++ ){
            cin >> w[i][j];
        }
    }
    for(int i = 1 ; i <= n ; i ++ ){
        for(int j = 1 ; j <= m ; j ++ ){
            for(int k = 0 ; k <= j ; k ++ ){
                f[i][j] = max(f[i][j] , f[i - 1][j - k] + w[i][k]);
            }
        }
    }
    cout << f[n][m] << endl;
    int k = m;
    for(int i = n ; i > 0 ; i -- ){
        for(int j = 0 ; j <= k ; j ++ ){
            if(f[i][k] == f[i - 1][k - j] + w[i][j]){
                num[i] = j;
                k -= j;
                //break;
            }
        }
    }
    for(int i = 1 ; i <= n ; i ++ )cout << i << " "<<  num[i] << " " << endl;
    return 0;
}