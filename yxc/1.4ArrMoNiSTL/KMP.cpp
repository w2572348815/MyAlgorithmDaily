/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-10-31 22:26:51
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-11-01 17:05:19
 * @FilePath: \MyAlgorithmDaily\yxc\1.4ArrMoNiSTL\KMP.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>

using namespace std;

const int N = 100010;
int ne[N];
char chang[N],duan[N];
int n,m;
void getNext(char s[N]){
    for(int i = 2,j = 0;i <= n;i++){
        while(j && s[j + 1]!= s[i])j = ne[j];
        if(s[j + 1] == s[i])j++;
        ne[i] = j;
    }
    return ;
}
int main(){
    cin>>n>>duan+1>>m>>chang+1;
    getNext(duan);
    for(int i = 1,j = 0;i <= m;i++){
        while(j && chang[i] != duan[j + 1]){
            j = ne[j];
        }
        if(chang[i] == duan[j + 1])j++;
        if(j == n){
            cout<<i - n ;
            j = ne[j];
        }

    }
    return 0;
}