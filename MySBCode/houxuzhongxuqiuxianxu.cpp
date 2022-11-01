/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-10-25 18:32:31
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-10-26 19:09:55
 * @FilePath: \MyAlgorithmDaily\MySBCode\PTA1025.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>
using namespace std;
struct node{
    char data;
    node* left;
    node* right;
};
node* creat(int *houxu,int i,int j,int *zhongxu,int k,int m){
    if(i>j)return NULL;
    node* n = new node;
    n->data = houxu[j];
    n->left = NULL;
    n->right = NULL;
    if(i==j)return n;
    int e;
    for( e = k;e <= m;e++)if(zhongxu[e]==houxu[j])break;
    n->left = creat(houxu,i,e-k + i-1,zhongxu,k, e-1);
    n->right = creat(houxu,e-k+i,j-1,zhongxu,e+1,m);
    return n;
}
void pr(node* tree){
    if(tree == NULL)return;
    printf(" %d",tree->data);
    pr(tree->left);
    pr(tree->right);
}
int main(){
    int n;
    int houxu[100],zhongxu[100];
    cin>>n;
    for(int i = 0 ; i < n;i ++)scanf("%d",&houxu[i]);
    for(int i = 0; i < n; i++)scanf("%d",&zhongxu[i]);
    node* e = creat(houxu,0,n-1,zhongxu,0,n-1);
    cout<<"Preorder:";
    pr(e);
}