/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-11-07 12:08:29
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-11-09 15:26:40
 * @FilePath: \MyAlgorithmDaily\yxc\week3 05 06\BinChaJIAndShiWuLian.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 50010;
int n,m;
int p[N],d[N];
int find(int x){
    if(x != p[x]){
        int t = find(p[x]);
        d[x] += d[p[x]];
        p[x] = t;
    }
    return p[x];
    
}
int main(){
    cin>>n>>m;
    int a,x,y;
    int res = 0;
    for(int i = 1;i <= n;i++ )p[i] = i;
    while(m--){
        cin>>a>>x>>y;
        if(y>n||x> n)res++;
        else{
            int px = find(x),py = find(y);
            if(a == 1){
                if(px == py && (d[x] - d[y])%3)res++;
                else if(px!=py){
                    p[px] = py;
                    d[px] = d[y] - d[x];
                }
            }else{
                if(px == py && (d[x] - d[y] - 1)%3)res++;
                else if(px != py){
                    p[px] = py;
                    d[px] = d[y] + 1 - d[x];
                }
            }
        }
    }
    cout<<res;
    return 0;
}