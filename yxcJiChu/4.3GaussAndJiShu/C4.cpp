/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-12-11 15:07:19
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-12-11 20:07:09
 * @FilePath: \MyAlgorithmDaily\yxcJiChu\4.3GaussAndJiShu\C4.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
const int N = 5010;
int primes[N];
int cnt;
bool st[N];
int sum[N];
void get_primes(int n){
    for(int i = 2 ; i <= n ; i ++ ){
        if(!st[i]){
            primes[cnt++] = i;
        }
        for(int j = 0 ; primes[j] <= n / i ; j ++ ){
            st[primes[j] * i] = true;
            if(i % primes[j] == 0)break;
        }
    }
}
int get(int a , int p){
    int res = 0;
    while(a){
        res += a / p ;
        a /= p;
    }
    return res;
}
vector<int> mul(vector<int> a,int b){
    vector<int > c ;
    int t = 0;
    for(int i = 0 ; i < a.size() ; i ++ ){
        t += a[i] * b;
        c.push_back(t % 10);
        t /= 10;
    }
    while(t){
        c.push_back(t % 10);
        t /= 10;
    }
    return c;
}
int main(){
    int a,b;
    cin>>a>>b;
    get_primes(a);
    for(int i = 0 ; i < cnt ; i ++ ){
        int p = primes[i];
        sum[i] = get(a,p) - get(a - b , p) - get(b , p);
    }
    vector<int > res;
    res.push_back(1);
    for(int i = 0 ; i < cnt ; i ++ ){
        for(int j = 0 ; j < sum[i] ; j ++ ){
            res = mul(res , primes[i]);
        }
    }
    for(int i = res.size() - 1; i >= 0 ; i -- ){
        printf("%d",res[i]);
    }
    return 0;
}