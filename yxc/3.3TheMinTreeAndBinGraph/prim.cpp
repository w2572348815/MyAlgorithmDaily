/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-11-10 15:26:17
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-11-10 20:18:39
 * @FilePath: \MyAlgorithmDaily\yxc\3.3TheMinTreeAndBinGraph\prim.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 510,INF = 0x3f3f3f3f;

int n,m;
int g[N][N];
int dist[N];
bool st[N];
int prim(){
    int res = 0;
    for(int j = 0; j < n;j++){
        int m = -1; 
        for(int i = 1; i <= n;i++){
            if(!st[i]&&(m == -1 || dist[m] > dist[i]))m = i;
        }
        if(j && dist[m] == INF)return INF;
        if(j)res += dist[m];
        for(int i = 1;i <= n;i++){
            dist[i] = min(dist[i],g[m][i]);
        }
        st[m] = true;
    }
    return res;

}
int main(){
    memset(g,0x3f,sizeof g);
    memset(dist,0x3f,sizeof dist);
    cin>>n>>m;
    while(m--){
        int x,y,z;
        cin>>x>>y>>z;
        g[x][y] =g[y][x] =  min(g[x][y],z);
    }
    int x = prim();
    cout<<x;
    return 0;

}
