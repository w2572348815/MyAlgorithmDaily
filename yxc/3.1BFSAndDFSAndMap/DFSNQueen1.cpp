/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-11-03 09:42:50
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-11-03 13:22:12
 * @FilePath: \MyAlgorithmDaily\yxc\1.7BFSAndDFSAndMap\DFSNQueen1.cpp
 * @Description: 时间复杂度n*n!
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>
using namespace std;
const int N = 20;
int n;
char ans[N][N];
bool col[N],dg[N],udg[N];
void dfs1(int c){
    if(c == n){
        for(int i = 0;i < n;i++)puts(ans[i]);
        puts("");
        return ;
    }
    for(int i = 0;i < n;i++){
        
        if(!col[i]&&!udg[i - c + n]&&!dg[c + i]){
            ans[c][i] = 'Q';
            col[i] = udg[i - c + n] = dg[c + i] = true;
            dfs1(c+1);
            ans[c][i] = '.';
            col[i] = udg[i - c + n] = dg[c + i] = false;
        }
    }
}
int main(){
    cin>>n;
    for(int i = 0;i < n;i++)
        for(int j = 0 ; j < n;j++)
            ans[i][j] = '.';
    dfs1(0);
    puts("");
    return 0;
}