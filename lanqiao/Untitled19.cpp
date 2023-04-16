#include<iostream>

using namespace std;

const int N = 1e5 + 10;
int a[N] , b[N];
int n,m,c;

int main(){
	cin >> n >> m >> c;
	for(int i = 0 ; i < n ; i ++ )cin >> a[i];
	for(int i = 0 ; i < m ; i ++ )cin >> b[i];
	for(int i = 0 , j = m - 1 ; i < n ; i ++ ){
		while(a[i] + b[j] > c)j--;
		 if(a[i] + b[j] == c)
			cout << i << ' ' << j;
		
		
	}
	return 0;
}
