/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-12-14 08:32:08
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-12-14 09:16:51
 * @FilePath: \MyAlgorithmDaily\yxcJiChu\week8 15\XianXingDPYouHua.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>  

using namespace std;

const int N = 100010;
int a[N];
int q[N];

int main(){
    int n ;
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i ++ )scanf("%d",&a[i]);
    q[0] = -2e9;
    int len = 0;
    for(int i = 0 ; i < n ; i ++ ){
        int l = 0 , r = len;
        while(l < r){
            int mid = l + r + 1 >> 1;
            if(q[mid] < a[i])l = mid;
            else r = mid - 1;
        }
        len = max(len , r + 1);
        q[r + 1]  = a[i];
    }
    cout<<len;
    return 0;
}