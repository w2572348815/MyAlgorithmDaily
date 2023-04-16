#include<iostream>

using namespace std;

const int N = 1e5 + 10;
int a[N];
int n , m;
int c[N];
void insert(int e , int b , int r){
	c[e] += r , c[b + 1] -= r;
}
int main(){
	scanf("%d%d" , &n,&m);
	for(int i = 1 ; i <= n ; i ++ ){
		cin >> a[i];
		insert(i , i , a[i]);
	}
	for(int i = 0 ;i < m ; i ++ ){
		int l , r , c;
		scanf("%d%d%d",&l,&r,&c);
		insert(l , r , c);
	}
	for(int i = 1 ; i <= n ; i ++ )c[i] += c[i - 1];
	for(int i = 1 ; i <= n ; i ++ )cout << c[i] << ' ';
	return 0;
}
