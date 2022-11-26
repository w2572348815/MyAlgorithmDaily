/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-11-20 16:50:21
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-11-20 21:59:47
 * @FilePath: \MyAlgorithmDaily\yxcJiChu\week6 11\ChinaLeft.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>
using namespace std;
int exgcd(int a,int b,int &x,int &y){
    if(!b){
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b,a%b,y,x);
    y  -= a / b * x;
    return d;
    
}
int main(){
    int n;
    int a1,m1;
    cin>>n;
    bool flag = true;
    scanf("%d%d",&a1,&m1);
    for(int i = 0; i < n - 1; i ++){
        int a2, m2,k1,k2;
        scanf("%d%d",&a2,&m2);
        int d = exgcd(a1,a2,k1,k2);
        if((m2 - m1) % d){
            flag = false ;
            break;
        }
        k1 *= (m2 - m1)/d;
        int t = a2 / d ; 
        k1 = (k1 % t + t)%t;
        m1 = k1 * a1 + m1;
        a1 = abs(a1 * t);

    }
    if(flag){
        cout<<(m1 % a1 + a1)%a1<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}