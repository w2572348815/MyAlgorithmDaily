#include<iostream>

using namespace std;

int n;

int main(){
	int res = 0;
	cin >> n;
	while(n)n -= (-n)&n , res ++;
	cout << res;
	return 0;
}
