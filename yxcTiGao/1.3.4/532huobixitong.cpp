#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 110 , M = 25000;

int a[N] , f[M];

int main(){
    int n;
    cin >> n;
    while(n -- ){
        int k;
        cin >> k;
        for(int i = 0 ; i < k ; i ++ )cin >> a[i];
        sort(a , a + k);
        memset(f , 0 , sizeof f);
        f[0] = 1;
        int res = 0;
        for(int i = 0 ; i < k ; i ++ ){
            if(!f[a[i]])res ++ ;
            for(int j = a[i] ; j <= a[k - 1] ; j ++ )
                f[j] += f[j - a[i]];
            
        }
        cout << res << endl;
    }
}