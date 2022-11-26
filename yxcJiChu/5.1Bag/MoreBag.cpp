/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-11-25 21:06:26
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-11-25 21:16:28
 * @FilePath: \MyAlgorithmDaily\yxcJiChu\5.1Bag\MoreBag.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>

using namespace std;

const int N = 1010;
int v[N],s[N],w[N];
int dp[N][N];

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i = 1 ; i <= n ; i ++ ) cin>>v[i]>>w[i]>>s[i];
    for(int i = 1 ; i <= n ; i ++ ){
        for(int j = 0 ; j <= m ; j ++ ){
            for(int k = 0 ; k * v[i] <= j && k <= s[i] ; k ++ ){
                dp[i][j] = max(dp[i][j],dp[i - 1][j - v[i] * k] + k * w[i]);
            }
        }
    }
    cout<<dp[n][m];
    return 0;
}