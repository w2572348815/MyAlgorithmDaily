#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

const int N = 12;
int f[N][1 << N];
vector<int > head[1 << N];
int n , m;
bool st[N];

int main(){
    while(cin >> n >> m  , n | m){
        
        

        for(int i = 0 ; i < 1 << n ; i ++ ){
            bool is_valid = true;
            int cnt = 0;
            for(int j = 0 ; j < n ; j ++ ){
                if(i >> j & 1){
                    if(cnt & 1)is_valid = false;
                    cnt = 0;
                }else{
                    cnt++;
                }
            }
            if(cnt & 1)is_valid = false;
            st[i] = is_valid;
        }

        for(int i = 0 ; i < 1 << n ; i ++ ){
            head[i].clear();
            for(int j = 0 ; j < 1 << n ; j ++ ){
                if((i & j) == 0 && st[i | j])head[i].push_back(j);
            }
        }

        memset(f , 0 , sizeof f);
        f[0][0] = 1;
        for(int i = 1 ; i <= m; i ++ ){
            for(int j = 0 ; j < 1 << m ; j ++ ){
                for(auto k : head[j]){
                    f[i][j] += f[i - 1][k];
                }
            }
        }
        cout << f[m][0] << endl;
    }
}