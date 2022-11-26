/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-10-25 19:39:44
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-11-25 08:55:51
 * @FilePath: \MyAlgorithmDaily\MySBCode\a.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>
using namespace std;
int main(){
    int a = -58;
    a = (~a+1)&a;
    cout<<a;
}