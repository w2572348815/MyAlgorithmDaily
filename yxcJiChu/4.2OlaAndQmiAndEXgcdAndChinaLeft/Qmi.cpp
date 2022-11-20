/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-11-20 08:48:35
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-11-20 08:57:09
 * @FilePath: \MyAlgorithmDaily\yxcJiChu\4.2OlaAndQmiAndEXgcdAndChinaLeft\Qmi.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>

using namespace std;

const int N = 100010;
typedef long long LL;
int qmi(int a,int b,int p){
    int res = 1;
    while(b){
        int k = b & 1;
        if(k){
            res = (LL)res * a % p;
        }
        a = (LL)a * a % p;
        b>>=1;
    }
    return res;
}
int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        int a,b,p;
        scanf("%d%d%d",&a,&b,&p);
        int res = qmi(a,b,p);
        printf("%d",res);
    }
    return 0;

}