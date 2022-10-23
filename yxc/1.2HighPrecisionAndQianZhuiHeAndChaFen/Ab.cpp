/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-10-23 14:23:27
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-10-23 14:33:19
 * @FilePath: \MyAlgorithmDaily\yxc\1.2HighPrecisionAndQianZhuiHeAndChaFen\Ab.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>
#include<vector>
using namespace std;
vector<int > mul(vector<int> &a,int b){
    vector<int> c;
    int t = 0;
    for(int i = 0;i < a.size()||t;i++){
        if(i < a.size())t += a[i]*b;
        c.push_back(t%10);
        t /= 10; 
    }

    return c;
}
int main(){
    string a;
    int b;
    cin>>a>>b;
    vector<int >A;
    for(int i = a.size() - 1; i >= 0;i--)A.push_back(a[i] - '0');
    vector<int > c = mul(A,b);
    for(int i = c.size() - 1;i >= 0;i--)printf("%d",c[i]);
    return 0;

}