#include<iostream>
#include<vector>

using namespace std;

const int N = 13 , M = 110;
int n , m;
int f[N][M][1 << N];
vector<int > state;
vector<int > head[1 << N];
int cnt[1 << N];

bool check(int s){
    for(int i = 0 ; i < n ; i ++ ){
        if(s >> i & 1 && s >> i + 1 & 1)return false;
    }
    return true;
}
int count(int i){
    int res = 0;
    for(int j = 0 ; j < n ; j ++ ){
        if(i >> j & 1)res ++;
    }
    return res;
}
int main(){
    cin >> n >> m;
    for(int i = 0 ; i < 1 << n ;  i ++ ){
        if(check(i)){
            state.push_back(i);
            cnt[i] = count(i);
        }
    }
    for(int i = 0 ; i < state.size() ; i ++ ){
        for(int j = 0 ; j < state.size() ; j ++ ){
            int a = state[i] , b = state[j];
            if(check(a | b) && !(a & b)){
                head[i].push_back(j);
            }
        }
    }
    f[0][0][0] = 1;
    for(int i = 1 ; i <= n + 1 ; i ++ ){
        for(int j = 0 ; j <= m ; j ++ ){
            for(int k = 0 ; k < state.size() ; k ++ ){
                for(int u = 0 ; u < head[k].size() ; u ++ ){
                    if(cnt[state[k]] <= j){
                        f[i][j][k] += f[i - 1][j - cnt[state[k]]][head[k][u]];
                    }
                }
            }
        }
    }
    cout << f[n + 1][m][0];
}