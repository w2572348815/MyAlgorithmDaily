/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-12-16 21:53:09
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-12-17 10:55:19
 * @FilePath: \MyAlgorithmDaily\yxcJiChu\6.1QuJianAndHuffman\QuJIanQuestion.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 100010;
struct qujian{
    int l , r;
    bool operator < (const qujian & w){
        return r < w.r;
    }
}a[N];

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i ++ ){
        int l , r;
        scanf("%d%d",&l,&r);
        a[i] = {l , r};
    }
    sort(a, a + n);
    int ed = -2e9 , res = 0;
    for(int i = 0 ; i < n ; i ++ ){
        if(a[i].l > ed){
            res ++ ;
            ed = a[i].r;
        }
    }    
    cout<<res;
    return 0;
}