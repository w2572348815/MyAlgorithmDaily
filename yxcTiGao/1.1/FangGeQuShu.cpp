#include<iostream>

using namespace std;

 const int N = 15 , M = 25;
 int w[N][N];
 int f[M][N][N];

 int main(){
    int n ;
    cin >> n;
    int a , b , c;
    while(cin >> a >> b >> c , a || b || c){
        w[a][b] = c;
    }
    for(int k = 2 ; k <= 2 * n ; k ++ ){
        for(int i1 = 1 ; i1 <= n ; i1 ++ ){
            for(int i2 = 1 ; i2 <= n ; i2 ++ ){
                int j1 = k - i1 , j2 = k - i2;
                if(j1 >= 1 && j1 <= n && j2 <= n && j2 >= 1){
                    int t = w[i1][j1];
                    if(i1 != i2)t += w[i2][j2];
                    int &e = f[k][i1][i2];
                    e = max(e , f[k - 1][i1][i2] + t);
                    e = max(e , f[k - 1][i1][i2 - 1] + t);
                    e = max(e , f[k - 1][i1 - 1][i2] + t);
                    e = max(e , f[k - 1][i1 - 1][i2 - 1] + t);
                }
            }
        }
    }
    cout << f[n + n][n][n];
    return 0;
 }
 