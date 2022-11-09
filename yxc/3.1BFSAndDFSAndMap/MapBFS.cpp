/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-11-04 09:07:08
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-11-09 15:34:43
 * @FilePath: \MyAlgorithmDaily\yxc\3.1BFSAndDFSAndMap\MapBFS.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 100010;
int n,m;
int h[N],e[N],ne[N],idx;
int d[N] ;
int q[N];

void add(int a,int b){
    e[idx] = b,ne[idx] = h[a],h[a] = idx++;
}
void bfs(){
    int hh = 0, tt = 0;
    q[0] = 1;

    while(hh<=tt){
        int t = q[hh++];
        for(int i = h[t];i!= -1;i = ne[i]){
            int x = e[i];
            if(d[x]==-1){
              
                d[i] = d[t] + 1;
                q[++tt] = x;
            }
        }
    }
}
int main(){
    cin>>n>>m;
    int a,b;
    memset(d,-1,sizeof d);
    memset(h,-1,sizeof h);
    d[1] = 0;
    for(int i  =0;i < m;i++){
        cin>>a>>b;
        add(a,b);
    }
    bfs();
    cout<<d[n]<<endl;
    return 0;

}