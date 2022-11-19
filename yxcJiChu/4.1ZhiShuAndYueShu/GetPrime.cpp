
/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-11-11 19:48:36
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-11-12 11:20:32
 * @FilePath: \MyAlgorithmDaily\yxcJiChu\4.1ZhiShuAndYueShu\GetPrime.cpp
 * @Description: 埃氏筛法1 nloglogn
 *               线性筛法2 n
 *               10的七次方时线性快一倍，10的六次方差不多
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>
using namespace std;
const int N = 100010;
int prime[N],cnt;
bool st[N];
/**
 * @description:埃氏筛法 
 * @param {int} n
 * @return {*}
 */
void get_prime1(int n){
    for(int i = 2; i <= n;i++){
        if(!st[i]){
            prime[cnt++] = i;
            for(int j = 2*i;j<=n;j += i)st[j] = true;
        }
    }
}
/**
 * @description: 线性筛法
 * @param {int} n
 * @return {*}
 */
void get_prime2(int n){
    for(int i = 2; i <= n;i ++){
        if(!st[i])prime[cnt++] = i;
        for(int j = 0;prime[j] <= n / i;j++){
            st[prime[j]*i] = true;
            if(i % prime[j] == 0)break;
        }
    }
}
int main(){
    int n;
    cin>>n;
    get_prime2(n);
    for(int i = 0;i < cnt;i++)printf("%d ",prime[i]);
    return 0;
}