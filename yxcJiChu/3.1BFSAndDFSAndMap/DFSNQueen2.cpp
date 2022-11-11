/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-11-03 13:03:30
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-11-03 13:34:55
 * @FilePath: \MyAlgorithmDaily\yxc\1.7BFSAndDFSAndMap\DFSNQueen2.cpp
 * @Description: 时间复杂度2^n^2
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>

using namespace std;

int n;
const int N = 20;
char ans[N][N];
bool row[N],col[N],dg[N],udg[N];
void dfs2(int r,int c,int s){
    if(c == n)r++,c = 0;
    if(r == n){
        if(s == n){
            for(int i = 0 ; i < n;i++)puts(ans[i]);
            puts("");
        }
        return ;
    }
    dfs2(r,c+1,s);
    if(!row[r]&&!col[c]&&!dg[r+c]&&!udg[r-c+n]){
        ans[r][c] = 'Q';
        row[r] = col[c] = dg[r+c] = udg[r - c + n] = true;
        dfs2(r,c+1,s+1);
        row[r] = col[c] = dg[r+c] = udg[r - c + n] = false;
        ans[r][c] = '.';
    }
}
int main(){
    cin>>n;
    for(int i = 0;i < n;i++)
        for(int j = 0;j < n;j++)
            ans[i][j] = '.';
    dfs2(0,0,0);
    return 0;
}