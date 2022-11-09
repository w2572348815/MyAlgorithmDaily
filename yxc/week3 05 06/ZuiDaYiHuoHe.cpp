/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-11-07 11:14:53
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-11-09 15:27:31
 * @FilePath: \MyAlgorithmDaily\yxc\week3 05 06\ZuiDaYiHuoHe.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>
using namespace std;
int n ;
const int N = 100010,M = 31*N;
int a[N];
int son[M][2];
int idx;
void insert(int x){
    int p  = 0; 
    for(int i = 30;i >=0 ;i--){
        int u = x >> i & 1;
        if(!son[p][u]){
            son[p][u] = ++idx;
            
        }
        p = son[p][u];
    }
}
int query(int x){
    int p = 0,res = 0;
    for(int i = 30; i >= 0;i -- ){
        int u = x >> i & 1;
        if(son[p][!u]){
            p = son[p][!u];
            res = res * 2 + !u;
        }else{
            p = son[p][u];
            res = res * 2 + u;
        }
    }
    return res;
}
int main(){
    int n;
    cin>>n;
    int res = 0;
    for(int i = 0 ;i < n; i++){
        cin>>a[i];
        insert(a[i]);
        int t = query(a[i]);
        res = max(res,a[i]^t);
    }
    cout<<res;
    return 0;
}
