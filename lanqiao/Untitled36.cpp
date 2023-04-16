#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>

using namespace std;
const int N = 1010;
int primes[N] , cnt;
bool st[N];

bool is_prime(int n){
	if(n == 1)return false;
	for(int i = 2 ; i <= n / i ; i ++ ){
		if(n % i == 0)return false;
	}
	return true;
}

void divide(int n){
	for(int i = 2 ; i <= n / i ; i ++ ){
		if(n % i == 0){
			int res = 0;
			while(n % i == 0){
				n /= i;
				res ++;
			}
			cout << i << ' ' << res << endl;
		}
		
	}
	if(n) cout << n << ' ' << '1';
	return;
	
}

void aishishaifa(int n){
	if(n == 1)return;
	for(int i = 2 ; i <= n ; i ++ ){
		if(!st[i]){
			primes[cnt++] = i;
			for(int j = i + i ; j <= n ; j += i){
				st[i] = true;
			}
		}
	}
	return ;
}

void xianshai(int n){
	if(n == 1)return ;
	for(int i = 2 ; i <= n ; i ++ ){
		if(!st[i]){
			primes[cnt++] = i;
		}
		for(int j = 0 ; primes[j] <= n / i; j ++ ){
			st[primes[j] * i] = true;
			if(i % primes[j] == 0)break;
		}
	}
	return ;
}

vector<int> get_div(int n){
	vector<int> res;
	for(int i = 1 ; i <= n / i ; i ++ ){
		if(n % i == 0){
			res.push_back(i);
			if(i != n / i)res.push_back(n / i);
		}
	}
	sort(res.begin(),res.end());
	return res;
}

int gcd(int a , int b){
	return b == 0 ? a : gcd(b,a%b);
}
int main(){
	return 0;
}


