#include<iostream>

using namespace std;

const int N = 1010;
int f1[N], f2[N];
int a[N];

int main(){
    int n;
    cin >> n;
    for(int i = 1 ; i <= n ; i ++ )cin >> a[i];
    for(int i = 1 ; i <= n ; i ++ ){
        f1[i]= 1 , f2[i] = 1;
        for(int j = 1 ; j < i ; j ++ ){
            if(a[i] > a[j])f1[i] = max(f1[i] , f1[j] + 1);
            if(a[i] < a[j])f2[i] = max(f2[i] , f2[j] + 1);
        }
    }
    int res = 0;
    for(int i = 1 ; i <= n ; i ++ ){
        res = max(res , f1[i] + f2[i] - 1);
    }
    cout << res;
    
    return 0;

    
}