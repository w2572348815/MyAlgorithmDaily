#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

const int N = 1e7 + 10;
bool st[2030];
int dist[2030];
int h[2030] , e[N] , ne[N] , w[N] , idx;

void add(int a, int b , int c){
	w[idx] = c , e[idx] = b , ne[idx] = h[a] , h[a] = idx ++;
}
int gcd(int a , int b){
	if(b!=0)return gcd(b,a%b);
	return a;
}
void spfa(){
	queue<int> heap;
	heap.push(1);
	st[1] = true;
	while(heap.size()){
		int x = heap.front();
		st[x] = false;
		heap.pop();
		for(int i = h[x] ; i != -1 ; i = ne[i]){
			int j = e[i];
			if(dist[j] > dist[x] + w[i]){
				dist[j] = dist[x] + w[i];
				heap.push(j);
				st[j] = true;
			}

		}
	}
}
int main(){
	memset(h,-1,sizeof h);
	memset(dist,0x3f,sizeof dist);
	dist[1] = 0;
	for(int i = 1 ; i <= 2021 ; i ++ )
		for(int j = 1 ; j <= 2021 ; j ++ )
		{
			if(abs(i - j) > 21)continue;
			int x = i * j / gcd(i,j);
			add(i,j,x);
			add(j,i,x);
		}
	spfa();
	cout << dist[2021];
	return 0;
}

