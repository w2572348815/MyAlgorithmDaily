/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-11-01 20:25:27
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-11-01 21:38:17
 * @FilePath: \MyAlgorithmDaily\yxc\1.5TrieTreeAndSetAndHeap\MySet2.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>
using namespace std;
const int N = 100010;
int p[N],s[N];
int find(int x){
    if(p[x] != x){
        p[x] = find(p[x]);
    }
    return p[x];
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i++){
        p[i] = i;
        s[i] = 1;
    }
    while(m--){
        char op[5];
        int a,b;
        scanf("%s",op);
        if(op[0] == 'C'){
            cin>>a>>b;
            if(find(a) == find(b))continue;
            s[find(a)] += s[find(b)];
            p[find(b)] = find(a); 
        }
        else if(op[1] == '1'){
            cin>>a>>b;
            if(find(a) == find(b))cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }else{
            cin>>a;
            printf("%d\n",s[find(a)]);
        }
    }
    return 0;
}