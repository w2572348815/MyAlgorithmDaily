/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-10-31 18:42:09
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-10-31 19:23:32
 * @FilePath: \MyAlgorithmDaily\yxc\week1\FindDiK.cpp
 * @Description: 快速选择算法 找到第K大元素 时间N
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>
using namespace std;
int n,k;
const int N = 10010;
int a[N];
int quick_sort(int L,int R,int k){
    if(L>=R)return a[L];
    int huafen = a[L];
    int i = L - 1, j = R + 1;
    while(i < j){
        do i++;while(a[i] < huafen);
        do j--;while(a[j] > huafen);
        if(i < j)swap(a[i],a[j]);
    }
    int s = j - L + 1;
    if(s >= k){
        return quick_sort(L,j,k);
    }else{
        return quick_sort(j + 1,R,k - s);
    }
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i = 0; i < n;i++)scanf("%d",&a[i]);
    int e = quick_sort(0,n - 1,k);
    printf("%d",e);
    return 0;
}    