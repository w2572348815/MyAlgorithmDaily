/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-12-13 19:50:31
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-12-14 08:30:21
 * @FilePath: \MyAlgorithmDaily\yxcJiChu\5.2XianXingDPAndQuJianDPAndCountDP\QuJianDP.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>

using namespace std;

const int N = 310;
int n;
int f[N][N];
int s[N];

int main(){
    scanf("%d",&n);
    for(int i = 1 ; i <= n ; i ++ ){
        scanf("%d",&s[i]);
    }
    for(int i = 2 ; i <= n ; i ++ ){
        s[i] += s[i - 1];
    }
    for(int len = 2 ; len <= n ; len ++ ){
        for(int qi = 1 ; qi + len - 1 <= n ; qi ++ ){
            int l = qi , r = qi + len - 1;
            f[l][r] = 1e8;
            for(int k = l ; k < r ;k ++ ){
                f[l][r] = min(f[l][r] , f[l][k] + f[k + 1][r] + s[r] - s[l - 1]);
            }
        }
    }
    cout<<f[1][n];
    return 0 ;
}