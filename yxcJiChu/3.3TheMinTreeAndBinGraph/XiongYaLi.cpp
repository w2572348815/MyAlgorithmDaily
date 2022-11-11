/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-11-11 13:24:58
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-11-11 17:03:51
 * @FilePath: \MyAlgorithmDaily\yxcJiChu\3.3TheMinTreeAndBinGraph\XiongYaLi.cpp
 * @Description: 匈牙利算法，在二分图中找最大匹配数
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 510,M = 100010;
int n1,n2,m;
int h[N],e[M],ne[M],idx;
int match[N];
bool st[N];
void add(int a,int b){
    e[idx] = b,ne[idx] = h[a],h[a] = idx++;
}
bool find(int x){
    
    for(int i = h[x];i != -1;i = ne[i]){
        int j = e[i];
        if(!st[j]){
            st[j] = true;
            if(match[j] == 0 || find(match[j])){
                match[j] = x;
                return true;
            }
        }
    }
    return false;
}
int main(){
    cin>>n1>>n2>>m;
    memset(h,-1,sizeof h);
    while(m--){
        int a,b;
        cin>>a>>b;
        add(a,b);
    }
    int res = 0;
    for(int i = 1;i <= n1;i++){
        memset(st,false,sizeof st);
        if(find(i))res++;
    }
    cout<<res;
    return 0;
}