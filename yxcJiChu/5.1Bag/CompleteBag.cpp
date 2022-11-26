/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-11-25 17:22:28
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-11-25 21:03:43
 * @FilePath: \MyAlgorithmDaily\yxcJiChu\5.1Bag\CompleteBag.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>
using namespace std;

const int N = 1010;
// int dp[N][N];
int dp[N];
int v[N],w[N];

// int main(){
//     int n,m;
//     cin>>n>>m;
//     for(int i = 1; i <= n ; i ++ )cin>>v[i]>>w[i];
//     for(int i = 1 ; i <= n ; i++ ){
//         for(int j = 0; j <= m ; j ++ ){
//             for(int k = 0; k*v[i] <= j;k++){
//                 dp[i][j] = max(dp[i][j],dp[i - 1][j - k*v[i]] + k*w[i]);
//             }
//         }
//     } 
//     cout<<dp[n][m];
//     return 0;
// }


//优化1 省去三重循环


// int main(){
//     int n,m;
//     cin>>n>>m;
//     for(int i = 1; i <= n ; i ++ )cin>>v[i]>>w[i];
//     for(int i = 1 ; i <= n ; i++ ){
//         for(int j = 0; j <= m ; j ++ ){
//             dp[i][j] = dp[i - 1][j];
//             if(j >= v[i])dp[i][j] = max(dp[i][j],dp[i][j - v[i]] + w[i]);
//         }
//     } 
//     cout<<dp[n][m];
//     return 0;
// }


//优化3 再缩空间

int main(){
    int n,m;
    cin>>n>>m;
    for(int i = 1; i <= n ; i ++ )cin>>v[i]>>w[i];
    for(int i = 1 ; i <= n ; i++ ){
        for(int j = 0; j <= m ; j ++ ){
            if(j >= v[i])dp[j] = max(dp[j],dp[j - v[i]] + w[i]);
        }
    } 
    cout<<dp[m];
    return 0;
}