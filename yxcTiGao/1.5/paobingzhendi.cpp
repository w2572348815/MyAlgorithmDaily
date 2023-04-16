#include<iostream>
#include<vector>

using namespace std;

const int N = 11 , M = 110;
int d[1 << N];
int f[2][1 << N][1 << N];
vector<int > state;
int n , m;
int cnt[1 << N];

bool check(int u){
    for(int i = 0  ; i < m ; i ++ ){
        if((u >> i & 1) && ((u >> i + 1  & 1)|(u >> i + 2 & 1 )))return false;
    }
    return true;
}
int count(int u){
    int res = 0;
    for(int i = 0 ; i < m ; i ++ )if(u >> i & 1)res ++;
    return res;
}

int main(){
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i ++ ){
        for(int j = 0 ; j < m ; j ++ ){
             char c;
            cin >> c;
            if(c == 'H')d[i] += 1 << j;
        }
    }
    for(int i = 0 ; i < 1 << m ; i ++ ){
        if(check(i)){
            state.push_back(i);
            cnt[i] = count(i);
        }
    }
    for(int i = 1 ; i <= n + 2; i ++ ){
        for(int a = 0 ; a < state.size() ; a ++ )
            for(int b = 0 ; b < state.size() ; b ++ )
                for(int c = 0 ; c < state.size() ; c ++ ){
                    int va = state[a] , vb = state[b] , vc = state[c];
                    if((va & vb) || (va & vc) || (vb & vc))continue;
                    if((vb & d[i - 1])|(vc & d[i]))continue;
                    f[i & 1][b][c] = max(f[i & 1][b][c] , f[i - 1 & 1][a][b] + cnt[vc]);
                }
    }
    cout << f[n + 2 & 1][0][0];    
}