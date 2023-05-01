#include<iostream>

using namespace std;

const int N = 110;
int d[N][N];
int f[N][N];

int main(){
    int n;
    cin >> n;
    for(int i = 1 ; i <= n ; i ++ ){
        for(int j = 1 ; j <= n ;j ++ ){
            cin >> d[i][j];
        }
    }
    f[1][1] = d[1][1];
    for(int i = 1 ; i <= n; i ++ ){
        for(int j = 1 ; j <= n; j ++){
            if(i != 1){
                if(j == 1){
                    f[i][j] = d[i][j] + f[i - 1][j];
                }else{
                    f[i][j] = d[i][j] + min(f[i - 1][j] , f[i][j - 1]);
                }
            }else{
                if(j!=1)f[i][j] = d[i][j] + f[i][j - 1];
            }
            
        }
    }
    cout << f[n][n];
    return 0;
}