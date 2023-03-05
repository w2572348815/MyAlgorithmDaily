#include<iostream>

using namespace std;

const int N = 1010;
int f[N][N];

int main(){
    int n , m , k;
    cin >> m >> k >> n;
    for(int i = 1 ; i <= n ; i ++){
        int v1 , v2;
        cin >> v1 >> v2;
        for(int j = m ; j >= v1 ; j --){
            for(int e = k ; e > v2 ; e --){
                f[j][e] = max(f[j][e] , f[j - v1][e - v2] + 1);
            }
        }
    }
    cout << f[m][k];
    int e = k;
    while(e > 0 && f[m][e] == f[m][k])e--;
    cout << " " << k - e;
    return 0;
}