#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 1e5 + 10;

int h[N] , e[2*N] , ne[2*N] , idx;

void add(int a , int b){
	e[idx] = b , ne[idx] = h[a] , h[a] = idx++;
}
int color[N];

bool is_bin(int u , int col){
	if(color[u] == 3 - col)return false;
	if(color[u] == col)return true;
	color[u] = col;
	for(int i = h[u] ; i != -1 ; i = ne[i]){
		int j = e[i];

		if(!is_bin(j , 3 - col))return false;
		
	}
	return true;
}

int main(){
	int n , m;
	cin >> n >> m;
	memset(h , -1 , sizeof h);
	for(int i = 0 ; i < m ; i ++ ){
		int a , b;
		cin >> a >> b;
		if(a == b)continue;
		add(a , b);
		add(b , a);
	}
	for(int i = 1; i <= n ; i ++ ){
		if(!color[i]){
			if(!is_bin(i , 1)){
				cout << "NO";
				return 0;
			}		
		}
	}
	cout << "yes";
	return 0;
}
