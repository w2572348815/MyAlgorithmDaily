/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-11-02 16:44:17
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-11-02 18:28:24
 * @FilePath: \MyAlgorithmDaily\yxc\1.6Hash\HashOpenAddress.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>
#include<cstring>
using namespace std;
const int N = 200003,null = 0x3f3f3f3f;
int h[N];
int find(int i){
    int k = (i % N + N) % N;
    if(k == null)return k;
    while(h[k]!=null&&h[k]!=i){
        k++;
        if(k == N)k = 0;
    }
    return k;
}

int main(){
    memset(h,0x3f,sizeof h);
    int n;
    cin>>n;
    while(n--){
        char op[2];
        int x;
        
        
        cin>>op>>x;
        int k = find(x);
        if(op[0] == 'I')h[k] = x;
        else{
            if(h[k]!=null)puts("yes");
            else puts("no");
        }
        
    }

}