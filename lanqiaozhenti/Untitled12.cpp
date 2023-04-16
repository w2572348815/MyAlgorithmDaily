#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e7 + 10;
struct edge{
	int a , b , c;
	bool operator<(const edge& e){
		return c < e.c;
	}
}ed[N];
int p[2030];
int find(int x){
	if(p[x] != x)p[x] = find(p[x]);
	return p[x];
}
int main(){
	int idx = 0;
	for(int i = 1 ; i <= 2021 ; i ++ ){
		p[i] = i;
	}
	for(int i = 1 ; i <= 2021 ; i ++ )
		for(int j = 1 ; j < i ; j ++ )
		{
			int x = i , y = j , c = 0;
			while(x){
				int e = x % 10;
				int w = y % 10;
				if(e != w)c += e + w;
				x=x/10;
				y/=10;
			}

			if(c != 0)ed[idx++] = {i,j,c};
		}
	sort(ed , ed + idx);
	long long res = 0;
	for(int i = 0 ; i < idx ; i ++ ){
		int x = find(ed[i].a);
		int y = find(ed[i].b);
		if(x != y)p[x] = y , res += ed[i].c;
	}
	cout << res;
	return 0;
}
