/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-12-15 10:47:24
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-12-15 17:09:57
 * @FilePath: \MyAlgorithmDaily\yxcJiChu\5.3ShuWeiAndZhuangTaiYaSuoAndShuXingDPAndJIYi\ZhuangTaiDP.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 12 , M = 1 << N;
long long f[N][M];
bool st[M];

int main(){
    int n, m; 
    while(cin>>n>>m , n || m){
        memset(f , 0 , sizeof f);
        for(int i  = 0 ; i < 1 << n ;i ++ ){
            st[i] = true;
            int cnt = 0 ;
            for(int j = 0 ; j < n ; j ++ ){
                if(i >> j & 1){
                    if(cnt % 2)st[i]  = false;
                        cnt = 0;
                }else{
                    cnt++;
                }
            }
            if(cnt % 2){
                st[i] = false;
            }
        }
        f[0][0] = 1;
        for(int i = 1 ; i <= m ; i ++ ){
            for(int j = 0 ; j < 1 << n ; j ++ ){
                for(int k = 0 ; k < 1 << n ; k ++ ){
                    if((j & k) == 0 && st[j | k]){
                        f[i][j] += f[i - 1][k];
                    }
                }
            }
        }
        cout<<f[m][0]<<endl;
        

    }
    return 0;
}