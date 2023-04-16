#include<iostream>

using namespace std;

int main(){
	int n;
	cin >> n;
	for(int i = 0 ; i < n ; i ++ ){
		cout << max(2*i ,2 *(n - i - 1)) << ' ';
	}
	return 0;
}
