/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-11-03 19:13:15
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-11-09 15:37:05
 * @FilePath: \MyAlgorithmDaily\yxc\3.1BFSAndDFSAndMap\MapDFS.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 100010,M = 2*N;
int h[N],e[M],ne[M],idx,n;
int ans = N;
bool st[N];
void add(int a,int b){
    e[idx] = b,ne[idx] = h[a],h[a] = idx++;
}
//返回u作为根节点子树的节点长度
int dfs(int u){
    st[u] = true;
    int sum = 1,res = 0;
    for(int i = h[u];i!=-1;i= ne[i]){
        int x = e[i];
        if(!st[x]){
            int s = dfs(x);
            sum += s;
            res = max(res,s);
        }
    }
    res = max(res,n- sum);
    ans = min(ans,res);
    return sum;
}
int main(){
    cin>>n;
    memset(h, -1,sizeof h);
    for(int i = 0;i < n - 1;i++){
        int a,b;
        cin>>a>>b;
        add(a,b);
        add(b,a);
    }
    dfs(1);
    cout<<ans<<endl;
    return 0;
}