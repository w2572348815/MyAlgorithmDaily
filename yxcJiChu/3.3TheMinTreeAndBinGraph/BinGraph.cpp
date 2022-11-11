/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-11-11 08:23:30
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-11-11 17:02:27
 * @FilePath: \MyAlgorithmDaily\yxcJiChu\3.3TheMinTreeAndBinGraph\BinGraph.cpp
 * @Description: 染色法判断是否是二分图
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 100010,M = 200010;
int h[N],e[M],ne[M],idx;
int n,m;
int color[N];
void add(int a,int b){
    e[idx] =b,ne[idx] = h[a],h[a] = idx++;
}
bool dfs(int i,int c){
    color[i] = c; 
    for(int j = h[i];j != -1;j = ne[j]){
        int m = e[j];
        if(!color[m]){
            if(!dfs(m,3-c)){
                return false;
            }
        }else{
            if(color[m] == c)return false;
        }
    }
    return true;
}
int main(){
    cin>>n>>m;
    memset(h,-1,sizeof h);
    while(m--){
        int a, b;
        cin>>a>>b;
        add(a,b);
        add(b,a);
    }
    int flag = 1;
    for(int i = 1; i <= n;i ++){
        if(!color[i]){
            if(!dfs(i,1)){
                flag = 0;
                break;
            }
        }
    }
    if(flag)cout<<"Yes";
    else cout<<"No";
    return 0;
}