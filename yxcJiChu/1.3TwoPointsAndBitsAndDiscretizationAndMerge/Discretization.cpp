/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-10-26 19:29:37
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-10-31 19:22:39
 * @FilePath: \MyAlgorithmDaily\yxc\1.3TwoPointsAndBitsAndDiscretizationAndMerge\Discretization.cpp
 * @Description: 离散化加前缀和
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,m;
int a[300010],s[300010];
vector<int> alls;
typedef pair<int,int> PII;
vector<PII> add,query;
/**
 * @description: 
 * @param {int} x
 * @return {*}
 */
int find(int x){
    int l = 0;
    int r = alls.size()  - 1;
    while(l < r){
        int mid = l + r >> 1;
        if(alls[mid] >= x){
            r = mid;
        }else{
            l = mid + 1;
        }
    }
    return r + 1;
}
int main(){
    scanf("%d%d",&n,&m);
    int x, c;
    for(int i = 0 ; i < n;i ++){
        scanf("%d%d",&x,&c);
        alls.push_back(x);
        add.push_back({x,c});
    }
    int l,r;
    for(int i =  0; i < m;i ++){
        scanf("%d%d",&l,&r);
        alls.push_back(l);
        alls.push_back(r);
        query.push_back({l,r});
    }
    sort(alls.begin(),alls.end());
    alls.erase(unique(alls.begin(),alls.end()),alls.end());
    for(PII v : add){
        int index = find(v.first);
        a[index] += v.second;
    }
    for(int i = 1; i <=alls.size();i++){
        s[i]  = s[i - 1] + a[i];
    }
    for(PII v : query){
        int l = find(v.first);
        int r = find(v.second);
        cout<<s[r] - s[l - 1]<<endl;
    }
    

}
