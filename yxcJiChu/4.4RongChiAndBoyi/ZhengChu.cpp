/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-12-12 10:15:15
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-12-12 10:36:51
 * @FilePath: \MyAlgorithmDaily\yxcJiChu\4.4RongChiAndBoyi\ZhengChu.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>
#include<algorithm>

using namespace std;

const int M = 20;
int p[M];
typedef long long LL;
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int res = 0;
    for(int i = 0 ; i < m ; i ++ ){
        scanf("%d",&p[i]);
    }
    for(int i = 1 ; i < 1 << m ; i ++ ){
        int psum = 1 , cnt = 0;
        for(int j  = 0 ; j < m ; j ++ ){
            if(i >> j & 1){
                
                cnt++;
                if((LL)psum * p[j]> n){
                    psum = -1;
                    break;
                }
                psum *= p[j];
                
            }
        } 
        if(psum != -1){
            if(cnt % 2){
                res += n / psum;
                }else{
                        res -= n / psum;
                }
        }
        
        
    }
    cout<<res<<endl;
    return 0;
}