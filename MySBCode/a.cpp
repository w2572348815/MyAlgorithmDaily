/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-10-25 19:39:44
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-11-09 14:47:27
 * @FilePath: \MyAlgorithmDaily\MySBCode\a.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>
#include<stdlib.h>
using namespace std;
struct node{
    char data;
    struct node* left;
    struct node* right;
};
node* creat(char ch[200]){
    int j = 1;
    char temp;
    node* head;
    node* stack[200];
    int top = -1;
    if(ch[0] == '\0')return NULL;
    else {
        head = (node*)malloc(sizeof(node));
        head->data = ch[0];
        head->left = head->right = NULL;
        stack[++top] = head;
    }

    int k = 0;
    node * p = NULL;
    while(temp = ch[j++]!='\0'){
        if(temp == '('){
            k = 1;
            p = stack[++top];
            break;
        }else if(temp == ','){
            k = 2;
            break;
        }else if(temp == ')'){

        }
    }



    return head;
}

int main(){

}
