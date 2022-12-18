/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-12-17 10:56:40
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-12-17 15:35:31
 * @FilePath: \MyAlgorithmDaily\yxcJiChu\6.1QuJianAndHuffman\FenZu.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;
const int N = 100010;
struct Range{
    int l,r;
    bool operator < (const Range & w) const{
        return l < w.l;
    }
}range[N];
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i ++ ){
        int l , r;
        scanf("%d%d",&l,&r);
        range[i] = {l , r};
    }
    sort(range , range + n );
    priority_queue<int , vector<int> , greater<int> > heap;
    for(int i = 0 ; i < n ; i ++ ){
        if(heap.empty() || heap.top() > range[i].l){
            heap.push(range[i].r);
        }else{
            heap.pop();
            heap.push(range[i].r);
        }
    }
    cout<<heap.size();
    return 0;
}