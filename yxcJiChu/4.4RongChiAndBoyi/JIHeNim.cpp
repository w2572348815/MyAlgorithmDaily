/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-12-13 09:10:53
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-12-13 09:30:21
 * @FilePath: \MyAlgorithmDaily\yxcJiChu\4.4RongChiAndBoyi\JIHeNim.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>
#include<algorithm>
#include<cstring>
#include<unordered_set>

using namespace std;

const int N = 110,M = 10010;
int n, m;
int s[N],f[M];

int sg(int x){
    if(f[x] != -1)return f[x];
    unordered_set<int > set;
    for(int i = 0 ; i < m ; i ++ ){
        if(x >= s[i]){
            set.insert(sg(x - s[i]));
        }
    }
    for(int i = 0; ; i ++ ){
        if(!set.count(i)){
            return f[x] = i;
        }
    }
}

int main(){
    cin>>m;
    for(int i = 0 ; i < m ;  i ++ ){
        cin>>s[i];
    }
    memset(f , -1 , sizeof f);
    cin>>n;
    int res = 0;
    for(int i = 0 ; i < n ; i ++ ){
        int x;
        cin>>x;
        res ^= sg(x);
    }
    if(res)cout<<"yes";
    else cout<<"no";
    return 0;
}