/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-11-12 16:27:59
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-11-12 16:33:44
 * @FilePath: \MyAlgorithmDaily\yxcJiChu\4.1ZhiShuAndYueShu\ZhanzhuanXiangChuFa.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>
using namespace std;
int gcd(int a,int b){
    return b ? gcd(b,a % b) : a;
}
int main(){
    int a,b;
    cin>>a>>b;
    int c = gcd(a,b);
    cout<<c;
}