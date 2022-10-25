/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-10-25 18:32:31
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-10-25 19:09:37
 * @FilePath: \MyAlgorithmDaily\MySBCode\PTA1025.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node * left;
    struct node * right;
}Node,*Tree;
int x = 1,z = 1,h = 1;
int * creat(int n){
    int * a = (int *)malloc(sizeof(int)*(n + 1 ));
    a[1] = 1;
    int j,left,right;
    for(int i  = 1; i <= n ;i++){
        scanf("%d%d%d",&j,&left,&right);
        if(left!= -1)a[2*j] = left;
        if(right!= -1)a[2*j + 1] = right;
    }
    return a;
}
void xPrint(int *a,int i,int n){
    if(i > n)return;
    if(x == 1)printf("%d",a[i]),x++;
    else printf(" %d",a[i]);
    xPrint(a,2*i,n);
    xPrint(a,2*i+1,n);
}
void zPrint(int *a,int i,int n){
    if(i > n)return;
    
    zPrint(a,2*i,n);
    if(z == 1)printf("%d",a[i]),z++;
    else printf(" %d",a[i]);
    zPrint(a,2*i+1,n);
}
void hPrint(int *a,int i,int n){
    if(i > n)return;
    
    hPrint(a,2*i,n);
    hPrint(a,2*i+1,n);
    if(h == 1)printf("%d",a[i]),h++;
    else printf(" %d",a[i]);
}
Tree change(int *a,int i,int n){
    if(i > n)return NULL;
    Tree t = (Tree)malloc(sizeof(Node));
    t->data = a[i];
    t->left = change(a,2*i,n);
    t->right = change(a,2*i +1,n);
    return t;
}
void xianPrint(Tree t){
    if(t == NULL)return;
    printf("%d ",t->data);
    xianPrint(t->left);
    xianPrint(t->right);
}
int main(){
    int n ;
    scanf("%d",&n);
    int *a = creat(n);
    // for(int i = 1; i <= n;i++){
    //     printf("%d ",a[i]);
    // }
    xPrint(a,1,n);
    puts("");
    zPrint(a,1,n);
    puts("");
    hPrint(a,1,n);
    puts("");
    Tree t = change(a,1,n);
    xianPrint(t);
    return 0;
}