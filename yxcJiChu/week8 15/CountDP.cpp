/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-12-14 10:34:01
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-12-14 15:11:04
 * @FilePath: \MyAlgorithmDaily\yxcJiChu\week8 15\CountDP.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>

using namespace std;

const int N = 1010 , mod = 1e9 + 7;

int f[N];
int main(){
    int n ;
    cin >> n;
    f[0] = 1;
    for(int i = 1 ; i <= n ; i++ ){
        for(int j = i ; j <= n ; j ++ ){
            f[j] = (f[j] + f[j - i]) % mod;
        }
    }
    cout<<f[n];
    return 0;
}