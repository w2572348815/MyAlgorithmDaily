#include<iostream>
#include<vector>
typedef long long LL;
using namespace std;
LL n;
int main(){
	int res = 0;
	n = 2021041820210418;
	vector<LL> r;
	for(int i = 1 ; i <= n / i ; i ++ ){
		if(n % i == 0){
			r.push_back(i);
			if(n/i != i)r.push_back(n/i);
		}
	}
	for(auto a : r)
		for(auto b : r)
			for(auto c : r)
			if(a * b * c == n)res++;
			cout << res;
	return 0;
}
