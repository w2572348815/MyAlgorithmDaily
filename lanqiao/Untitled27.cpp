#include<iostream>
#include<cstring>


using namespace std;

struct {
	int a , b , c;
}edge[100];

int n , m , k;
int dist[100] , back[100];
int bellman_ford(){
	memset(dist , 0x3f , sizeof dist);
	dist[1] = 0;
	for(int i = 0 ; i < k ; i ++ ){
		memcpy(back,dist,sizeof dist );
		for(int j = 0 ; j < m ; j ++ ){
			int a = edge[j].a , b = edge[j].b , c = edge[j].c;
			dist[b] = min(back[b] , back[a] + c);
		}
	}
	if(dist[n] > 0x3f3f3f3f / 2)return -1;
	return dist[n];
}
int main(){
	cin >> n >> m >> k;
	for(int i = 0 ; i < m ; i ++ ){
		int a , b , c;
		cin >> a >> b >> c;
		edge[i] = {a , b , c};
	}
	
	cout << bellman_ford();
	return 0;
}
