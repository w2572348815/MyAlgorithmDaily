/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-11-01 22:39:49
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-11-02 15:40:37
 * @FilePath: \MyAlgorithmDaily\yxc\1.5TrieTreeAndSetAndHeap\MyHeap.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>
#include<string.h>
using namespace std;

const int N = 100010;
int h[N],hp[N],ph[N],s,k;
int n;
void hswap(int a,int b){
    swap(ph[hp[a]],ph[hp[b]]);
    swap(hp[a],hp[b]);
    swap(h[a],h[b]);
}
void down(int i){
    int t = i;
    if(2*i <= s && h[i] > h[2*i]) t = 2*i;
    if(2*i + 1 <= s && h[2*i + 1] < h[t])t = 2*i + 1;
    if(t!=i)hswap(i,t),down(t);
}
void up(int i){
    while(i/2 && h[i/2] > h[i]){
        hswap(i,i/2);
        i /= 2;
    }
}
int main(){
    cin>>n;
    while(n--){
        char op[5];
    cin>>op;
    if(op[0] == 'I'){
        int x;
        cin>>x;
        s++,k++;
        h[s] = x;
        ph[k] = s;
        hp[s] = k;
        up(s);
    }else if(op[0] == 'P'){
        if(s>=1)cout<<h[1]<<endl;
    }else if(!strcmp(op,"DM")){
        hswap(1,s--);
        down(1);
    }else if(!strcmp(op,"D")){
        int x;
        cin>>x;
        x = ph[x];
        hswap(x,s--);
        down(x),up(x);
    }else{
        int q,w;
        cin>>q>>w;
        q = ph[q];
        h[q] = w;
        down(q),up(q);
    }
    }
    return 0;
}