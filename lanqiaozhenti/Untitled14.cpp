#include<iostream>

using namespace std;

int main(){
	int n;
	cin >> n;
	int res = 0;
	double e = n / 2.0;
	for(int i = 1 ;i < n ; i ++ ){
		if(i * i % n < e)res++;
	}
	cout << res;
	return 0;
}
