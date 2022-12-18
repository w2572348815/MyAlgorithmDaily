/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-12-17 15:45:33
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-12-17 21:10:56
 * @FilePath: \MyAlgorithmDaily\yxcJiChu\6.2PaiXuBuDengShiAndJueDuiZhiBuDengShiAndTuiGongShi\PaiXuBuDengShi.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 100010;
int a[N];

int main(){
    int n ;
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i ++ )scanf("%d",&a[i]);
    sort(a, a + n);
    long long res = 0 ;
    for(int i = 0 ; i < n ; i ++ ){
        res += a[i]*(n - i - 1);
    }
    cout<<res;
    return 0;
}