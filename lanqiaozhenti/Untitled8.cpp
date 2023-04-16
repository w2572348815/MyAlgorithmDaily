#include<iostream>
#include<cstring>

using namespace std;
typedef long long LL;
const int N = 5e4 + 10 , M = 999997;
struct circle{
	int a , b , c;
}cir[N];
LL h[M];
bool st[M];
int id[M];
 
LL get_key(int a , int b){
	return a * 1000000001ll + b;
}
int find(int a , int b){
	LL x = get_key(a,b);
	int index = (x % M + M) % M;
	while(h[index] != -1 && h[index] != x){
		if(++index == M)index = 0;
	}
	return index;
}
int sqr(int x){
	return x*x;
}

void dfs(int a , int b , int c){
	st[find(a,b)] = true;
	for(int i = a - c ; i <= a + c ; i ++ )
		for(int j = b - c; j <= b + c ; j ++ )
			if(sqr(i - a) + sqr(j - b) <= sqr(c)){
				int x = find(i,j);
				if(id[x] && !st[x]){
					dfs(i,j,cir[id[x]].c);
				}
			}
}
int main(){
	int n , m;
	memset(h,-1,sizeof h);
	scanf("%d%d",&n,&m);
	for(int i = 1 ; i <= n ; i ++ ){
		int a , b , c;
		scanf("%d%d%d",&a,&b,&c);
		cir[i] = {a,b,c};
		int x = find(a,b);
		h[x] = get_key(a,b);
		if(!id[x] || cir[id[x]].c < c){
			id[x] = i;
		}
	}
	for(int e = 0 ; e < m ; e ++ ){
		int a , b , c;
		scanf("%d%d%d",&a,&b,&c);
		for(int i = a - c ; i <= a + c; i ++ )
			for(int j = b - c ; j <= b + c ; j ++ )
				if(sqr(i - a) + sqr(j - b) <= sqr(c)){
					int x = find(i,j);
					if(id[x] && !st[x]){
						dfs(i,j,cir[id[x]].c);
					}
				}
	}
	LL res = 0;
	for(int i = 1 ; i <= n ; i ++ )
	{
		int x = find(cir[i].a,cir[i].b);
		if(st[x])res++;
	}
	printf("%lld",res);
	return 0;
}
