#include<iostream>
#include<cstring>

using namespace std;

const int N = 510;

int d[N][N];
int n,m;
bool st[N];
int dist[N];
void dijkstra(){
	memset(dist , 0x3f , sizeof dist);
	dist[1] = 0;
	for(int i = 0 ; i < n ; i ++ ){
		int t = -1;
		for(int j = 1 ; j <= n ; j ++ )
			if(!st[j] && (t == -1 || dist[j] < dist[t]))t = j; 
			st[t] = true;
		for(int j = 1 ; j <= n ; j ++ ){
			dist[j] = min(dist[j] , dist[t] + d[t][j]);
		}
	}
}
int main(){
	cin >> n >> m;
	for(int i = 0 ; i < m ; i ++ ){
		int a , b , c;
		cin >> a >> b >> c;
		d[a][b] = c;
	}
	dijkstra();
	cout << dist[n];
	return 0;
}
