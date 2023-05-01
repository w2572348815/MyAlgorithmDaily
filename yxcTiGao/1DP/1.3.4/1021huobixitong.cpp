#include<iostream>

using namespace std;

const int N = 3010;
int f[N];

int main(){
    int n , m;
    cin >> n >> m;
    f[0] = 1;
    for(int i = 1 ; i <= n ; i ++ ){
        int a;
        cin >> a;
        for(int j = a ; j <= m; j ++){
            f[j] += f[j - a];
        }
    }
    cout << f[m];
    return 0;

}