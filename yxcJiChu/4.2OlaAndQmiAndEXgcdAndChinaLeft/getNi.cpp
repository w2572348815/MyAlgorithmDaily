/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-11-20 08:58:22
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-11-20 09:40:03
 * @FilePath: \MyAlgorithmDaily\yxcJiChu\4.2OlaAndQmiAndEXgcdAndChinaLeft\getNi.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>

using namespace std;

int n ;
typedef long long LL;
int qmi(int a,int b,int p){
    int res = 1;
    while(b){
        if(b & 1){
            res = (LL)res * a % p;
        }
        a = (LL)a * a % p;
        b>>=1;
    }
    return res;
}
int main(){
    scanf("%d",&n);
    while(n--){
        int a,p;
        scanf("%d%d",&a,&p);
        int res = qmi(a,p-2,p);
        if(a % p)cout<<res<<endl;
        else cout<<"impossible"<<endl;
    }
    return 0;
}