#include<iostream>

using namespace std;

const int N = 1010;
int f[N][N];

int main(){
    int n , m , k ; 
    cin >> n >> m >> k;

    
    for(int i = 1 ; i <= n ; i ++ ){
        int a , b , c;
        cin >> a >> b >> c;
        for(int j = m ; j >= a ; j --){
            for(int e = k ; e >= b ; e --){
                f[j][e] = max(f[j][e] , f[j - a][k - b] + c);
            }
        }
    }
    cout << f[m][k];
    return 0;
}