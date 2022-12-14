/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-12-14 19:07:41
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-12-14 19:37:42
 * @FilePath: \MyAlgorithmDaily\yxcJiChu\week8 15\YaWeiAdd.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>
#include<vector>

using namespace std;
const int N = 1e9;
vector<int> add(vector<int > &a , vector<int > & b){
    if(a.size() < b.size()){
        return add(b,a);
    }
    vector<int > c;
    int t = 0;
    for(int i= 0 ; i < a.size() ; i ++){
        t += a[i];
        if(i < b.size())t += b[i];
        c.push_back(t % N);
        t /= N;
    } 
    if(t){
        c.push_back(t);
    }
    return c;

}

int main(){
    string a,b;
    cin >> a >> b;
    vector<int > va;
    vector<int > vb;
    for(int i = a.size() - 1 , s = 0 , k = 1 , j = 0 ; i >= 0 ; i -- ){
        s += k * (a[i] - '0');
        k *= 10;
        j ++ ;
        if(j == 9 || i == 0){
            va.push_back(s);
            s = 0;
            j = 0;
            k = 1;
        }
    }
    for(int i = b.size() - 1 ,s = 0 , j = 0 , k = 1; i >= 0 ; i -- ){
        s += k *(b[i] - '0');
        j ++ ;
        k *= 10;
        if(j == 9 || i == 0){
            vb.push_back(s);
            s = 0;
            j = 0;
            k = 1;
        }
    }
    vector<int > c = add(va , vb);
    cout<<c.back();
    for(int i = c.size() - 2 ; i >= 0 ; i-- ){
        printf("%9d",c[i]);
    }
    return 0;

}