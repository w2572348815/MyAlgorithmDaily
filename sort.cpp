/*
 * @Author: 武家豪&&2572348815@qq.com
 * @Date: 2022-09-25 09:08:59
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-09-25 16:58:37
 * @FilePath: \c++\sort.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by error: git config user.name && git config user.email & please set dead value or install git, All Rights Reserved. 
 */

#include<iostream>
using namespace std;

void swap(int* arr,int n,int m){
    int temp = arr[n];
    arr[n] = arr[m];
    arr[m] = temp;
    return;
}
void printArr(int* arr,int n){
    for(int i = 0;i < n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void selectSort(int* arr,int n){
    int minIndex,temp;
    for(int i = 0;i < n - 1;i++){
        minIndex = i;
        for(int j = i;j < n;j++){
            if(arr[minIndex] > arr[j]){
                minIndex = j;
            }
        }
    swap(arr,minIndex,i);
    }
}
void bubbleSort(int* arr,int n){
    for(int i = n - 1;i > 0;i--){
        for(int j = 1;j <= i;j++){
            if(arr[j-1]>arr[j]){
                swap(arr,j-1,j);
            }
        }
    }
}
void insertSort(int* arr,int n){
    for(int i = 1;i < n;i++){
        for(int j = i;j > 0;j--){
            if(arr[j] < arr[j-1]){
                swap(arr,j,j-1);
            }
        }
    }
}

void processMerge(int *arr,int L,int R){
    if(L == R){
        return;
    }
    int mid = (L+R)/2;
    int *temp = new int[R-L+1];
    int index = 0;
    int i = L,j = mid + 1;
    processMerge(arr,L,mid);
    processMerge(arr,mid+1,R);
    while(i <= mid && j <= R){
        if(arr[i]<=arr[j]){
            temp[index++] = arr[i++];
        }else{
            temp[index++] = arr[j++];
        }
    }
    while(i <= mid){
        temp[index++] = arr[i++];
    }
    while(j <= R){
        temp[index++] = arr[j++];
    }
    for(int i = 0;i < R - L + 1 ;i++ ){
        arr[L + i] = temp[i];
    }
    delete[] temp;
}
void mergeSort(int* arr,int n){
    if(arr == NULL){
        return;
    }
    processMerge(arr,0,n-1);
}





int separate1(int *arr,int L,int R){
    int lessOrEqual = L - 1;
    int i = L, j = R;
    while(i < j){
        if(arr[i] <= arr[R]){
            ++lessOrEqual;
            ++i;
        }else{
            swap(arr,i,j - 1);
            --j;
        }
    }
    swap(arr,R,++lessOrEqual);
    return lessOrEqual;
}
void quickSortProcess1(int *arr,int L,int R){
    if(L >= R)return;
    int index = separate1(arr,L,R); 
    quickSortProcess1(arr,L,index - 1);
    quickSortProcess1(arr,index + 1, R);
    
}
void quickSort1(int *arr,int n){
    if(arr==NULL){
        return;
    }
    quickSortProcess1(arr,0,n-1);
}
int* separate2(int* arr,int L,int R){
    int less = -1;
    int more = R;
    int i = 0;
    while(i < more){
        if(arr[i] < arr[R]){
            swap(arr,i,++less);
           ++i;
        }else if(arr[i]==arr[R]){
            ++i;
        }else{
            swap(arr,i,--more);
        }
    }
    swap(arr,R,more);
    int *res = new int[2];
    res[0] = less+1;
    res[1] = more;
    return res;
}

void quickSortProcess2(int* arr , int L,int R){
    if(L >= R)return;
    int *res = separate2(arr,L,R);
    quickSortProcess2(arr,L,res[0] - 1);
    quickSortProcess2(arr,res[1] + 1,R);
    delete[] res;
}
void quickSort2(int *arr , int n){
    if(arr == NULL)return;
    quickSortProcess2(arr, 0 ,n - 1);
}






int main(){
    int arr[10] = {1,-1,5,2,5,8,343,2,12,200};
    printArr(arr,10);
    quickSort2(arr,10);

    printArr(arr,10); 
}