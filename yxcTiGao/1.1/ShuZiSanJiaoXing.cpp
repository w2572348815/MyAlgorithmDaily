#include<iostream>
#include<cstring>
using namespace std;

const int N = 510;
int d[N][N];
int f[N][N];

int main(){
    int n;
    cin >> n;
    memset(d,-0x3f , sizeof d);
    for(int i = 1 ; i <= n ; i ++ ){
        for(int j = 1 ; j <= i ; j ++ ){
            cin >> d[i][j];
        }
    }
    f[1][1] = d[1][1];
    for(int i = 2 ; i <= n ; i ++ ){
        for(int j = 1 ; j <= i ; j ++ ){
            f[i][j] = d[i][j] + max(f[i - 1][j] , f[i - 1][j - 1]);
        }
    }
    int ma = -1e9;
    for(int i = 1 ; i <= n ; i ++ )ma = max(ma , f[n][i]);
    cout << ma;
    return 0;
}