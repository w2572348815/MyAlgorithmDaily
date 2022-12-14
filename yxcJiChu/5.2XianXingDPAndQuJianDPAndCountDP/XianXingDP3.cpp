/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-12-13 19:29:54
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-12-13 19:46:41
 * @FilePath: \MyAlgorithmDaily\yxcJiChu\5.2XianXingDPAndQuJianDPAndCountDP\XianXingDP3.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>
#include<algorithm>

using namespace std;
const int N = 1010;
char a[N],b[N];
int f[N][N];

int main(){
    int n,m;
    cin>>n>>m;
    scanf("%s%s", a + 1, b + 1);
    // for(int i = 1 ; i <= n ; i++ )cin>>a[i];
    // for(int i = 1 ; i <= m ; i ++ )cin>>b[i];
    for(int i = 1 ; i<= n ; i ++ )
        for(int j = 1 ; j <= m ; j ++){
            f[i][j] = max(f[i - 1][j] , f[i][j - 1]);
            if(a[i] == b[j])f[i][j] = max(f[i][j] , f[i - 1][j - 1] + 1);
        }
    cout<<f[n][m];
    return 0 ; 
}
