/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-12-13 10:03:04
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-12-13 15:21:27
 * @FilePath: \MyAlgorithmDaily\yxcJiChu\week7 12 13\TaiJieNIM.cpp
 * @Description: 
 *      
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>

using namespace std;

int main(){
    int n ;    
    cin>>n;
    int res = 0 ;
    int x; 
    for(int i = 0 ; i < n ; i ++ ){
        cin>>x;
        if(i % 2)res ^= x;
    }
    if(res)cout<<"yes";
    else cout<<"no";
    return 0;
}