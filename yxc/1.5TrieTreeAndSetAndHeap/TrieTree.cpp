#include<iostream>
using namespace std;

const int N = 100010;
int n;
int son[N][26], idx,cnt[N];
char ch[N];
void insert(){
    int p = 0;
    for(int i = 0;ch[i];i++){
        int u = ch[i] - 'a';
        if(!son[p][u])son[p][u] = ++idx;
        p = son[p][u];
    }
    cnt[p]++;
}
