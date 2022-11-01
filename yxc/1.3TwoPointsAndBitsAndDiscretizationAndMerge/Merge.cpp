/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-10-26 22:49:16
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-10-31 19:23:01
 * @FilePath: \MyAlgorithmDaily\yxc\1.3TwoPointsAndBitsAndDiscretizationAndMerge\Merge.cpp
 * @Description: 区间合并
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>
#include<vector>
#include<algorithm>
const int N = 100010;
using namespace std;
typedef pair<int,int> PII;
int n;
int main(){
    scanf("%d",&n);
    vector<PII> v;
    int l,r;
    for(int i = 0;i< n;i++){
        scanf("%d%d",&l,&r);
        v.push_back({l,r});
    }
    vector<PII> res;
    sort(v.begin(),v.end());
    int st = -2e9,ed = -2e9;
    for(PII seg:v){
        if(ed<seg.first){
            if(st!=-2e9)res.push_back({st,ed});
            st = seg.first,ed = seg.second;
        }
        else{
            ed = max(ed,seg.second);
        }
    }
    if(st!=-2e9)res.push_back({st,ed});
    cout<<res.size();
    return 0;
}