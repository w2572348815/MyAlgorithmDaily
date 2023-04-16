#include<iostream>

using namespace std;

int main(){
	double a;
	cin >> a;
	double l = 0 , r = 10000;
	while(r - l > 1e-8){
		double mid = (l + r)/2;
		if(mid * mid >= a)r = mid;
		else l = mid;
	}
	printf("%f",l);
	return 0;
}
