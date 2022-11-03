/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-10-31 21:49:02
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-10-31 21:56:06
 * @FilePath: \MyAlgorithmDaily\yxc\1.4ArrMoNiSTL\DanDIaoStack.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>

using namespace std;

const int N = 100010;
int tt;
int stk[N];
int main(){
    int n;
    cin>>n;
    for(int i = 0;i < n;i++){
        int x;
        cin>>x;
        while(tt&&stk[tt] >= x)tt--;
        if(tt)cout<<stk[tt]<<" ";
        else cout<<"-1 ";
        stk[++tt] = x;
    }
    return 0;
}