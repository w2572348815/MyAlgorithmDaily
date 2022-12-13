/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-12-13 08:30:06
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-12-13 08:33:27
 * @FilePath: \MyAlgorithmDaily\yxcJiChu\4.4RongChiAndBoyi\Nim1.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    int x;
    int res = 0;
    for(int i = 0 ;i < n ; i ++ ){
        cin>>x;
        res ^= x;
    }
    if(res != 0)cout<<"Yes";
    else cout<<"No";
    return 0;

}