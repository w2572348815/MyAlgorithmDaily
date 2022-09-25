/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2022-09-18 13:38:11
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2022-09-21 17:57:54
 * @FilePath: \c++\test.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* setList(int n){
    struct node *head,*tail,*p;int m;
    for(int i=0;i<n;i++){
        p = (struct node*)malloc(sizeof(struct node));
        scanf("%d",&(p->data));
        if(i==0){
            head = p;
            tail = p;
        }else{
            p->next = head;
            head = p;
        }
        
    }
    tail->next = NULL;
    return head;
}
void print(struct node *head){
    while(head!=NULL&&head->next!=NULL){
        printf("%d ",head->data);
        head = head->next;
    }
    printf("%d\n",head->data);
}
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        struct node* head = setList(n);
        print(head);
    }
}