/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-11-06 14:17:19
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-11-06 15:08:35
 * @FilePath: \MyAlgorithmDaily\yxc\week4 07 08\8num.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<unordered_map>

using namespace std;

typedef pair<string,int > PSI;
char st[9];
int bfs(string start){
    queue<string> q;
    unordered_map<string,int> m;
    q.push(start);
    m[start] = 0;
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    while(q.size()){
        string s = q.front();
        if(s == "12345678#"){
        return m[s];
        }
        
        q.pop();
        int k = s.find('#');
        int x = k / 3, y = k % 3;
        int distance = m[s];
        for(int i = 0;i < 4;i++){
            int a = x + dx[i], b = y + dy[i];
            if(a >= 0 && a < 3 && b >= 0 && b < 3){
                swap(s[k],s[a*3+b]);

                if(!m.count(s)){
                m[s] = distance + 1;
                q.push(s);

                }
             
                swap(s[k],s[a*3+ b]);
            }
        }

    }
    return -1;
}

int main(){
    string start;
    for(int i = 0;i < 9;i++){
        cin>>st[i];
        start += st[i];
    }
    int x = bfs(start);
    cout<<x;
    return 0;
}