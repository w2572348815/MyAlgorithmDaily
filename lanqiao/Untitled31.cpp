#include<iostream>
#include<cstring>

using namespace std;

const int N = 510;
int dist[N] , g[N][N];
int n , m;
bool st[N];
int prim(){
	int res = 0;
	memset(dist , 0x3f , sizeof dist);
	for(int i = 0 ; i < n ;  i ++ ){
		int t = -1;
		for(int j = 1 ; j <= n ; j ++ ){
			if(!st[j] && (t == -1 || dist[t] > dist[j]))t = j;
		}
		if(i && dist[t] >= 0x3f3f3f3f / 2)return -1;
		st[t] = true;
		if(i)res += dist[t];
		for(int j = 1 ; j <= n ; j ++ ){
			dist[j] = min(dist[j] , g[t][j]);
		}
	}
	return res;
	
}
int main(){
	cin >> n >> m;
	memset(g , 0x3f ,  sizeof g);
	
	for(int i = 0 ; i < m ; i ++ ){
		int a , b , c;
		cin >> a >> b >> c;
		g[a][b] = g[b][a] = min(g[a][b] , c);
	}	
	cout << prim();
	return 0;
}

