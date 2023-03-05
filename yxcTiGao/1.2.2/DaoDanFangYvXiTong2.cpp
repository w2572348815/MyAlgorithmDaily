#include<iostream>

using namespace std;

const int N = 55;
int a[N],down[N],up[N];
int n;
bool dfs(int depth , int u , int upi , int downi){
    if(upi + downi > depth)return false;
    if(u == n)return true;
    //当前数据放入上升组中
    int i = 0;
    while(i < upi && a[u] < up[i])i++;
    int t = up[i];
    up[i] = a[u];
    bool flag;
    if(i == upi)flag =  dfs(depth , u + 1 , upi + 1 , downi);
    else flag = dfs(depth ,u + 1 , upi , downi);
    up[i] = t;
    if(flag)return flag;
    //当前数据放入下降组中
    i = 0;
    while(i < down[i] && a[u] > down[i])i ++;
    t = down[i];
    down[i] = a[u];
    if(i == downi)flag = dfs(depth , u + 1 , upi , downi + 1);
    else flag = dfs(depth , u + 1 , upi , downi);
    down[i] = t;
    if(flag)return flag;
    return false;
}
int main(){
    while(cin >> n , n){
        for(int i = 0 ; i < n ; i ++ )cin >> a[i];
        int depth = 0;
        while(!dfs(depth , 0 , 0 , 0 ))depth++;
        cout << depth << endl;
    }
    return 0;
    
}