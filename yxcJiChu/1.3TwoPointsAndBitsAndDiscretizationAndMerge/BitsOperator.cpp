/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-10-25 19:15:55
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-10-31 19:22:50
 * @FilePath: \MyAlgorithmDaily\yxc\1.3TwoPointsAndBitsAndDiscretizationAndMerge\BitsOperator.cpp
 * @Description: 简单位运算
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>

using namespace std;
const int N = 100010;
int a[N];
int getMostRightBit(int n){
    return n&-n;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i= 0;i< n;i++)scanf("%d",&a[i]);
    for(int i = 0;i < n;i++){
        int res = 0;
        while(a[i]){
        a[i] -= getMostRightBit(a[i]);
        res++;
        }
        cout<<res<<" ";
    }
    return 0;
}


