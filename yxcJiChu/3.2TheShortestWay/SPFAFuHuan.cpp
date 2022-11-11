/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-11-05 10:19:01
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-11-11 17:07:10
 * @FilePath: \MyAlgorithmDaily\yxcJiChu\3.2TheShortestWay\SPFAFuHuan.cpp
 * @Description: spfa找负环
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>

using namespace std;

const int N = 100010;
int d[N],h[N],e[N],ne[N],idx,w[N],cn[N];
bool st[N];
int n,m;
void add(int a,int b,int c) {
    w[idx] = c,e[idx] = b,ne[idx] = h[a], h[a] = idx++;
}
bool spfa(){
    queue<int > q;
    for(int i = 1;i <= n;i ++ ){
        q.push(i);
        st[i] = true;
    }  
    while(q.size()){
        int t = q.front();
        q.pop();
        st[t] = false;
        for(int i = h[t] ;i!=-1;i= ne[i]){
            int j  = e[i];
            if(d[j] > d[t] + w[i]){
                d[j] = d[t] + w[i];
                cn[j] = cn[t] + 1;
                if(cn[j] >= n){
                    return true;
                }
                if(!st[j]){
                    st[j] = true;
                    q.push(j);
                }
            }
        }
    }
    return false;
}
int main(){
    cin>>n>>m;
    memset(h,-1,sizeof h);
    for(int i = 0 ; i < m ; i ++){
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
    }
    bool a = spfa();
    if(a)cout<<"Yes";
    else cout<<"false";
    return 0;
}