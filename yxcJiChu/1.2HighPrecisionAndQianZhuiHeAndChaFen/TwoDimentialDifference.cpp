/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-10-23 17:48:18
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-10-31 19:21:38
 * @FilePath: \MyAlgorithmDaily\yxc\1.2HighPrecisionAndQianZhuiHeAndChaFen\TwoDimentialDifference.cpp
 * @Description: 二维差分
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>

using namespace std;

const int N = 1010;
int n,m;
int a[N][N],c[N][N];
void insert(int x1,int y1,int x2,int y2,int num){
    c[x1][y1] += num;
    c[x2 + 1][y1] -= num;
    c[x1][y2 + 1] -= num;
    c[x2 + 1][y2 + 1] += num;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i = 1; i <= n;i++)
        for(int j = 1;j <= m;j++)
            scanf("%d",&a[i][j]);
    for(int i = 1; i <= n;i++)
        for(int j = 1;j <= m;j++){
            insert(i,j,i,j,a[i][j]);
        }
    int q;
    scanf("%d",&q);
    while(q--){
        int x1,x2,y1,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        int num;
        scanf("%d",&num);
        insert(x1,y1,x2,y2,num);
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m ; j++){
            c[i][j] += c[i - 1][j] + c[i][j - 1]  - c[i - 1][j - 1]; 
        }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m ; j++)
            printf("%d ",c[i][j]);
     printf("\n");       
    }   

    return 0;
}