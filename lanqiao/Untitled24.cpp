#include<iostream>
#include<cstring>

using namespace std;

const int N = 510;
int d[N][N] , dist[N];
bool st[N];
int n ,m;

int dijkstra(){
	memset(dist , 0x3f , sizeof dist);
	dist[1] = 0;
	for(int i = 0 ; i < n ; i ++ ){
		int t = -1;
		for(int j =1 ; j <= n; j ++ ){
			if(!st[j] && (t == -1 || dist[t] > dist[j])) t = j;
		}
		st[t] = true;
		for(int j = 1 ; j <= n ; j ++ ){
			dist[j] = min(dist[j] , dist[t] + d[t][j]);
		}
	}
	if(dist[n] == 0x3f3f3f3f)return -1;
	return dist[n];
}
int main(){
	cin >> n >> m;
	for(int i = 0 ; i < m ; i ++ ){
		int a , b , c;
		cin >> a >> b >> c;
		d[a][b] = c;
	}
	cout << dijkstra();
	return 0;
}
