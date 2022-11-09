/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-11-04 10:19:51
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-11-04 10:47:43
 * @FilePath: \MyAlgorithmDaily\yxc\3.1BFSAndDFSAndMap\ToPuSort.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 100010;
int n,m;
int h[N],e[N],ne[N],idx,ru[N];
int q[N],hh = 0,tt = -1;
void add(int a,int b){
    e[idx] = b,ne[idx] = h[a],h[a] = idx++;
}
bool topu_sort(){
    for(int i = 1;i <= n;i++){
        if(ru[i]==0){
            q[++tt] = i;
        }
    }
    while(hh <= tt){
        int t = q[hh++];
        for(int i = h[t];i!=-1;i = ne[i]){
            int x = e[i];
            ru[x]--;
            if(ru[x]==0){
                q[++tt] = x;
            }
        }

    }
    return tt == n - 1;
}
int main(){
    cin>>n>>m;
    int a,b;
    memset(h,-1,sizeof h);
    for(int i = 0;i < m;i++){
        cin>>a>>b;
        add(a,b);
        ru[b]++;
    }
    if(topu_sort()){
        for(int i = 0;i < n;i++){
            cout<<q[i]<<" ";
        }
    }else{
        cout<<"-1";
    }
    return 0;

}