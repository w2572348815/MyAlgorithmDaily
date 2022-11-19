/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-11-12 14:06:29
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-11-12 14:14:58
 * @FilePath: \MyAlgorithmDaily\yxcJiChu\4.1ZhiShuAndYueShu\GetDivisors.cpp
 * @Description: 试除法求约数
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> get_divisors(int n){
    vector<int> res;
    for(int i = 1; i <= n / i;i++){
        if(n % i == 0){
            res.push_back(i);
            if(i != n / i)res.push_back(n/i);
        }
        
    }
    sort(res.begin(),res.end());
    return res;
}
int main(){
    int x;
    cin>>x;
    auto k = get_divisors(x);
    for(int e : k){
        cout<<e<<" ";
    }
}