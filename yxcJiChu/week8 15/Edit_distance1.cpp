/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-12-14 10:01:42
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-12-14 10:11:28
 * @FilePath: \MyAlgorithmDaily\yxcJiChu\week8 15\Edit_distance1.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>

using namespace std;

const int N = 1010;
char a[N],b[N];
int f[N][N];
int main(){
    int n , m;
    scanf("%d%s",&n,a + 1);
    scanf("%d%s",&m,b + 1);
    for(int i = 0 ; i <= n ; i ++ )f[i][0] = i;
    for(int i = 0 ; i <= n ; i ++ )f[0][i] = i;
    for(int i = 1 ; i <= n ; i ++ ){
        for(int j = 1 ; j <= m ; j ++ ){
            f[i][j] = min(f[i - 1][j] + 1 , f[i][j - 1] + 1);
            if(a[i] == b[j])f[i][j] = min(f[i][j] , f[i - 1][j - 1]);
            else f[i][j] = min(f[i][j],f[i - 1][j - 1] + 1); 
        }
    }
    cout<<f[n][m];
    return 0;
}