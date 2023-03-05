#include<iostream>

using namespace std;

const int N = 1010;
int f[N] , a[N];

int main(){
    int n;
    cin >> n;
    int res = 0;
    for(int i = 0 ; i < n ; i ++ )cin >> a[i];
    for(int i = 0 ; i < n ; i ++ ){
        for(int j = 0 ; j < i ; j ++ ){
            if(a[i] > a[j]){
                f[i] = max(f[i], f[j]);
            }
        }
        f[i] += a[i];
        res = max(res , f[i]);
    }
    cout << res;
    return 0;
    
}