/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-11-19 22:59:59
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-11-20 08:22:25
 * @FilePath: \MyAlgorithmDaily\yxcJiChu\4.2OlaAndQmiAndEXgcdAndChinaLeft\ola.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>

using namespace std;

int main(){
    int n ;
    scanf("%d",&n);
    while(n--){
        int a;
        cin>>a;
        int res = a;
        for(int i = 2; i <= a / i;i ++ ){
            if(a % i == 0){
                res  = res / i *(i - 1);
                while(a % i == 0)a /= i;
            }
        }
        if(a > 1)res = res / a * (a - 1);
        cout<<res<<endl;
    }
    return 0;
}