/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-11-02 16:30:46
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-11-02 16:43:36
 * @FilePath: \MyAlgorithmDaily\yxc\1.6Hash\HashLaLianFa.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>
#include<cstring>
using namespace std;

const int N = 100003;
int h[N],e[N],ne[N],idx;
void insert(int x){
    e[idx] = x;
    x = (x%N + N)%N;
    ne[idx] = h[x];
    h[x] = idx++;
}
bool find(int x){
    int k = (x%N+N)%N;
    for(int i = h[k];i!=-1;i = ne[i]){
        if(e[i] = x)return true;
    }
    return false;
}
int main(){
    int n ;
    cin>>n;
    memset(h, -1, sizeof h);
    while(n--){
        char op[2];
        cin>>op;
        if(op[0] == 'I'){
            int x;
            cin>>x;
            insert(x);
        }else{
            int x;
            cin>>x;
            if(find(x))cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }
    return 0;
}