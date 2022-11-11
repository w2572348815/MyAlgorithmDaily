/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-10-31 19:42:20
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-10-31 20:11:00
 * @FilePath: \MyAlgorithmDaily\yxc\week1 01 02\SanCiFangGen.cpp
 * @Description: 求一个浮点数的三次方根,用double存数值不然会溢出
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */

#include<iostream>

using namespace std;



int main(){
    double n;
    cin>>n;

    double r = 10000,l = -10000;
    while(r - l > 1e-8){
        double mid = (l + r )/ 2;
        if(mid*mid*mid >= n){
            r = mid;
        }else{
            l = mid;
        }
    }
    printf("%lf",l);
}