#include<iostream>

using namespace std;

const int N = 1e5 + 10;
int a[N] , f[N];

int main(){
    int t;
    cin >> t;
    for(int i = 0 ; i < t ; i ++ ){
        int n;
        cin >> n;
        for(int j = 1 ; j <= n ; j ++ )cin >> a[j];
        for(int j = 1 ; j <= n ; j ++ ){
            f[j] = f[j - 1];
            if(j > 2)f[j] = max(f[j] , f[j - 2] + a[j]);
            else f[j] = max(f[j] , a[j]);
        }
        cout << f[n] << endl;
    }
}