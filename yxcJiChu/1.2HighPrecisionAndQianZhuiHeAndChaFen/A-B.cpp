/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-10-23 14:06:07
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-10-23 14:23:00
 * @FilePath: \MyAlgorithmDaily\yxc\1.2HighPrecisionAndQianZhuiHeAndChaFen\A-B.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>
#include<vector>

using namespace std;

const int N = 1e6+10;
vector<int> sub(vector<int> &a,vector<int> &b){
    vector<int > c;
    int t = 0;
    for(int i = 0;i < a.size()|| i < b.size();i++){
        t = a[i] - t;
        if(i < b.size())t -= b[i];
        c.push_back((t+10)%10);
        if(t >= 0)t = 0;
        else t = 1;
    }
    while(c.size() > 1 && c.back() == 0)c.pop_back();
    return c;
}
int main(){
    string a,b;
    cin>>a>>b;
    vector<int > A;
    vector<int > B;
    for(int i = a.size() - 1; i >= 0;i--)A.push_back(a[i] - '0');
    for(int i = b.size() - 1; i >= 0; i--)B.push_back(b[i] - '0');
    vector<int>C = sub(A,B);
    for(int i = C.size() - 1;i >= 0;i--)printf("%d ",C[i]);
    return 0;
}