/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-09-26 22:17:44
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-09-27 14:44:29
 * @FilePath: \MyAlgorithmDaily\questionsAndSolutionS.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>
#include<queue>
using namespace std;
//整型数组中一个数出现了奇数次，其余数出现偶数次，怎么求出现奇数次那个数O(n)
int findAppearedOddTimeOnlyNum(int *arr,int n){
    int ans  = arr[0];
    for(int i = 1;i < n;i++){
        ans ^= arr[i];
    }
    return ans;
}
//整型数组中两个数出现了奇数次，其余数出现偶数次，怎么求出现奇数次那俩数O(n)
int *findAppearedOddTimeTwoNum(int *arr,int n){
    int ans = arr[0];
    for(int i = 1;i < n;i++){
        ans ^= arr[i];
    }
    int rightOne = (~ans + 1) & ans;
    int ans1 = arr[0];
    for(int i = 1;i < n;i++){
        if(arr[i]&rightOne){
            ans1 ^= arr[i];
        }
    }
    ans ^= ans1;
    int *res = new int[2];
    res[0] = ans;
    res[1] = ans1;
    return res;
}
//有序数组中找一个元素是否存在(二分法)
int dichotomyFind(int *arr,int n,int num){
    int L = 0;
    int R = n - 1;
    while(L <= R){
        int mid = (L  + R)/2;
        if(arr[mid] > num){
            R = mid - 1;
        }else if(arr[mid] < num){
            L = mid + 1;
        }else{
            return mid;
        }
    }
    return -1;

}
//有序数组中找>=某个数最左侧的位置（二分法)
int dichotomyLeft(int *arr,int n,int num){
    int L = 0;
    int R = n - 1;
    int res = -1;
    while(L<=R){
        int mid = (L + R)/2;
        if(arr[mid] < num){
            L = mid + 1;
        }else if(arr[mid]>=num){
            res = mid;
            R = mid - 1;
        }
    }
    return res;
}
//局部最小值（二分法）条件：arr可以无序且相邻数一定不相等,任意返回一个局部最小值
int localMin(int *arr,int n){
    int L = 0;
    int R = n - 1;
    if(arr == NULL ||n == 0)return -1;
    if(L == R)return L;
    if(arr[L] < arr[L + 1])return L;
    if(arr[R - 1] > arr[R])return R; 
    while(L <= R){
        int mid = (L + R)/2;
        if(arr[mid]<arr[mid+1]&&arr[mid]<arr[mid-1]){
            return mid;
        }else if(arr[mid] > arr[mid + 1]){
            L = mid + 1;
        }else if(arr[mid] > arr[mid-1]){
            R = mid - 1;
        }
    }
    return -1;
}
//已知一一个儿乎有序的数组，儿乎有序是指，如果把数组排好顺序的话，每个元
//素移动的距离可以不超过k，并且k相对于数组来说比较小。请选择- - 个合适的
//排序算法针对这个数据进行排序。
void sortedArrDistanceLessK(int *arr,int n,int k){
    priority_queue<int,vector<int>,greater<int>> queue;
    int i;
    for(i = 0;i < min(n,k);i++){
        queue.push(arr[i]);
    }
    int index = 0;
    for(int j = i;j < n;j++){
        queue.push(arr[j]);
        arr[index++] = queue.top();
        queue.pop();
    }
    while(!queue.empty()){
        arr[index++] = queue.top();
        queue.pop();
    }
}
int main(){
    int arr[20] = {9,10,11,12,22,30,32,65,2,5432,2,5,8};
    int n = localMin(arr,13);
    printf("%d",n);
}