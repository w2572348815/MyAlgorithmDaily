/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-11-01 17:54:37
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-11-01 18:02:37
 * @FilePath: \MyAlgorithmDaily\yxc\week2 03 04\findTargetSum.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>
using namespace std;
int a[100010],b[100010];
int n,m,x;

 int main(){
    cin>>n>>m>>x;
    for(int i = 0; i < n;i++)cin>>a[i];
    for(int i = 0; i < m;i++)cin>>b[i];
    int i  = 0, j = m - 1;
    while(i < n && j > 0){
        if(a[i] + b[j] > x){
            j--;
        }else if(a[i] + b[j] < x){
            i++;
        }else{
            cout<<i<<' '<<j;
            return 0;
        }
    }
    cout<<"NO";
    return 0;
 }