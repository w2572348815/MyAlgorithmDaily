/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-12-18 10:45:25
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-12-18 10:50:49
 * @FilePath: \MyAlgorithmDaily\yxcJiChu\6.2PaiXuBuDengShiAndJueDuiZhiBuDengShiAndTuiGongShi\TuiGongShi.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>
#include<algorithm>

using namespace std;
typedef pair<int, int > PII;
const int N = 50010;
PII cow[N];

int main(){
    int n ; 
    cin >> n;
    int w , s;
    for(int i = 0 ; i < n ; i ++ ){
        cin >> w >> s;
        cow[i] = { w + s , s};
    }
    sort(cow , cow + n);
    int res = -2e9 , sum = 0;
    for(int i = 0 ; i < n ; i ++ ){
        res = max(res , sum - cow[i].second);
        sum += cow[i].first - cow[i].second;
    }
    cout<<res;
    return 0;
}