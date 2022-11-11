/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-11-11 16:57:48
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-11-11 17:01:15
 * @FilePath: \MyAlgorithmDaily\yxcJiChu\4.1ZhiShuAndYueShu\IsPrime.cpp
 * @Description: 试除法判断是否是质数
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

bool is_prime(int n){
    if(n < 2) return false;
    for(int i = 2; i <= n / i; i ++ ){
        if(n % i == 0)return false;
    }
    return true;
}

int main(){
    int n;
    cin>>n;
    bool b = is_prime(n);
    if(b)cout<<"Yes";
    else cout<<"No";
    return 0;
}