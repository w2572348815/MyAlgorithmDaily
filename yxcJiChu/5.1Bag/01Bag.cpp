/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-11-24 16:30:24
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-11-25 17:21:28
 * @FilePath: \MyAlgorithmDaily\yxcJiChu\5.1Bag\01Bag.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>

using namespace std;

const int N = 1010;
// int dp[N][N];
int v[N],w[N];
int dp[N];
// int main(){
//     int n,m;
//     cin>>n>>m;
//     for(int i = 1; i <= n ; i ++ )cin>>v[i]>>w[i];
//     for(int i = 1 ; i <= n ; i ++ )
//         for(int j = 1 ; j <= m ; j ++){
//             dp[i][j] = dp[i-1][j];
//             if(j>=v[i])dp[i][j] = max(dp[i][j],dp[i-1][j - v[i]] + w[i]);
//         }
//     cout<<dp[n][m];
//     return 0;
// }
int main(){
    int n,m;
    cin>>n>>m;
    for(int i = 1; i <= n; i++ )cin>>v[i]>>w[i];
    for(int i = 1; i <= n ; i ++ ){
        for(int j = m ; j >= 1 ; j -- ){
            if(j >= v[i])dp[j] = max(dp[j],dp[j - v[i]] + w[i]);
        }
    }
    cout<<dp[m];
    return 0;
}