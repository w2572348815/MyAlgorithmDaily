/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-10-23 13:24:39
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-10-31 19:19:44
 * @FilePath: \MyAlgorithmDaily\yxc\1.1SortAndDichotomy\dichotomy.cpp
 * @Description: 二分法 时间logN
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>
using namespace std;
const int N = 100010;
int n,q,k;
int a[N];
int main(){
    scanf("%d%d",&n,&q);
    for(int i = 0; i < n;i++)scanf("%d",&a[i]);
    while(q--){
        scanf("%d",&k);
        int L = 0;
        int R = n - 1;
        while(L < R){
            int mid = L + R >> 1;
            if(a[mid]<k){
                L = mid + 1;
            }else{
                R = mid;
            }
        }
        if(a[L] == k)printf("%d ",L);
        else{
            printf("-1 -1\n");
            return 0;
        }

        L = 0;
        R = n - 1;
        while(L < R){
            int mid = L + R + 1>> 1;
            if(a[mid] > k){
                R = mid - 1;
            }else{
                L = mid;
            }
        }
        if(a[L] == k)printf("%d\n",L);
    }
}
