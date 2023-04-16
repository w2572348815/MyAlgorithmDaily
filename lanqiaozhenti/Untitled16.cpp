#include<iostream>
#include<queue>
using namespace std;

const int N = 2e5 + 10;
int v[N];
int n , m;
typedef pair<int,int> PII;
priority_queue<PII,vector<PII>,greater<PII>> heap[N];
int main(){
	cin >> n >> m;
	for(int i = 0 ; i < n ; i ++ )scanf("%d",&v[i]);
	while(m--){
		int a , b , c , d;
		scanf("%d %d %d %d",&a,&b,&c,&d);
		while(heap[b].size() && heap[b].top().first <= a){
			PII e = heap[b].top();
			heap[b].pop();
			v[b] += e.second;
		}
		if(d <= v[b]){
			heap[b].push({a + c,d});
			v[b] -= d;
			printf("%d\n",v[b]);
		}else {
			printf("-1\n");
		}
	}
	
}
