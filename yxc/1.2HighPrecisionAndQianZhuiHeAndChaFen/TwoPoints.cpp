/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-10-25 08:48:12
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-10-25 17:53:24
 * @FilePath: \MyAlgorithmDaily\yxc\1.2HighPrecisionAndQianZhuiHeAndChaFen\TwoPoints.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>

using namespace std;

const int N = 100010;
int n;
int a[N],s[N];
int main(){
    scanf("%d",&n);
    for(int i = 0 ;i < n;i ++)scanf("%d",&a[i]);
    int i = 0, j = 0,res = 0;
    while(j!=n){
        s[a[j]]++;
        while(s[a[j]]>1){
            s[a[i]]--;
            i++;
        }
        res = max(res, j - i + 1);
        j++;

    }
    cout<<res<<endl;
}