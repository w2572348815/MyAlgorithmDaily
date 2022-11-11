/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-10-25 19:39:44
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-11-10 14:07:01
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
    struct node* l;
    struct node* r;
} ;

typedef node* tree;
void zhongPr(tree t){
    if(t == NULL)return ;
    zhongPr(t->l);
    printf("%c",t->data);
    zhongPr(t->r);
}
tree creat(char ch[200]){
    if(ch[0]=='\0')return NULL;
    tree stack[2000];
    int top = -1;
    tree head = (tree)malloc(sizeof(node));
    head->data = ch[0];
    stack[0] = head;
    head->l = NULL;
    head->r = NULL;
    int j = 1;
    char temp;
    int k = 0;
    tree t = NULL;
    while( ch[j] != '\0'){
        if(ch[j] == '('){
            k = 1;
            
            top++;
            j++;
            continue;
        }else if(ch[j] == ','){
            k = 2;
            j++;
            continue;
        }else if(ch[j] == ')'){
            top--;
            j++;
            continue;
        }else{
            if(k == 1){
                tree m = (tree)malloc(sizeof(node));
                m->data = ch[j];
                m->l = NULL;
                m->r = NULL;
               tree t = stack[top];
                t->l = m;
                
                stack[top + 1] = m;
                zhongPr(head);
                puts("");
            }
            if(k == 2){
                tree m = (tree)malloc(sizeof(node));
                m->data = ch[j];
                m->l = NULL;
                m->r = NULL;
                tree t = stack[top];
                t->r = m;
                stack[top+1] = m;
                zhongPr(head);
                puts("");
            }
            j++;
        }

    
    }
   
    return head;
}


int main(){
    char ch[200];
    cin>>ch;
    tree t = creat(ch);
    zhongPr(t);
}