/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-11-02 18:28:44
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-11-02 18:51:15
 * @FilePath: \MyAlgorithmDaily\yxc\1.6Hash\HashStr.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>
using namespace std;
typedef unsigned long long ULL;
const int N = 100010,P = 131;
char str[N];
ULL h[N],p[N];
ULL get(int l,int r){
    return h[r] - h[l - 1] * p[r - l + 1]; 
}
int main(){
    int n,m;
    cin>>n>>m;
    cin>>str+1;
    p[0] = 1;
    for(int i = 1;i <= n;i++){
        p[i] = P*p[i-1];
        h[i] = h[i-1]*P + str[i];
    }
    while(m--){
        int l1,r1,l2,r2;
        cin>>l1>>r1>>l2>>r2;
        if(get(l1,r1)==get(l2,r2))puts("Yes");
        else puts("N0");
    }
}