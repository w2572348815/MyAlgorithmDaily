#include<iostream>
#include<algorithm>

using namespace std;

const int N = 2e5 + 10;
int n ,m;
struct e{
	int a , b , c;
	bool operator<(const e &a) const{
		return c < a.c;
	} 
}edge[N];
int f[N];
int find(int x){
	if(f[x] != x)f[x] = find(f[x]);
	return f[x];
}
int kruskal(){
	int res = 0;
	for(int i = 0 ; i < m ; i ++ ){
		int a = edge[i].a , b = edge[i].b , c = edge[i].c;
		a = find(a) , b = find(b);
		if(a != b){
			f[a] = b;
			res += c;
		}
	}
	int w = find(1);
	for(int i = 1 ; i <= n ; i++ )if(find(i) != w)return -1;
	return res;
}

int main(){
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++ )f[i] = i;
	for(int i = 0 ; i < m ; i ++ ){
		int a , b , c;
		cin >> a >> b >> c;
		edge[i] = {a , b , c};
	}
	sort(edge , edge + m);
	cout << kruskal();
	return 0;
}
