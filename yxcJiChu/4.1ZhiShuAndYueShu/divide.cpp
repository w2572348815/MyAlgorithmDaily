/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-11-11 18:54:24
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-11-11 19:45:55
 * @FilePath: \MyAlgorithmDaily\yxcJiChu\4.1ZhiShuAndYueShu\divide.cpp
 * @Description: 分解质因数,试除法
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

void divide(int n){
    for(int i = 2;i <= n / i; i ++){
        if(n % i == 0){
            int s = 0;
            while(n % i == 0){
                n /= i;
                s++;
            }
            cout<<i<<" "<<s<<endl;
        }
    }
    if(n > 1)cout<<n<<" "<<"1"<<endl;
}
int main(){
    int n;
    cin>>n;
    divide(n);
    return 0;
}