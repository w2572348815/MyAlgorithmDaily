#include<iostream>
#include<cstring>

using namespace std;

const int N = 510 , M = 1e5 + 10;
int h[N],ne[M],e[M],idx;
int n1,n2,m;
int res;
int match[N];
bool st[N];
void add(int a , int b){
	e[idx] = b , ne[idx] = h[a] , h[a] = idx++;
}
bool find(int u){
	for(int i = h[u] ; i != -1 ; i = ne[i]){
		int j = e[i]; 
		if(!st[j]){
			st[j] = true;
			if(match[j] == 0){
				match[j] = u;
				return true;
			}else if(find(match[j])){
				match[j] = u;
				return true;
			}
		}
	}
	return false;
}
int main(){
	cin >> n1 >> n2 >> m;
	memset(h , -1 , sizeof h);
	for(int i = 0 ; i < m ; i ++ ){
		int a , b;
		cin >> a >> b;
		add(a , b);
	}
	
	for(int i = 1 ; i <= n1 ;  i++ ){
		memset(st,false ,sizeof st);
		if(find(i)){
			res++;
		}
	} 
	cout << res;	
	return 0;
}
