#include<iostream>

using namespace std;

const int N = 1010;
int f[N];

int main(){
    int n;
    cin >> n;
    int a[4] = {10 , 20 , 50 , 100};
    f[0] = 1;
    for(int i = 0 ; i < 4 ; i ++ ){
        for(int j = 0 ; j <= n ; j ++ ){
            if(j >= a[i])f[j]  += f[j - a[i]];
        }
    }
    cout << f[n];
    return 0;
}