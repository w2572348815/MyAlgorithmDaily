#include<iostream>

using namespace std;

const int N = 30010;

int f[N];
int main(){
    int n , m;
    cin >> m >> n;
    for(int i = 1 ; i <= n ; i ++ ){
        int a , b;
        cin >> a >> b;
        b = a * b; 
        for(int j = m ; j >= a ; j -- ){
            f[j] = max(f[j] , f[j - a] + b);
        }
    }
    cout << f[m];
    return 0;
}