/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-11-25 23:28:06
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-11-26 09:51:22
 * @FilePath: \MyAlgorithmDaily\yxcJiChu\5.1Bag\GroupBag.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>

using namespace std;

const int N = 110;
int s[N],v[N][N],w[N][N];
int dp[N];

int main(){
    int n,m;
    cin>>n>>m;
    for(int i = 1 ; i <= n ;i ++ ){
        scanf("%d",&s[i]);
        for(int j = 0 ; j < s[i] ; j ++ ){
            scanf("%d %d",&v[i][j],&w[i][j]);
        }
    }
    for(int i = 1 ;i <= n ; i ++ ){
        for(int j = m ; j >= 0 ; j -- ){
            for(int k = 0 ; k < s[i] ; k ++ ){

                if(j >= v[i][k])dp[j] = max(dp[j],dp[j - v[i][k]] + w[i][k]);
            }
        }
    }
    cout<<dp[m];
    return 0 ;
}