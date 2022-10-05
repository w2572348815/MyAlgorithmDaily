/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-09-27 19:27:55
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-09-28 13:52:35
 * @FilePath: \MyAlgorithmDaily\LinkList.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>
using namespace std;
template<class T>
struct Node{
    T data;
    Node<T>* next;
    Node<T>(Node<T>* p = nullptr){
        next = p;
    }
    Node<T>(const T& val,Node<T>*p = nullptr){
        data = val;
        next = p;
    }
};
template<class T>
class LinkedList{
    private:
    Node<T> *head;
    Node<T> *tail;
    int length;
    public:
    //重载原始的构造函数
    LinkedList(){
        head = new Node<T>;
        tail = head;
        length = 0;
    }
    //带参构造函数
    LinkedList(const T& data){
        head = new Node<T>;
        head->next = new Node<T>(data);
        tail = head->next;
        length = 1;
    }
    //返回头节点
    Node<T>* getHead(){
        return head;
    }
    //拷贝构造
    LinkedList(const LinkedList<T>& l){
        T data;
        Node<T>* otherHead = l.getHead();
        Node<T>* thisHead = head = new Node<T>;
        while(otherHead->next){
        data = ohterHead->next->data;
        thisHead->next = new Node<T>(value);
        thisHead = thisHead->next;
        length++;
        otherHead = otherHead->next; 
        }
    }
    //将链表清空只留头节点
    void makeEmpty(){
        while(head->next){
            q = head->next;
            head->next = q->next;
            delete q;
        }
        length = 0;
    }
    //析构函数
    ~LinkedList(){
        makeEmpty();
    }
    //返回链表长度
    int length(){
        return length;
    }
    //在表中搜索含数据x的节点，搜索成功时函数返回该节点地址；否则返回NULL值。
    Node<T>* search(const T& x){
        Node<T>* h = head,res = nullptr;
        while(h->next){
            if(h->next->val==x){
                res = h->next;
            }
            h = h->next;
        }
    }
    return res;
};