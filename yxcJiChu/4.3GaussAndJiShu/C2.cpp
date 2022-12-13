/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-11-26 14:07:31
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-11-26 14:23:01
 * @FilePath: \MyAlgorithmDaily\yxcJiChu\4.3GaussAndJiShu\C2.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>

using namespace std;
const int mod = 1e9 + 7;
const int N = 10010;
int fact[N],infact[N];
typedef long long LL;
int qmi(int a,int k,int p){
    int res = 1;
    while(k){
        if(k&1){
            res =(LL) res * a % p;
        }
        a = (LL)a * a % p;
        k = k >> 1;
    }
    return res;
}

int main(){
    fact[0] = infact[0] = 1;
    for(int i = 1 ; i < N ; i ++ ){
        fact[i] = (LL)fact[i - 1] * i % mod;
        infact[i] = (LL)infact[i - 1] * qmi(i,mod - 2 ,mod) % mod;
    }
    int n ;
    cin>>n;
    while(n--){
        int a,b;
        cin>>a>>b;
        printf("%d\n",(LL)fact[a] * infact[b] % mod * infact[a- b] % mod);
    }
    return 0;
}