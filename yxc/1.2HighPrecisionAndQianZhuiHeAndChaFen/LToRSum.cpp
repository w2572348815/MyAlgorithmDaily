/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-10-23 14:53:48
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-10-23 15:04:34
 * @FilePath: \MyAlgorithmDaily\yxc\1.2HighPrecisionAndQianZhuiHeAndChaFen\LToRSum.cpp
 * @Description: 一维前缀和
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>

using namespace std;

const int N = 100010;

int n;
int m;
int a[N],s[N];
int main(){
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i++)scanf("%d",&a[i]);
    for(int i = 1; i <= n;i++)s[i] = s[i - 1] + a[i];
    while(m--){
        int a,b;
        scanf("%d%d",&a,&b);
        printf("%d",s[b] - s[a- 1]);
    }
    return 0;
}