#include<iostream>
#include<vector>

using namespace std;

const int N = 13;
int d[N][1 << N];
int n , m;
int fa[N];
vector<int > head[1 << N] , state;

bool check(int u){
    for(int i = 0 ; i < m ; i ++ ){
        if((u >> i & 1) && (u >> i + 1 & 1))return false;
    }
    return true;
}
int main(){
    cin >> n >> m;
    for(int i = 0 ; i < n ; i ++ )
        for(int j = 0 ; j < m ; j ++ ){
            int a;
            cin >> a;
            fa[i] += !a << j;            
        }
    for(int i = 0 ; i < 1 << m ; i ++ ){
        if(check(i)){
            state.push_back(i);
        }
    }
    for(int i = 0 ; i < state.size() ; i ++ ){
        for(int j = 0 ; j < state.size() ; j ++ ){
            int a = state[i] , b = state[j];
            if((a & b) == 0)head[i].push_back(j);
        }
    }
    d[0][0] = 1;
    for(int i = 1 ; i <= n + 1 ; i ++ ){
        for(int j = 0 ; j < state.size() ; j ++ ){
            for(int k : head[j]){
                if(state[j] & fa[i - 1])continue;
                d[i][j] += d[i - 1][k];
            }
        }
    }
    cout << d[n + 1][0];
}