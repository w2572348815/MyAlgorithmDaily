/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-12-14 10:12:44
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-12-14 10:33:13
 * @FilePath: \MyAlgorithmDaily\yxcJiChu\week8 15\Edit_distance2.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>
#include<cstring>
using namespace std;

const int N = 1010, M = 15;
int n,m;
char st[N][M];
int f[N][N];
int edit(char a[] ,char b[]){
    int la = strlen(a + 1);
    int lb = strlen(b + 1);
    for(int i = 0 ; i <= lb ; i ++ )f[0][i] = i;
    for(int i = 0 ; i <= la ; i ++)f[i][0] = i;
    for(int i = 1 ; i <= la ; i ++ )
        for(int j = 1 ; j <= lb ; j ++ ){
            f[i][j] = min(f[i - 1][j] + 1 , f[i][j - 1] + 1 );
            f[i][j] = min(f[i][j] , f[i - 1][j - 1] + (a[i] != b[j]));
        }
    return f[la][lb];

}

int main(){
    scanf("%d%d",&n,&m);
    for(int i = 0 ; i < n ; i ++ ){
        scanf("%s" , st[i] + 1);
    } 
    while(m -- ){
        char a[N];
        int limits;
        scanf("%s%d",a + 1, &limits);
        int res = 0;
        for(int i = 0 ; i < n; i ++ ){
            if(edit(st[i],a) <= limits)res ++ ;
        }
        printf("%d",res);
    }
    return 0;
}