/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-10-22 18:48:57
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-10-22 19:00:03
 * @FilePath: \MyAlgorithmDaily\yxc\1.1sortAndDichotomy\merge_sort.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>

using namespace std;
const int N = 1000010;
int temp[N];
void merge_sort(int a[],int L,int R){
    if(L >= R)return ;
    int mid = L + R >> 1;
    merge_sort(a , L , mid);
    merge_sort(a , mid + 1 , R);
    int k = 0;
    int i = L;
    int j = mid + 1 ;
    while(i <= mid && j <= R){
        if(a[i] < a[j])temp[k++] = a[i++];
        else temp[k++] = a[j++];        
    }
    while(i<=mid)temp[k++] = a[i++];
    while(j<=R)temp[k++] = a[j++];
    for(i = L,j = 0;i <= R;i++,j++){
        a[i] = temp[j];
    }
}
int main(){
    int a[15] = {1,2,3,12,3,42,123,123,12,43,65,90};
    for(int i = 0;i<12;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    merge_sort(a,0,11);
    for (int i = 0; i < 12; i++)
    {
        /* code */
        cout<<a[i]<<" ";
    }
    
}