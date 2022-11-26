#include<iostream>

using namespace std;

const int N = 25000;
int dp[N];
int v[N],w[N],s[N];

int main(){
    int n, m ;
    scanf("%d%d",&n,&m);
    int cnt = 0;
    for(int i = 1 ; i <= n ; i ++ ){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        int k = 1;
    
        while(k<=c){
            cnt ++;
            v[cnt] = a*k;
            w[cnt] = b*k;
            c -= k;
            k *= 2;
        }
        if(c > 0){
            cnt++;
            v[cnt] = a*c;
            w[cnt] = b*c;
        }
    }
    n = cnt;
    for(int i = 1 ; i <= n ;i ++ )
        for(int j = m ; j >= v[i] ; j -- ){
            dp[j] = max(dp[j],dp[j - v[i]] + w[i]);
        }
    cout<<dp[m];
    return 0;
}