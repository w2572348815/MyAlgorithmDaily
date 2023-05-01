#include<iostream>

using namespace std;

const int N = 1010;
int f[N] , v[N] , w[N];

int main(){
    int n , m ;
    cin >> n >> m;
    for(int i = 1; i <= n ; i ++ )cin >> v[i] >> w[i];
    for(int i = 1 ; i <= n ; i ++ ){
        for(int j = 0 ; j <= m ; j ++ ){
            if(j >= v[i])f[j] = max(f[j] , f[j - v[i]] + w[i]);
        }
    }
    cout << f[m];
    return 0;
}