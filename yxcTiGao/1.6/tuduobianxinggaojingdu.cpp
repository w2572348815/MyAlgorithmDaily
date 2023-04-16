#include<iostream>
#include<cstring>

using namespace std;

int n;
const int N = 110 , M = 35;
int a[N];
typedef long long LL;
LL f[N][N][M];
void add(LL a[],LL b[]){
    LL temp[M];
    for(int i = 0 , t = 0; i < M ; i ++ ){
        t += a[i] + b[i];
        temp[i] = t % 10;
        t /= 10;
    }
    memcpy(a,temp,sizeof temp);
}
void mul(LL a[] , LL b){
    LL temp[M];
    for(int i = 0 , t = 0 ; i < M ; i ++ ){
        t += a[i] * b;
        temp[i] = t % 10;
        t /= 10;
    }
    memcpy(a,temp,sizeof temp);
}
void print(LL a[]){
    int k = M - 1;
    while(k >= 0 && !a[k])k--;
    while(k >= 0){
        cout << a[k--];
    }
}
int cmp(LL a[],LL b[]){
    for(int i = M - 1 ; i >= 0 ; i -- ){
        if(a[i] < b[i])return 1;
        if(a[i] > b[i])return -1;
    }
    return 0;
}
int main(){
    scanf("%d",&n);
    for(int i = 1 ; i <= n ; i ++ ){
        scanf("%d",&a[i]);
    }
    for(int len = 3 ; len <= n ; len ++ )
        for(int l = 1 ; l <= n-len+1 ; l ++ )
        {
            int r = l + len - 1;
            f[l][r][M - 1] = 1;
            LL temp[M];
            for(int k = l + 1; k < r ; k ++ )
            {
                memset(temp,0,sizeof temp);
                temp[0] = a[k];
                mul(temp,a[r]);
                mul(temp,a[l]);
                add(temp,f[l][k]);
                add(temp,f[k][r]);
                if(cmp(temp,f[l][r]) == 1){
                    memcpy(f[l][r],temp,sizeof temp);
                }
            }
        }

    print(f[1][n]);
    return 0;
}