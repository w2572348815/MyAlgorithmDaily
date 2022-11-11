/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-11-03 13:31:55
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-11-03 19:11:41
 * @FilePath: \MyAlgorithmDaily\yxc\1.7BFSAndDFSAndMap\BFSZouMiGong.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 10;
int n,m;
int d[N][N],tu[N][N];
typedef pair<int,int> PII;
PII q[N*N];
int bfs(){
    int tt = 0,hh = 0;
    q[0] = {0,0};
    memset(d,-1,sizeof d);
    d[0][0] = 0;
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    while(hh<=tt){
        PII t = q[hh++];
        for(int i  = 0; i < 4;i++){
            int x = t.first + dx[i];
            int y = t.second + dy[i];
            if(x >= 0 && x < n && y >= 0 && y < m && d[x][y] == -1 && tu[x][y] == 0){
                d[x][y] = d[t.first][t.second] + 1;
                q[++tt] = {x,y};
            }
        }
    }
    return d[n-1][m-1];
}
int main(){
    cin>>n>>m;
    for(int i = 0;i < n;i++)
        for(int j = 0;j < m ;j++)
            cin>>tu[i][j];
    int a = bfs();
    cout<<a;
}