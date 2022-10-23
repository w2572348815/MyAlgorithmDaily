/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-10-23 15:37:34
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-10-23 17:47:02
 * @FilePath: \MyAlgorithmDaily\yxc\1.2HighPrecisionAndQianZhuiHeAndChaFen\OneDimentialDifference.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>
using namespace std;

int n,m;
const int N = 100010;
int a[N],c[N];
void insert(int i, int j,int num){
    c[i] += num;
    c[j+1] -= num;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i++)scanf("%d",&a[i]);
    for(int i = 1;i <= n;i++)insert(i,i,a[i]);
    while(m--){
        int l;
        int r;
        int num;
        scanf("%d%d%d",&l,&r,&num);
        insert(l,r,num);
    }
    for(int i = 1;i <= n;i++){
        c[i] = c[i] + c[i - 1];
        printf("%d ",c[i]);
    }
    return 0;
}
