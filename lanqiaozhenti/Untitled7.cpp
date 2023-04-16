#include<iostream>
#include<cstring>

using namespace std;

const int N = 5e4 + 10 , M = 999997;
typedef long long LL;
struct circle{
	int a , b , c;
}cir[N];
LL h[M];
int id[M];
bool st[M];

LL get_key(int a , int b){
	return a * 1000000001ll + b;
}
int find(int a,int b){
	LL index = get_key(a,b);
	int x = (index % M + M) % M;
	while(h[x]!=-1 && h[x] != index){
		x++;
		if(x == M)x =0;
	}
	return x;
}
int sqr(int a){
	return a * a;
}
void dfs(int x ,int y , int r){
	st[find(x,y)] = true;
	for(int i = x - r ; i <= x + r ; i ++ )
		for(int j = y - r ; j <= y + r ; j ++ )
		if(sqr(i - x) + sqr(j - y) <= sqr(r)){
			int index = find(i,j);
			if(id[index] && !st[index]){
				dfs(i,j,cir[id[index]].c);
			}
		}
}
int main(){
	int n , m;
	cin >> n >> m;
	memset(h,-1,sizeof h);
	for(int i = 1 ; i <= n ; i ++ ){
		int a , b , c;
		scanf("%d%d%d",&a,&b,&c);
		cir[i] = {a,b,c};
		int x = find(a,b);
		if(h[x] == -1)h[x] = get_key(a,b);
		if(!id[x] || c > cir[id[x]].c){
			id[x] = i;
		}
	}
	for(int i = e ; e <= m ; e ++ ){
		int a,b,c;
		cin >> a >> b >> c;
		for(int i = a - c ; i <= a + c ; i ++ )
			for(int j = b - c ; j <= b + c ; j ++ )
				if(sqr(i - a) + sqr(j - b) <= sqr(c)){
					int x = find(i,j);
					if(id[x] && !st[x]){
						dfs(i,j,cir[id[x]].c);
					}
				}
	}
	LL res = 0;
	for(int i = 1 ; i <= n ; i ++ ){
		int x = find(cir[i].a,cir[i].b);
		if(st[x])res++;
	}
	cout << res;
	return 0;
}
