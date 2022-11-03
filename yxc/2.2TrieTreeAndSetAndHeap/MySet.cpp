/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-11-01 19:55:44
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-11-01 20:24:47
 * @FilePath: \MyAlgorithmDaily\yxc\1.5TrieTreeAndSetAndHeap\MySet.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>
using namespace std;
int n,m;
const int N = 100010;
int father[N];
int find(int x){
    if(father[x] != x){
        father[x] = find(father[x]);
    }
    return father[x];
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i = 1; i <= n;i++)father[i] = i;
    
    while(m--){
        char op[2];
        int a,b;
        scanf("%s%d%d",op,&a,&b);
        if(op[0] == 'M'){
            father[find(a)] = find(b);
        }else{
            if(find(a) == find(b)){
                puts("Yes");

            }else{
                puts("No");
            }
        }
    }
    return 0;


}