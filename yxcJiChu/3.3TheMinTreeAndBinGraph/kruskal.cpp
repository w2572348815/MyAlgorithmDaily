/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-11-10 20:47:41
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-11-11 17:03:10
 * @FilePath: \MyAlgorithmDaily\yxcJiChu\3.3TheMinTreeAndBinGraph\kruskal.cpp
 * @Description: 稀疏图找最小生成树
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 200010;

int n,m;
int p[N];
struct edge{
    int a,b,w;
    bool operator< (const edge&W)const{
        return w<W.w;
    }
}edges[N];

int find(int x){
    if(p[x]!= x)p[x] = find(p[x]);
    return p[x];
}
int main(){
    cin>>n>>m;
    for(int i = 0; i < m; i++){
        int a,b,w;
        cin>>a>>b>>w;
        edges[i].a = a;
        edges[i].b = b;
        edges[i].w = w;
    }
    sort(edges,edges + m);
    for(int i= 1; i <= n; i++){
        p[i] = i;
    }
    int res = 0,cnt = 0;
    for(int i = 0; i< m;i ++){
        int a = edges[i].a,b = edges[i].b,w = edges[i].w;
        a = find(a);
        b = find(b);
        if(a!=b){
            p[a] = b;
            res += w;
            cnt ++; 
        }
    }
    if(cnt < n - 1)puts("cuowu");
    else printf("%d",res);
    return 0;

}