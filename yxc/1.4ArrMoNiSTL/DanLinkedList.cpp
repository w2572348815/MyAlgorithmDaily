/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-10-31 20:14:55
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-10-31 20:32:08
 * @FilePath: \MyAlgorithmDaily\yxc\1.4ArrMoNiSTL\DanLinkedList.cpp
 * @Description: 数组模拟单链表，速度更快
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>

using namespace std;
int head,idx;
const int N = 100010;
int e[N],ne[N];
void init(){
    head = -1;
    idx = 0;
}
void insert_head(int x){
    e[idx] = x;
    ne[idx] = head;
    head = idx++;
}
void delete_knext(int k){
    ne[k - 1] = ne[ne[k - 1]];
}
void insert_knext(int k,int x){
    e[idx] = x;
    ne[idx] = ne[k - 1];
    ne[k - 1] = idx++;
}
void pr(){
    int i = head;
    while(ne[i]!=-1){
        cout<<e[i]<<' ';
        i = ne[i];
    }
}
int main(){
    int m;
    init();
    scanf("%d",&m);
    char s[10];
    while(m--){
        cin>>s;
        if(s[0] == 'H'){
            int x;
            cin>>x;
            insert_head(x);
        }else if(s[0]=='D'){
            int k;
            cin>>k;
            delete_knext(k);
        }else{
            int k,x;
            cin>>k>>x;
            insert_knext(k,x);
        }

    }
    pr();
    return 0;

}

