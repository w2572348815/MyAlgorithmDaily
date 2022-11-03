/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-11-03 09:32:55
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-11-03 09:40:30
 * @FilePath: \MyAlgorithmDaily\yxc\1.7BFSAndDFSAndMap\DFSQuanPaiLie.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>
using namespace std;
const int N = 8;
bool str[N];
int n;
int ans[N];
void dfs(int i){
    if(i == n){
        for(int j = 0;j < n;j++)cout<<ans[j];
        cout<<endl;
        return ;
    }
    for(int j = 1;j <= n;j++){
        if(!str[j]){
            ans[i] = j;
            str[j] = true;
            dfs(i+1);
            str[j] = false;
        }
    }
}
int main(){

    cin>>n;
    dfs(0);
}
