/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-12-15 19:25:57
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-12-15 21:43:51
 * @FilePath: \MyAlgorithmDaily\yxcJiChu\5.3ShuWeiAndZhuangTaiYaSuoAndShuXingDPAndJIYi\ZhuangTaiDP2.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
const int N = 20 , M = 1 << N ;
int f[M][N];
int a[N][N];

int main(){
    int n ;
    cin >> n;
    for(int i = 0 ; i < n ; i ++ )
        for(int j = 0 ; j < n ; j ++ )scanf("%d",&a[i][j]);
    memset(f , 0x3f , sizeof f);
    f[1][0] = 0;
    for(int i = 0 ; i < 1 << n ; i ++ )
        for(int j = 0 ; j < n ; j ++ )
            if(i >> j & 1)
                for(int k = 0 ; k < 1 << n ; k ++ )
                    {
                        if((i - (1 << j))>> k & 1){
                            f[i][j] = min(f[i][j] , f[i - (1 << j)][k] + a[k][j]);
                        }
                    }
    cout<<f[(1 << n) - 1][n - 1];
    return 0;
}