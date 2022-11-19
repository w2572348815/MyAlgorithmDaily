/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-11-12 15:01:06
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-11-12 15:41:50
 * @FilePath: \MyAlgorithmDaily\yxcJiChu\4.1ZhiShuAndYueShu\YueShuGeShu.cpp
 * @Description: 求乘积的约数个数
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>
#include<algorithm>
#include<unordered_map>


using namespace std;
const int mod = 1e9 + 7;
typedef long long LL;
int main(){
    unordered_map<int,int> primes;
    int n;
    cin>>n;
    while(n--){
        int x;
        cin>>x;
        for(int i = 2; i <= x / i;i++){
            while(x % i == 0){
                x /= i;
                primes[i] ++;
            }
        }
        if(x > 1)primes[x]++;
    }
    LL res = 1;
    for(auto prime:primes)res= res*(prime.second + 1)%mod;
    cout<<res;
    return 0;
}