/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-11-12 15:42:12
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-11-12 16:22:18
 * @FilePath: \MyAlgorithmDaily\yxcJiChu\4.1ZhiShuAndYueShu\YueShuZhiHe.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;
typedef long long LL;
const int mod = 1e9 + 7;
int main(){
    int n;
    cin>>n;
    unordered_map<int ,int> primes;
    while(n--){
        int x;
        cin>>x;
        for(int i = 2; i <= x / i;i++){
            while(x % i == 0){
                x /= i;
                primes[i]++;
            }
        }
        if(x > 1)primes[x]++;
    }
    LL res = 1;
    for(auto prime:primes){
        int p = prime.first,a = prime.second;
        LL t = 1;
        while(a--){
            t = (t * p + 1) % mod;
        }
        res = res * t % mod;

    }
    cout<<res;
    return 0;
}