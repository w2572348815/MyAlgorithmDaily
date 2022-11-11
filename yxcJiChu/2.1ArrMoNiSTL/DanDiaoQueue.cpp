/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-10-31 21:56:51
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-10-31 22:25:58
 * @FilePath: \MyAlgorithmDaily\yxc\1.4ArrMoNiSTL\DanDiaoQueue.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>

using namespace std;

const int N = 100010;
int k,n;
int a[N],q[N];
int main(){
    cin>>n>>k;
    for(int i = 0;i < n;i++)cin>>a[i];
    int hh = 0,tt = -1;
    for(int i = 0;i < n;i++){
        if(hh<=tt&&i - q[hh] + 1 > k)hh++;
        while(hh<=tt && a[q[tt]]>=a[i])tt--;
        q[++tt] = i;
        if(i >= k - 1)printf("%d ",a[q[hh]]);
    }
    puts("");
    hh = 0;
    tt = -1;
    for(int i = 0;i < n;i++){
        if(hh<=tt&&i - q[hh] + 1 > k)hh++;
        while(hh<=tt&&a[q[tt]]<=a[i])tt--;
        q[++tt] = i;
        if(i >= k - 1)printf("%d ",a[q[hh]]);
    }
    puts("");
    return 0;
}