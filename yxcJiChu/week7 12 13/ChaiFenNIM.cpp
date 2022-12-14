/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-12-13 15:22:36
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-12-13 15:53:44
 * @FilePath: \MyAlgorithmDaily\yxcJiChu\week7 12 13\ChaiFenNIM.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>
#include<cstring>
#include<unordered_set>

using namespace std;

const int N = 110;
int f[N];
int sg(int x){
    if(f[x] != -1){
        return f[x];  
    }
    unordered_set<int> s;
    for(int i = 0 ; i < x ; i ++ ){
        for(int j = 0 ; j <= i ;  j ++ ){
            s.insert(sg(i) ^ sg(j));
        }
    }
    for(int i = 0 ; ; i ++ ){
        if(!s.count(i))return f[x] = i;
    }
}
int main(){
    int n;
    int res = 0 ;
    cin>>n;
    memset(f, -1 , sizeof f);
    for(int i = 0 ; i < n ; i ++ ){
        int x;
        cin>>x;
        res ^= sg(x);
    }
    if(res)cout<<"Yes";
    else cout<<"No";
    return 0;

}