/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-12-15 21:47:18
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-12-16 09:22:33
 * @FilePath: \MyAlgorithmDaily\yxcJiChu\5.3ShuWeiAndZhuangTaiYaSuoAndShuXingDPAndJIYi\ShuXingDP.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 6010;
int h[N] , e[N] , ne[N] , idx;
bool has_father[N];
int n;
int w[N];
int f[N][2];

void add(int a, int b){
    e[idx] = b , ne[idx] = h[a] , h[a] = idx ++ ;  
}
void dfs(int k){
    f[k][1] = w[k];
    for(int i = h[k] ; i != -1 ; i = ne[i]){
        int j = e[i];
        dfs(j);
        f[k][1] += f[j][0];
        f[k][0] += max(f[j][0] , f[j][1]);
    }
}
int main(){
    scanf("%d",&n);
    memset(h , -1 , sizeof h);
    for(int i = 1 ; i <= n ; i ++ ) scanf("%d",&w[i]);
    for(int i = 1 ; i < n ; i ++ ){
        int a ,b ;
        cin >> a >> b;
        add(b , a);
        has_father[a] = true; 
    }
    int k = 1;
    for(int i = 1 ; i <= n ; i ++ ){
        if(!has_father[i]){
            k = i;
            break;
        }
    }
    dfs(k);

    cout<<max(f[k][0] , f[k][1]);
    return 0;
}