/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-12-13 19:06:34
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-12-13 19:21:47
 * @FilePath: \MyAlgorithmDaily\yxcJiChu\5.2XianXingDPAndQuJianDPAndCountDP\XianXingDP2.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1010;

int f[N],a[N],g[N];
int main(){
    int n;
    cin>>n;
    for(int i = 1 ; i <= n ; i ++ )cin>>a[i];
    for(int i = 1 ; i <= n ; i ++ ){
        f[i] = 1;
        g[i] = 0;
        for(int j = 1 ; j < i ; j ++ ){
            if(a[j] < a[i])
                if(f[j] + 1 > f[i]){
                    f[i] = f[j] + 1;
                    g[i] = j;
                }
        }
    }
    int t = 0;
    for(int i = 1 ; i <= n ; i ++ ){
        if(f[t] < f[i])t = i ; 
    }
    cout<<f[t]<<endl;
    for(int i = 0 , len = f[t] ; i < len ; i ++ ){
        cout<<a[t];
        t = g[t];
    }

    return 0;
}