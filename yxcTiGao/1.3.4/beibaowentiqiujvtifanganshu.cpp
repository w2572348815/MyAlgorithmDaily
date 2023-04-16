#include<iostream>
#include<cstring>

using namespace std;

const int N = 1010;
int f[N] , g[N];
int n , m;

int main(){
    cin >> n >> m;
    memset(f,-0x3f,sizeof f);
    f[0] = 0;
    g[0] = 1;
    for(int i = 0 ; i < n ; i ++ ){
        int v , w;
        cin >> v >> w;
        for(int j = m ; j >= v ; j -- ){
            int cnt = 0;
            int res = max(f[j] , f[j - v] + w);
            if(f[j] == res)cnt += g[j];
            if(res == f[j - v] + w)cnt += g[j - v];
            g[j] = cnt;
            f[j] = res;
        }
    }
    int res = 0;
    for(int i = 1 ; i <= m ; i ++ )res = max(res , f[i]);
    int cnt = 0;
    for(int i = 0 ; i <= m ; i ++ ){
        if(res == f[i])cnt += g[i];
    }
    cout << cnt;
    return 0;
}