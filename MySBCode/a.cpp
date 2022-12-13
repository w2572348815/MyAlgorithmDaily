/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-10-25 19:39:44
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-12-06 12:21:44
 * @FilePath: \MyAlgorithmDaily\MySBCode\a.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>
using namespace std;
const int N = 1010;
int n,m;
int a[N][N];
bool st[N];
int main(){
    cin>>n>>m;
    int flag = 1;
    for(int i = 0; i < m ; i ++ ){
        int c,b;
        cin>>b;
        if(i!=0 && b!=c){
            flag = 0;
            break;
        }
        cin>>c;
        if(a[b][c] == 1){
            flag = 0;
            break;
        }
        a[b][c] = 1;
        a[c][b] = 1;
        st[b] = st[c] = true;
    }
    for(int i = 1; i <= n ; i ++ ){
        if(!st[i]){
            flag = 0;
            break;
        }
    }

    if(flag == 1)cout<<"Y";
    else cout<<"N";
}