/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-10-25 19:39:44
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-10-28 21:12:51
 * @FilePath: \MyAlgorithmDaily\MySBCode\a.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>
using namespace std;
int n;
int a[1010];
int main(){
    cin>>n;
    for(int i = 0;i < n;i++){
        cin>>a[i];
    }
    
    for(int i = 0;i  < n;i++){
        int count = 0;
        if(a[i]==1){
            cout<<count<<endl;
            continue;
        }
        if(a[i]%3!=0){
            cout<<"-1"<<endl;
            continue;
        }
        while(a[i]%6==0){
            a[i] /= 6;
            count++;
        }
        while(a[i]%3==0){
            a[i] /= 3;
            count += 2;
        }
        if(a[i] == 1)cout<<count<<endl;
        else cout<<"-1"<<endl;
    }
}