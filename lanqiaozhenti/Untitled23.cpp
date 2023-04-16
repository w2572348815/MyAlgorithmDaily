#include<iostream>

using namespace std;
typedef long long LL;
int n;
LL C(int a,int b){
	LL res = 1;
	for(int i = 0 ; i < b ; i ++ ){
		res *= a - i;
		res /= i + 1;
	}
	return res;
}

bool check(int k){
	int l = 2 * k , r = n;
	while(l < r){
		int mid = l + r + 1>> 1;
		if(C(mid,k) > n){
			r = mid - 1;
		}else{
			l = mid;
		}
	}
	if(C(l , k) == n){
		int x = (1 + l) * l / 2 + k + 1;
		cout << x;
		return true;
	}
	return false;
}
int main(){
	cin >> n;
	for(int i = 16 ; ; i --){
		if(check(i))break;
	}
	return 0;
}
