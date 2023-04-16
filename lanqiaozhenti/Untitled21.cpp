#include<iostream>

using namespace std;
typedef long long LL;

int main(){
	LL n;
	cin >> n;
	n = n / 1000;
	n = n % 86400;
	int h = n / 3600;
	n %= 3600;
	int m = n / 60;
	int c = n % 60;
	printf("%02d:%02d:%02d",h,m,c);
	return 0;
}
