/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-11-26 13:50:18
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-11-26 13:59:09
 * @FilePath: \MyAlgorithmDaily\yxcJiChu\4.3GaussAndJiShu\C1.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>

using namespace std;

const int N = 2010;
const int mod = 1e9 + 7;
int c[N][N];
void init(){
    c[0][0] = 1;
    for(int i = 1;i < N ; i ++ ){
        for(int j = 0 ; j <= i ; j ++ ){
            if(!j)c[i][j] = 1;
            else c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
        }
    }
}

int main(){
    int n;
    cin>>n;
    init();
    while(n--){
        int a,b;
        cin>>a>>b;
        cout<<c[a][b];
    }
    return 0;
}