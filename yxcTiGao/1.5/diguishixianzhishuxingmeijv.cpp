#include<iostream>
#include<vector>

using namespace std;

const int N = 15;
vector<int> f;
int n;
void dfs(int u){
    if(u == n + 1){
        for(int i = 0 ; i < f.size() ; i ++ )cout << f[i] << ' ';
        cout  << endl;
        return ;
    }
    f.push_back(u);
    dfs(u + 1);
    f.pop_back();
    dfs(u + 1);
    

}
int main(){
    cin >> n;
    dfs(1);
    return 0;
}



#include<iostream>

using namespace std;

int n;
void dfs(int u ,int state){
    if(u == n){
        for(int i = 0; i < n ; i ++ )
            if(state >> i & 1)cout << i + 1 << ' ';
        cout <<endl;
        return;
    }
    dfs(u + 1 , state);
    dfs(u + 1 , state | 1 << u);
}
int main(){
    cin >> n;
    dfs(0 , 0 );
    return 0;
}