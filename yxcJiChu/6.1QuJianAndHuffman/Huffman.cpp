/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-12-17 15:36:17
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-12-17 15:43:52
 * @FilePath: \MyAlgorithmDaily\yxcJiChu\6.1QuJianAndHuffman\Huffman.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>
#include<queue>

using namespace std;
const int N = 10010;
int a[N];
int main(){
    int res = 0 ;
    int n ;
    cin >> n;
    int a;
    priority_queue<int , vector<int > , greater<int > > heap; 
    for(int i = 0 ; i < n ; i ++ )scanf("%d",&a),heap.push(a);
    while(heap.size()!=1){
        int a,b;
        a = heap.top();
        heap.pop();
        b = heap.top();
        heap.pop();
        heap.push(a + b);
        res += a + b;
    }
    cout<<res;
    return 0;
}