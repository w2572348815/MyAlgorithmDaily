/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-12-14 15:11:22
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-12-14 15:28:10
 * @FilePath: \MyAlgorithmDaily\yxcJiChu\week8 15\CountDP2.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>

using namespace std;
const int N = 1010 , mod = 1e9 + 7 ;
int f[N][N];
int main(){

    f[0][0] = 1;
    int n;
    cin>>n;
    for(int i = 1 ; i <= n ; i ++ ){
        for(int j = 1 ; j <= i ; j ++ ){
            f[i][j] = f[i - 1][j - 1] + f[i - j][j];
        }
    }
    int res = 0;
    for(int i = 1 ; i <= n ; i ++ ){
        res = (res + f[n][i]) % mod;
    }
    cout<<res;
    return 0;
}