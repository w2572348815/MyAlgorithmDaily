/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-11-20 22:44:40
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-11-26 10:24:10
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
const double eps = 1e-6;
int n ;
int gauss(){
    for(int col = 0, row = 0; col < n ;col ++){
        
    }


}
int main(){
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i++ ){
        for(int j = 0 ; j <= n ; j++){
            scanf("%d",&a[i][j]);
        }
    }
    int k = gauss();
    if(k == 0){
        cout<<"wujie"<<endl;
    }
    if(k == 1){
        for(int i = 0 ; i < n ; i ++ )printf("%d",a[i][n]);
    }
    if(k == 2){
        printf("wuqiongduo\n");
    }
    return 0 ;
}