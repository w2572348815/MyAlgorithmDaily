/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-10-31 19:25:35
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-10-31 19:42:54
 * @FilePath: \MyAlgorithmDaily\yxc\week1 01 02\NumOfReverseOrderPair.cpp
 * @Description: 逆序对数量，归并算法
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>
using namespace std;
int n,coun;
const int N = 100010;
int a[N],help[N];
void merge_sort(int L,int R){
    if(L >= R)return ;
    int mid = L + R >> 1;
    merge_sort(L,mid);
    merge_sort(mid + 1,R);
    int i = L, j = mid + 1,m = 0;
    while(i <= mid && j <= R){
        if(a[i]<=a[j]){
            help[m++] = a[i++];
        }else{
            coun += mid - i + 1;
            help[m++] = a[j++]; 
        }
    }
    while(i <= mid)help[m++] = a[i++];
    while(j <= R)help[m++] = a[j++];
    for(int i = 0;i < m;i++)a[i + L] = help[i];

}
int main(){
    scanf("%d",&n);
    for(int i = 0; i < n;i++)scanf("%d",&a[i]);
    merge_sort(0,n - 1);
    cout<<coun;
}