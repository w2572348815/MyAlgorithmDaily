/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-11-05 09:41:33
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-11-11 17:06:38
 * @FilePath: \MyAlgorithmDaily\yxcJiChu\3.2TheShortestWay\SPFA.cpp
 * @Description: 可找有负权边的最短路
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;

const int N = 100010;
int h[N],e[N],ne[N],idx,d[N],n,m,w[N];
bool st[N];
void add(int a,int b,int c){
    e[idx] = b,ne[idx] = h[a],w[idx] = c,h[a] = idx++;
}
int spfa(){
   
    memset(d,0x3f,sizeof d);
    d[1] = 0;
    queue<int > q;
    q.push(1);
    st[1] = true;
    while(q.size()){
        int t = q.front();
        q.pop();
        st[t] = false;
        for(int i = h[t];i!=-1;i = ne[i]){
            int j = e[i];
            if(d[j] > d[t] + w[i]){
                d[j] = d[t] + w[i];
                if(!st[j]){
                    st[j] =true;
                    q.push(j);
                }
            }
        }
        
    }
    if(d[n] == 0x3f3f3f3f)return -1;
    else return d[n];
}
int main(){
    cin>>n>>m;
     memset(h,-1,sizeof h);
    for(int i = 0 ; i < m ; i++){
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
    }
    int t = spfa();
    if(t == -1)cout<<"impossible";
    else cout<<t;
}