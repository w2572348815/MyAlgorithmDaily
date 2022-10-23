/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-10-23 13:51:19
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-10-23 14:05:39
 * @FilePath: \MyAlgorithmDaily\yxc\1.2HighPrecisionAndQianZhuiHeAndChaFen\A+B.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */

#include<iostream>
#include<string>
#include<vector>
using namespace std;
int N = 1e6 + 10;

int main(){
    string a,b;
    cin>>a>>b;
    vector<int > A;
    vector<int > B;
    for(int i = a.size() - 1; i >= 0;i--)A.push_back(a[i] - '0');
    for(int i = b.size() - 1; i >= 0;i--)B.push_back(b[i] - '0');
    int t= 0 ;
    vector<int > C;
    for(int i = 0; i < A.size()||i < B.size()||t!=0;i++){
        if(i<A.size())t += A[i];
        if(i<B.size())t += B[i];
        C.push_back(t%10);
        t /= 10;
    }
    for(int i = C.size() - 1; i >= 0;i--)printf("%d",C[i]);
    return 0;
}