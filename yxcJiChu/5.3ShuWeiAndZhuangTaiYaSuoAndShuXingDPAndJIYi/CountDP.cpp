/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-12-16 09:54:31
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-12-16 21:49:14
 * @FilePath: \MyAlgorithmDaily\yxcJiChu\5.3ShuWeiAndZhuangTaiYaSuoAndShuXingDPAndJIYi\CountDP.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>
#include<cstring>
#include<vector>

using namespace std;
int get(vector<int> num,int l ,int r){
    int res = 0;
    for(int k = l ; k >= r ; k -- ){
        res = res * 10 + num[k];
    }
    return res;
}
int power10(int x){
    int res = 1;
    for(int i = 0 ; i < x ; i ++ )res *= 10;
    return res;
}
int count(int n , int x){
    if(!n) return 0;
    vector<int > num;
    while(n){
        num.push_back(n % 10);
        n /= 10;
    }
    n = num.size();
    int res = 0;
    for(int i = n - 1 - !x ; i >= 0 ; i -- ){
        if(i < n - 1){
            res += get(num, n - 1 , i + 1) * power10(i);
            if(!x)res -= power10(i);
        }
        if(num[i] == x)res += get(num , i - 1 , 0) + 1;
        else if(num[i] > x)res += power10(i);
    }
    return res;
}
int main(){
    int a,b;
    vector<int > v1;
    vector<int > v2;
    while(cin>>a>>b, a || b){
        if(a > b)swap(a,b);
        for(int i = 0; i < 10 ; i ++ ){
            cout<<count(b , i) - count(a - 1 , i)<<" ";
        }
        cout<<endl;
    }
    return 0;
}