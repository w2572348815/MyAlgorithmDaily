#include<iostream>

using namespace std;

int a[1010];
int n;

int main(){
	cin >> n;
	for(int i = 1 ; i <= n ; i ++ ){
		cin >> a[i];
		a[i] += a[i - 1];
		cout << a[i];
	
	}	
	return 0;
}
