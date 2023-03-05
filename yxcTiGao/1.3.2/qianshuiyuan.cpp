#include<iostream>
#include<cstring>

using namespace std;

const int N = 80;
int f[N][N];
int n , m  , k;
int main(){
    cin >> n >> m >> k;
    memset(f,0x3f,sizeof f);
    f[0][0] = 0;
    for(int i = 0 ; i < k ; i ++ ){
        int a , b , c;
        cin >> a >> b >> c;
        for(int j = n ; j >= 0 ; j -- ){
            for(int l = m ; l >= 0 ; l -- ){
                f[j][l] = min(f[j][l] , f[max(0 , j - a)][max(0 , l - b)] + c);
            }
        }
    }
    cout<<f[n][m];
    return 0;
}