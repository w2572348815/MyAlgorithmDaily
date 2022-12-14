/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-12-13 15:56:11
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-12-13 16:53:36
 * @FilePath: \MyAlgorithmDaily\yxcJiChu\5.2XianXingDPAndQuJianDPAndCountDP\XianXingDP.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>


using namespace std;

const int N = 510;
int a[N][N];
int dp[N][N];

int main(){
    int n;
    scanf("%d",&n);
    
    for(int i = 1 ; i <= n ; i ++ )
        for(int j = 1 ; j <= i ; j ++ ){
            cin>>a[i][j];
        }
   
    for(int i = 0 ; i <= n; i ++ )
        for(int j = 0 ; j <=i + 1 ; j ++ )dp[i][j] = -1e9;
    
    dp[1][1] = a[1][1];

    for(int i = 2 ; i <= n ; i ++ ){
        for(int j = 1 ; j <= i ; j ++ ){
            dp[i][j] = max(dp[i - 1][j - 1] + a[i][j] , dp[i - 1][j] + a[i][j] );
        }
    }

    int res = -1e9;
    for(int i = 1 ; i <= n ; i ++ ){
        res = max(res , dp[n][i]);
    }
    cout<<res;
    return 0;

}