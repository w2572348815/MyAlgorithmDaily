#include<iostream>

using namespace std;

const int N = 1e5 + 10;
char d[N] , c[N];
int n , m;
int ne[N];

int main(){
    cin >> n >> d + 1 >> m >> c + 1;
    //求next数组
    for(int i = 2 , j = 0 ; i <= n ; i ++ ){
        while(j && d[i] != d[j + 1])j = ne[j];
        if(d[i] == d[j + 1])j++;
        ne[i] = j;
    }
    //kmp匹配过程
    for(int i = 1 , j = 0 ; i <= m ; i ++ ){
        while(j && d[j + 1] != c[i])j = ne[j];
        if(d[j + 1] == c[i])j++;
        if(j == n){
            cout << i - n << ' ';
            j == ne[j];
        }
    }
}