/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-11-04 16:25:04
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-11-11 17:05:03
 * @FilePath: \MyAlgorithmDaily\yxcJiChu\3.2TheShortestWay\DijkstraCommon.cpp
 * @Description: 图中找到根节点的最小距离
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 510;
int tu[N][N],n,m,d[N];
bool st[N];
int dijkstra(){
    memset(d,0x3f,sizeof d);
    d[1] = 0;
    for(int i = 0;i < n;i++){
        int t = -1;
        for(int j = 1;j <= n;j++){
            if(!st[j] && (t == -1 || d[j] < d[t])){
                t = j;
            }
        }
        st[t] = true;
        for(int j = 1;j <= n;j++){
            if(tu[t][j] + d[t] < d[j]){
                d[j] = tu[t][j] + d[t];
            }
        }
    }
    if(d[n]== 0x3f3f3f3f){
        return -1;
    }else{
        return d[n];
    }
}
int main(){
    cin>>n>>m;
    memset(tu,0x3f,sizeof tu);
    for(int i = 0 ; i < m; i++){
        int a,b,c;
        cin>>a>>b>>c;
        tu[a][b] = min(tu[a][b],c);
    }
    int ans = dijkstra();
    cout<<ans;
}