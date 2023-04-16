#include<iostream>
#include<cmath>

using namespace std;
typedef long long LL;
const int N = 2e5 + 10 , M = 10;
LL f[N][M];
int n;
int main(){
	cin >> n;
	LL res = 0;
	int m = -1;
	for(int i = 0 ; i < n ; i ++ ){
		LL x;
		cin >> x;
		LL stk[10];
		int top = 0;
		while(x > 1){
			stk[++top] = x;
			x = sqrtl(x / 2 + 1);
		}
		res += top;
		m = max(top , m);
		int e = top;
		for(int j = 0 ; j < e ; j ++ ){
			f[i][j] = stk[top--];
		}
	}
	for(int i = m - 1 ; i >= 0 ; i --){
		for(int j = 1 ; j < n ; j ++ ){
			if(f[j][i] && f[j][i] == f[j - 1][i]){
				res--;
			}
		}
	}
	cout << res;
	return 0;
}


