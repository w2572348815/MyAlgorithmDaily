#include<iostream>

using namespace std;

const int N = 14400;
int v[N] , w[N] , f[N];

int main(){
    int n , m;
    cin >> n >> m;
    int cnt = 0;
    for(int i = 0 ; i < n ; i ++ ){
        int a , b , c;
        cin >> a >> b >> c;
        int k = 1; 
        while(k <= c){
            cnt ++;
            v[cnt] = a * k;
            w[cnt] = b * k;
            c -= k;
            k *= 2;
        }
    }
    n = cnt;
    for(int i = 1 ; i <= n ; i ++ ){
        for(int j = m ; j >= v[i] ; j -- ){
            f[j] = max(f[j] , f[j - v[i]] + w[i]);
        }
    }
    cout << f[m];
    return 0;
}