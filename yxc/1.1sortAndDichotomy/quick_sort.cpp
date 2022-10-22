/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-10-22 17:12:16
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-10-22 18:37:17
 * @FilePath: \MyAlgorithmDaily\yxc\quick_sort.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>
using namespace std;
void quick_sort(int a[],int L,int R){
    if(L >= R)return;
    int x = a[L];
    int i = L;
    int j = R;
    while(i < j){
        if(a[i]==x&&a[j]==x){
            i++;
            j--;
        }
        while(a[i]<x){
            i++;
        }
        while(a[j]>x){
            j--;
        }
        
        if(i < j)swap(a[i],a[j]);
    }
    quick_sort(a,L,j);
     quick_sort(a,j+1,R);
}
void quick_sort2(int a[],int L,int R){
    if(L >= R) return ;
    int x = a[L];
    int i = L - 1;
    int j = R + 1;
    while(i < j){
        do{
            i++;
        }while(a[i]<x);
        do{
            j--;
        }while(a[j]>x);
        if(i<j)swap(a[i],a[j]);
    }
    quick_sort2(a,L,j);
    quick_sort2(a,j+1,R);

}
int main(){
    int a[15] = {1,2,3,12,3,42,123,123,12,43,65,90};
    for(int i = 0;i<12;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    quick_sort2(a,0,11);
    for (int i = 0; i < 12; i++)
    {
        /* code */
        cout<<a[i]<<" ";
    }
    
}