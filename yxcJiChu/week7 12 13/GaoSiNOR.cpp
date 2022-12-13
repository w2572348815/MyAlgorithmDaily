/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-12-13 09:32:55
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-12-13 10:01:38
 * @FilePath: \MyAlgorithmDaily\yxcJiChu\week7 12 13\GaoSiNOR.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>

using namespace std;

const int N = 110;
int a[N][N];
int n;

int gauss(){
    int col,row;
    for(col = 0 , row = 0 ; col < n ; col ++ ){
        int t = row;
        for(int i = t ; i < n ; i ++ ){
            if(a[i][col]){
                t = i ;
                break;
            }
        }
        if(!a[t][col])continue;
        for(int i = col ; i <= n ; i ++ )swap(a[t][i],a[row][i]);
        for(int i = row + 1 ; i < n ; i ++ ){
            if(a[i][col]){
                for(int j = col ; j <= n ; j ++ ){
                    a[i][j] = a[i][j] ^ a[t][j];
                }
            }
        }
        row++;
    }
    if(row == n){
        for(int i = n - 1 ; i >= 0 ; i -- ){
            for(int j = i + 1 ; j < n ; j ++ ){
                a[i][n] ^= a[i][j] & a[j][n];
            }
        }
        return 1;
    }else{
        for(int i = n - 1 ; i >= row ; i -- ){
            if(a[i][n])return 0;
        }
        return 2;
    }
}

int main(){
    cin>>n;
    for(int i = 0 ; i < n ;i ++ )
        for(int j = 0 ; j <= n ; j ++ )cin>>a[i][j];
    int res = gauss();
    //无解
    if(!res)cout<<"No";
    else{
        //唯一解
        if(res == 1){
            for(int i = 0 ; i < n ; i ++ ){
                cout<<" "<<a[i][n];
            }
        }else{
            cout<<"wushujie";
        }
    } 
    return 0 ; 
}