/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-11-01 18:05:18
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-11-01 19:52:40
 * @FilePath: \MyAlgorithmDaily\yxc\1.5TrieTreeAndSetAndHeap\TrieTree.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>
using namespace std;

const int N = 100010;
int n;
int son[N][26], idx,cnt[N];
char ch[N];
void insert(){
    int p = 0;
    for(int i = 0;ch[i];i++){
        int u = ch[i] - 'a';
        if(!son[p][u])son[p][u] = ++idx;
        p = son[p][u];
    }
    cnt[p]++;
}
int query(){
    int p = 0;
    for(int i = 0;ch[i];i++){
        int u = ch[i] - 'a';
        if(!son[p][u])return 0;
        p = son[p][u];
    }
    return cnt[p];
}
int main(){
    cin>>n;
    while(n--){
        char op[2];
        scanf("%s%s",op,ch);
        if(op[0] == 'I'){
            insert();
            
        }else{
            printf("%d\n",query());
        }
        

    }
    return 0;
}
