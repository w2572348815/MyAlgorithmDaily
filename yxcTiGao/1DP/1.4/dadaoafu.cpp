#include<iostream>

using namespace std;

const int N = 1e5 + 10;
int w[N];
int f[N][2];

int main(){
    int t;
    cin >> t;
    for(int j = 0 ; j < t ; j ++ ){
        int n;
        cin >> n;
        int sum = 0;
        for(int i = 1 ; i <= n ; i ++ )cin >> w[i];
        for(int i = 1 ; i <= n ; i ++ ){
            f[i][0] = max(f[i - 1][1] , f[i - 1][0]);
            f[i][1] = f[i - 1][0] + w[i];
        }
        cout << max(f[n][1] , f[n][0]) << endl;

    }
    return 0;
}