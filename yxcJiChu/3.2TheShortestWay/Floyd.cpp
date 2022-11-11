/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-11-05 13:28:13
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-11-11 17:06:59
 * @FilePath: \MyAlgorithmDaily\yxcJiChu\3.2TheShortestWay\Floyd.cpp
 * @Description: 多源最短路
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>
#include<cstring>
#include<algorithm>
const int N  = 210,INF = 1e9;
using namespace std;

int d[N][N];
int n,m,q;
void floyd(){
    for(int k = 1;k <= n;k ++)
        for(int i = 1;i <= n;i++)
            for(int j = 1; j <= n;j++)
                d[i][j] = min(d[i][j],d[i][k] + d[k][j]);

}
int main(){
    cin>>n>>m>>q;
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= n;j++){
            if(j == i)d[i][j] = 0;
            else d[i][j] = INF;
        }
    while(m--){
        int a,b,w;
        cin>>a>>b>>w;
        d[a][b] = min(d[a][b],w);
    }
    floyd();
    while(q--){
        int a,b;
        cin>>a>>b;
        if(d[a][b]>INF/2)cout<<"NO";
        else cout<<d[a][b];
    }
}
