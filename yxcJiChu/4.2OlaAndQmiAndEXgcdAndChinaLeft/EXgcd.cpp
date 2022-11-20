/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-11-20 12:33:22
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-11-20 16:25:25
 * @FilePath: \MyAlgorithmDaily\yxcJiChu\4.2OlaAndQmiAndEXgcdAndChinaLeft\EXgcd.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>

using namespace std;
int gcd1(int a,int b){
    return b == 0 ? a : gcd1(b , a % b);
}
int exgcd(int a,int b,int &x,int &y){
    if(b == 0){
        x = 1, y = 0;
        return a;
    }

    int d =  exgcd(b, a % b,y,x);
    y -= a / b * x;
    return d;
}
int main(){
    int n ;
    scanf("%d",&n);
    while(n--){
        int a,b,x,y;
        scanf("%d%d",&a,&b);
        exgcd(a,b,x,y);
        cout<<x<<" "<<y<<endl;
    }
    return 0;
}