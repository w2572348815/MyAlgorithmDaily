#include<iostream>

using namespace std;

const int N = 2010;
int w[N] , v[N] , s[N] , f[N];

int main(){
    int n , m;
    cin >> n >> m ;
    for(int i = 1 ; i <= n ; i ++ )cin >> v[i] >> w[i] >> s[i];
    for(int i = 1 ; i <= n ; i ++ ){
        for(int j= m ; j >= v[i] ; j -- ){
            for(int k = 1; k * v[i] <= j && k <= s[i] ; k++){
                f[j] = max(f[j] , f[j - k*v[i]] + k * w[i]);
            }
        }
    }
    cout << f[m];
    return 0;
}