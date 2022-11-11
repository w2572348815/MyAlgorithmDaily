/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-10-23 14:34:26
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-10-23 14:51:22
 * @FilePath: \MyAlgorithmDaily\yxc\1.2HighPrecisionAndQianZhuiHeAndChaFen\Achub.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 vector<int > div(vector<int >&a,int b,int &r){
    int t = 0;
    r = 0;
    vector<int > c;
    for(int i = a.size() - 1; i >= 0;i--){
        r = r*10 + a[i];
        c.push_back(r / b);
        r %= b;
    }
    reverse(c.begin(),c.end());
    while(c.size() > 1 && c.back() == 0)c.pop_back();
    return c;
 }
int main(){
    string a;
    int b;
    cin>>a>>b;
    vector<int > A;
    for(int i = a.size() - 1; i >= 0;i--){
        A.push_back(a[i] - '0');
    }
    int r;
    vector<int >c = div(A,b,r);

    for(int i = c.size() - 1;i >= 0;i-- )printf("%d",c[i]);
    printf("余数为 %d",r);
    return 0;

}