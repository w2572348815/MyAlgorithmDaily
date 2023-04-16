#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

const int N = 1e5 + 10;
int e[N] , h[N] , ne[N] , idx , w[N] , dist[N] , cnt[N];
int n,m;
bool st[N];
void add(int a, int b , int c){
	w[idx] = c , e[idx] = b , ne[idx] = h[a] , h[a] = idx++;
}
bool spfa(){
	queue<int > q;
	q.push(1);
	while(q.size()){
		int t = q.front();
		q.pop();
		st[t] = false;
		for(int i = h[t] ; i != -1 ; i = ne[i]){
			int j = e[i];
			if(dist[j] > dist[t] + w[i]){
				dist[j] = dist[t] + w[i];
				cnt[j] = cnt[t] + 1;
				if(cnt[j] == n)return true;
				q.push(j);
				st[j] = true;
			}
		}
	}
	return false;
}
int main(){
	memset(h , -1 , sizeof h);
	memset(dist , 0x3f , sizeof dist);
	dist[1] = 0;
	cin >> n >> m;
	for(int i = 0 ; i < m ; i ++ ){
		int a ,b,c;
		cin >> a>> b>>c;
		add(a,b,c);
	}

	if(spfa())cout << "yes";
	else cout << "no";
	return 0;
}
