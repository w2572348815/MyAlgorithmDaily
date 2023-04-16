#include<iostream>

using namespace std;

const int N = 1e5 + 10 , mod = 1e9 + 7;

int main(){
	int n;
	int ma , mb;
	cin >> n;
	cin >> ma;
	int a[N] , b[N];
	for(int i = ma - 1 ; i >= 0; i -- ){
		cin >> a[i];
	}
	cin >> mb;
	for(int i = mb - 1 ; i >= 0 ; i -- ){
		cin >> b[i];
	}
	int res = 0;
	for(int i = ma - 1 ; i >= 0 ; i --){
		res =res + a[i] - b[i] % mod;
		if(i)res =res * max(a[i - 1] + 1 , max(b[i - 1] + 1 , 2)) % mod;
	}
	cout << res;
	return 0;
	
}
