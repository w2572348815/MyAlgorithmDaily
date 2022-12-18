/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-12-17 21:43:10
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-12-17 22:52:57
 * @FilePath: \MyAlgorithmDaily\yxcJiChu\6.2PaiXuBuDengShiAndJueDuiZhiBuDengShiAndTuiGongShi\JueDuiZhiBuDengShi.cpp
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
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; i ++ )scanf("%d",&a[i]);
    sort(a , a + n);
    int res = 0;
    for(int i = 0 ; i < n ; i ++ ){
        res += abs(a[i] - a[n / 2]);
    }
    cout << res;
    return 0;
}