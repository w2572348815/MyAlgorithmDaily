#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;

const int N = 1e5 + 10;
int n , m;
int h[N] , e[N] , ne[N] , idx;
int q[N] , d[N];
bool st[N];
void add(int a , int b){
	e[idx] = b , ne[idx] = h[a] , h[a] = idx ++;
}
int bfs(){
	memset(d,0x3f,sizeof d);
	d[1] = 0;
	q[0] = 1;
	st[0] = true;
	int hh = 0 , tt = 0;
	while(hh <= tt){
		int t = q[hh];
		hh++;
		for(int i = h[t] ; i != -1 ; i = ne[i] ){
			int j = e[i];
			if(st[j])continue;
			if(d[j] > d[t] + 1)d[j] = d[t] + 1;
			q[++tt] = j;
		}
	}
	return d[n];
}
int main(){
	cin >> n >> m;
	memset(h , -1 , sizeof h);
	int a ,b;
	while(m--){
		cin >> a >> b;
		if(a != b)add(a,b);
	}
	cout << bfs();
	return 0;
}
