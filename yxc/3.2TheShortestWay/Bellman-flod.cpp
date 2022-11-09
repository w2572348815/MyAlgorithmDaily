/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-11-04 21:02:01
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-11-09 15:29:12
 * @FilePath: \MyAlgorithmDaily\yxc\3.2TheShortestWay\Bellman-flod.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 510,M = 10010;
int n,m,k,d[N],backup[N];
struct edge{
    int a;
    int b;
    int c;
}edges[M];
int bellman_flod(){
    for(int i = 0;i < k;i++){
        memcpy(backup,d,sizeof d );
        for(int j = 0; j < m ; j++){
            int a = edges[j].a,b = edges[j].b,c = edges[j].c;
            d[b] = min(d[b],backup[a]+c);
        }



    }
    if(d[n] > 0x3f3f3f3f/2){
        return -1;
    }else {
        return d[n];
    }
}
int main(){
    cin>>n>>m>>k;
    memset(d,0x3f,sizeof d);
    d[1] = 0;
    for(int i = 0; i < m ; i ++ ){
        int a,b,c;
        cin>>a>>b>>c;
        edges[i].a = a;
        edges[i].b = b;
        edges[i].c = c;
    }
    int x = bellman_flod();
    cout<<x<<endl;
    return 0;
        
}