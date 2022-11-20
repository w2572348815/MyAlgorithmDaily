/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-11-20 16:27:00
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-11-20 16:39:45
 * @FilePath: \MyAlgorithmDaily\yxcJiChu\4.2OlaAndQmiAndEXgcdAndChinaLeft\SameMod.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>

using namespace std;

int exgcd(int a,int b,int &x,int &y){
    if(!b){
        x = 1,y = 0;
        return a;
    }
    int d = exgcd(b,a % b,y,x);
    y -= a / b * x;
    return d;
}
int main(){
    int n;
    cin>>n;
    while(n--){
        int a,b,m,x,y;
        scanf("%d%d%d",&a,&b,&m);
        int d = exgcd(a,m,x,y);
        if(b % d)printf("impossible\n");
        else printf("%d\n",(long long)x * (b / d) % m);
    }
    return 0;
}