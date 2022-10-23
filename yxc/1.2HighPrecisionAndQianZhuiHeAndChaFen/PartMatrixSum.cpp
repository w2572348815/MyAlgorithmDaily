/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-10-23 15:06:51
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-10-23 15:33:12
 * @FilePath: \MyAlgorithmDaily\yxc\1.2HighPrecisionAndQianZhuiHeAndChaFen\PartMatrixSum.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>
using namespace std;
const int N = 10010;
int m;
int n;

int a[N][N];
int s[N][N];
int main(){
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i++ )
        for(int j = 1; j <= m;j++)
            scanf("%d",&a[i][j]);
    
    
    for(int i = 1; i <= n;i++)
            for(int j = 1;j <= m;j++){
                s[i][j] = s[i - 1][ j] + s[i][j - 1] +a[i][j] - s[i- 1][j- 1];
            }
    int c;
    scanf("%d",&c);
    while(c--){
        int x1,x2,y1,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        printf("%d",s[x2][y2] - s[x2][y1 -1] - s[x1 - 1][y2] + s[x1-1][y1 -1]);
    }
    return 0;
}