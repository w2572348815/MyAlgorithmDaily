/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-11-01 21:48:30
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-11-01 22:10:27
 * @FilePath: \MyAlgorithmDaily\yxc\1.5TrieTreeAndSetAndHeap\HeaoSort.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>
using namespace std;
int n,m;
const int N = 100010;
int a[N],s;
void down(int i){
    int t = i;
    if(2*i <= s && a[2*i] < a[t])t = 2*i ;
    if(2*i + 1 <= s && a[2*i + 1] < a[t])t = 2*i + 1;
    if(i!=t)swap(a[i],a[t]),down(t);

}
void up(int i){
    while(i/2&&a[i/2]>a[i]){
        swap(a[i],a[i/2]);
        i = i/2;
    }
}
int main(){
    cin>>n>>m;
    for(int i = 1;i <= n ;i++){
        cin>>a[i];
    }
    s = n;
    for(int i = n / 2;i;i--)down(i);
    while(m--){
        printf("%d ",a[1]);
        a[1] = a[s];
        s--;
        down(1);

    }
    return 0;
}