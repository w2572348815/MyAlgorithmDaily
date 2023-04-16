#include<iostream>

using namespace std;

const int N = 1e6 + 10;
int n , k;
int a[N] , q[N];
int hh , tt;
int main(){
	cin >> n >> k;
	hh = 0 , tt = -1;
	for(int i = 0 ; i < n ; i ++ )cin >> a[i];
	for(int i = 0 ; i < n ; i ++ ){
		if(hh <= tt && i - k + 1 > q[hh])hh++;
		while(hh <= tt && a[i] >= a[q[tt]])tt--;
		q[++tt] = i;
		if(i >= k - 1)cout << a[q[hh]] << endl;
	}
	return 0;
}
