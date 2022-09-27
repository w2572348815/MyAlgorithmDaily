/*
 * @Author: 武家豪&&2572348815@qq.com
 * @Date: 2022-09-25 09:08:59
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-09-27 14:44:07
 * @FilePath: \MyAlgorithmDaily\sort.cpp
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
    int less = L-1;
    int more = R;
    int i = L;
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


int *separate3(int *arr,int L , int R){
    int less = L - 1;
    int more = R;
    int i = L;
   int random = (rand() % (R - L + 1)) + L;
   swap(arr,random,R);
    while(i < more){
        if(arr[i] < arr[R]){
            swap(arr,i++,++less);
        }else if(arr[i] == arr[R]){
            ++i;
        }else{
            swap(arr,--more,i);
        }
    }
    swap(arr,R,more);
    int* a = new int[2];
    a[0] = less + 1;
    a[1] = more;
    return a;
}
void quickSortProcess3(int *arr,int L,int R){
    if(L >= R)return;
    int *a = separate3(arr,L,R);
    quickSortProcess3(arr,L,a[0] - 1);
    quickSortProcess3(arr,a[1] + 1, R);
}

void quickSort3(int* arr,int n){
    if(arr == NULL)return;
    quickSortProcess3(arr , 0 , n - 1);
}
void heapInsert(int *arr,int index){

    while(arr[index] > arr[(index - 1)/2]){
        swap(arr,index,(index - 1)/2);
        index = (index - 1)/2;
    }
}
void heapify(int *arr,int heapSize,int index){
    int left = 2*index + 1;
    while(left < heapSize){
        int largest = left + 1 < heapSize && arr[left + 1] > arr[left] ? left + 1 : left;
        largest = arr[index] >= arr[largest] ? index : largest;
        if(largest == index)break;
        swap(arr,index,largest);
        index = largest;
        left = 2*index + 1;  
    }
}
void heapSort1(int* arr,int n){
    if(arr == NULL || n < 2)return;
    for(int i = 0;i < n;i++){
        heapInsert(arr,i);
    }
    for(int i = n - 1;i >0;i--){
        swap(arr,i,0);
        heapify(arr,i,0);
    }
}
//优化部分常数,但不影响总体复杂度,下面第一个for循环是O(n),没修改前是O(n*logn)
void heapSort2(int* arr,int n){
    if(arr == NULL || n < 2)return;
    for(int i = n - 1;i >= 0 ;i--){
        heapify(arr,n,i);
    }
    for(int i = n - 1;i >0;i--){
        swap(arr,i,0);
        heapify(arr,i,0);
    }
}
//基数排序,只排正数
int maxBit(int *arr,int n){
    int max = arr[0];
    for(int i = 1;i < n;i++){
        if(max < arr[i])max = arr[i];
    }
    int count = 0;
    while(max){
        max /= 10;
        count++;
    }
    return count;
}
int getDight(int num,int n){
    for(int i = 1;i < n;i++){
        num /= 10;
    }
    return num%10;
}
void radixSort(int *arr,int n){
    if(arr == NULL || n < 2)return;
    int bits = maxBit(arr,n);
    int *help = new int[n];
    for(int i = 1;i <= bits;i++){
        int bucket[10] = {0};
        for(int j = 0;j < n;j++){
            bucket[getDight(arr[j],i)]++;
        }
        for(int j = 1;j < 10;j++){
            bucket[j] += bucket[j - 1];
         }
         for(int j = n - 1;j >= 0;j--){
            int num = getDight(arr[j],i);
            help[--bucket[num]] = arr[j]; 
         }
         for(int j = 0;j < n;j++){
            arr[j] = help[j];
         }
        
    }
    delete[] help;
}




int main(){
    int arr[10] = {1,1,5,2,5,8,343,2,12,200};
    printArr(arr,10);
    radixSort(arr,10);

    printArr(arr,10); 
}