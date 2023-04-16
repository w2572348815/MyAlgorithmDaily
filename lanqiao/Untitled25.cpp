#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

const int N = 1e5 + 10;
int w[N] , h[N] , ne[N], e[N] , idx , dist[N];
int n , m;
typedef pair<int , int> PII;

void add(int a , int b , int c){
	w[idx] = c , e[idx] = b, ne[idx] = h[a] , h[a] = idx++;
}

int dijkstra(){
	priority_queue<PII , vector<PII> , greater<PII>> heap;
	heap.push({0 ,1});
	while(heap.size()){
		PII t = heap.top();
		heap.pop();
		int dian = t.second , jvli = t.first;
		for(int i = h[dian] ; i != -1 ; i = ne[i] ){
			int j = e[i];
			if(dist[j] > jvli + w[i]){
				dist[j] = jvli + w[i];
				heap.push({dist[j] , j});
			}
		}
	}
	if(dist[n] == 0x3f3f3f3f)return -1;
	return dist[n];
}

int main(){
	cin >> n >> m;
	memset(h , -1 , sizeof h);
	memset(dist , 0x3f , sizeof dist);
	dist[1] = 0;
	for(int i = 0 ; i < m; i++ ){
		int a, b , c;
		cin >> a >> b >> c;
		add(a , b , c);
	}	
	cout << dijkstra();
	return 0;
}
