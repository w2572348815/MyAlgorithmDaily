/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-12-16 09:24:14
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-12-16 09:54:15
 * @FilePath: \MyAlgorithmDaily\yxcJiChu\5.3ShuWeiAndZhuangTaiYaSuoAndShuXingDPAndJIYi\JiYiSouSuo.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 310;
int h[N][N];
int dp[N][N];
int r,c;
int sousuo(int i , int j){
    if(dp[i][j])return dp[i][j];
    dp[i][j] = 1;
    int cx[4] = {1, -1 , 0 , 0};
    int cy[4] = {0, 0 , -1 , 1};
    for(int k = 0 ; k < 4 ; k ++ ){
        int a = i + cx[k] , b = j + cy[k];
        if(a >= 1 && a <= r && b >= 1 && b <= c && h[a][b] < h[i][j])
        dp[i][j] = max(dp[i][j] , sousuo(a , b) + 1);
    }
    return dp[i][j];
}
int main(){
    cin>> r>>c;
    for(int i = 1 ; i <= r ; i ++)
        for(int j = 1 ; j <= c ; j ++ ){
            scanf("%d",&h[i][j]);
        }
    int res = 0;
    for(int i = 1 ; i <= r ; i ++ )
        for(int j = 1 ; j <= c ; j ++ ){
            res = max(res , sousuo(i , j));
        }
    cout <<res;
    return 0;
}