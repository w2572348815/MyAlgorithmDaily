#include<iostream>
#include<cstring>

using namespace std;

const int N = 1e5 + 10;

int n;
int h[N] , e[N] , ne[N] , idx;
int res;
bool st[N];
void add(int a ,int b){
	e[idx] = b , ne[idx] = h[a] ,h[a] = idx ++;
}
int dfs(int u){
	int ans = 1;
	st[u] =true;
	int ma = 0;
	for(int i = h[u] ; ne[i] != -1 ; i = ne[i] ){
		
		int j = e[i];
		if(st[j])continue;
		int k = dfs(j);
		ans += k;
		ma = max(ma , k);
	}
	ma = max(ma , n - ans);
	res = min(res , ma);
	return ans;
}
int main(){
	cin >> n;
	memset(h , -1 , sizeof h);
	for(int i = 0 ; i < n - 1 ; i ++ ){
		int a , b;
		cin >> a >> b;
		add(a ,b);
		add(b ,a);
	}
	res = n;
	dfs(1);
	cout << res;
	return 0;
}
