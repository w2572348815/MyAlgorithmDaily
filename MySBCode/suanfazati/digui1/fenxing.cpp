#include<iostream>

using namespace std;

const int N = 1010;

char d[N][N];
void dfs(int u){
    if(u == 1){
        d[0][0] = 'X';
        return;
    }
    dfs(u - 1);
    int len = 1;
    for(int i = 0 ; i < u - 2 ; i ++)len *= 3;
    int dx[4] = {2 , 1 , 2 , 0} , dy[4] = {0 , 1 , 2 , 2};
    for(int i = 0 ; i < 4 ; i ++ )
        for(int j = 0 ; j < len ; j ++ )
            for(int k = 0 ; k < len ; k ++ )
                d[dx[i] * len + j][dy[i] * len + k] = d[j][k];
}
int main(){
    int n;
    dfs(7);
    while(cin >> n , ~n){
        int len = 1;
        for(int i = 0 ; i < n -  1; i ++ )len *= 3;
        for(int i = 0 ; i < len ; i ++ ){
            for(int j = 0 ; j < len ; j ++)
                if(d[i][j] == 'X')cout << d[i][j];
                else cout << ' ';
        cout << endl;
        }
        cout<<'-'<<endl;
    }
}