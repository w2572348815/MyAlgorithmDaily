#include<iostream>

using namespace std;

typedef long long LL;

int main(){
	LL a , b , n;
	cin >> a >> b >> n;
	LL e[7] = {a,a,a,a,a,b,b};
	LL sum = 5 * a + 2 * b;
	LL res = n / sum * 7;
	n = n % sum;
	for(int i = 0 ; n > 0 ; i ++ ){
		n -= e[i];
		res++;
	}
	cout <<res;
	return 0;
}
