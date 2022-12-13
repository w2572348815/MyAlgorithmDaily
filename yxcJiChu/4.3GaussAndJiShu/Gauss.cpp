/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-11-20 22:44:40
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-12-11 12:41:19
 * @FilePath: \MyAlgorithmDaily\yxcJiChu\4.3GaussAndJiShu\Gauss.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int N = 110;
double a[N][N];
int n;
const int eps = 1e-6;
int guass(){
    int row = 0,col = 0;
    for( ; col < n ; col ++ ){
        int t = row;
        for(int i = row + 1 ; i < n ; i ++ ){
            if(fabs(a[t][col]) < fabs(a[i][col]))t = i;
        }
        if(fabs(a[t][col]) < eps)continue;
        for(int i = col ; i <= n ; i ++ )swap(a[t][i],a[row][i]);
        for(int i = n ; i >= col ; i -- )a[row][i] /= a[row][col];
        for(int i = row + 1 ; i < n ; i ++ )
            if(fabs(a[i][col]) > eps)
            for(int j = n ; j >= col ; j -- ){
                a[i][j] -= a[row][j] * a[i][col];
            }
        row++;
    }
    //一个解
    if(row == n){
        for(int i = n - 1 ; i >= 0 ; i -- ){
            for(int j = i + 1 ; j < n ; j ++){
                a[i][n] -= a[j][n]*a[i][j];
            }
        }
        return 0;
    }else{
        //无解
        for(int i = n - 1 ; i >= row ; i -- )if(fabs(a[i][n] > eps))return 2;
        //无穷多解
        return 1;
    }
    
}
int main(){
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i ++ )
        for(int j = 0 ; j <= n ; j ++ )scanf("%lf",&a[i][j]);
    int res =  guass();
    //唯一解
    if(res == 0){
        for(int i = 0 ; i < n ; i ++ )printf("%.2lf ",a[i][n]);
    }
    //无穷多解
    if(res == 1){
        printf("无穷多解");
    }
    //无解
    if(res == 2){
        printf("无解");
    }    
    return 0;
}