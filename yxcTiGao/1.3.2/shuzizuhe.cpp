#include<iostream>

using namespace std;

const int N = 110;
int f[10100];

int main(){
    int n,m;
    cin >> n >> m;
    int res = 0;
    f[0] = 1;
    for(int i = 1 ; i <= n ;  i ++ ){
        int a;
        cin >> a;
        for(int j = m ; j >= a ; j -- ){
            f[j] += f[j - a];
        }
    }
    cout << f[m];
    return 0;
    
}
