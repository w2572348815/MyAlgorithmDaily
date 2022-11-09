/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-11-04 18:40:39
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-11-09 15:30:18
 * @FilePath: \MyAlgorithmDaily\yxc\3.2TheShortestWay\DijkstraHeap.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>

using namespace std;

const int N = 100010;
int e[N],ne[N],h[N],idx,w[N];
typedef pair<int,int> PII;
int n,m,d[N];
bool st[N];
void add(int a,int b,int c){
    w[idx] = c,e[idx] = b,ne[idx] = h[a],h[a] = idx++; 
}
int dijkstra(){
    memset(d,0x3f,sizeof d);
    d[1]  = 0;
    priority_queue<PII,vector<PII>,greater<PII>> heap;
    heap.push({0,1});
    while(heap.size()){
        auto t = heap.top();
        heap.pop();
        int dx = t.second , distance = t.first;
        if(st[dx])continue;
        for(int i = h[dx];i!=-1;i = ne[i]){
            int x = e[i];
            if(d[x] > distance + w[i]){
                d[x] = distance + w[i];
                heap.push({d[x],x});
            }
        }

    } 
    if(d[n] == 0x3f3f3f3f)return -1;
    else return d[n];

}
int main(){
    cin>>n>>m;
    memset(h,-1,sizeof h);
    for(int i = 0;i < m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
    }
    int a = dijkstra();
    cout<<a;
}