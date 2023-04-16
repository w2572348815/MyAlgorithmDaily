#include<iostream>
#include<cstring>

using namespace std;

const int N = 1010;
int n , m;
int h[N] ,e[N] , ne[N],idx,r[N],c[N];
int q[N];
void add(int a, int b){
	c[a] ++ , r[b]++;
	e[idx] = b , ne[idx] = h[a] , h[a] = idx++;
}
void topsort(){
	int hh = 0 , tt = -1;
	for(int i = 1 ; i <= n ; i ++ ) if(!r[i])q[++tt] = i;
	while(hh <= tt){
		int t = q[hh++];
		for(int i = h[t] ; i != -1 ; i = ne[i]){
			int j = e[i];
			r[j] --;
			if(!r[j])q[++tt] = j; 
		}
	}
	if(tt == n - 1){
		for(int i = 0 ; i < n ; i ++ )cout << q[i];
		
	}else cout << "-1";
}
int main(){
	cin >> n >> m;
	memset(h , -1 , sizeof h);
	while(m--){
		int a , b;
		cin >> a >> b;
		add(a , b);
	}
	topsort();
	return 0;
}

