#include<iostream>

using namespace std;
typedef long long LL;
int main(){
	LL n;
	scanf("%lld",&n);
	LL res = 1;
	for(int i = 2 ; i <= n / i ; i ++ ){
		if(n % i == 0){
			int cnt = 0;
			while(n % i == 0){
				n /= i;
				cnt ++;
			}
			if(cnt%2)res *= i;
		}
	}
	if(n > 1)res *= n;
	cout << res;
	return 0; 
}
