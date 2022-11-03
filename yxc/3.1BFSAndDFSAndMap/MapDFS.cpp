#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 100010;

int n;
int h[N],e[N*2],ne[N*2],idx;
bool st[N];
int ans = N;
void add(int x,int y){
    e[idx] = y,ne[idx] = h[x],h[x] = idx++;
}
int dfs(int i){
    st[i] = true;
    int sum = 1,res = 0;
    for(int j = h[i];j != -1;j = ne[j]){
        int k = e[i];
        if(!st[k]){
            int s = dfs(k);
            res = max(res,s);
            sum += s;
        }
    }
    res = max(res,n - sum);
    ans = min(res,ans);
    return sum;
}
int main(){

    cin>>n;
    memset(h,-1,sizeof h);
    int a,b;
    for(int i = 1;i < n;i++){
        cin>>a>>b;
        add(a,b);
        add(b,a);
    }
    dfs(1);
    cout<<ans;
}