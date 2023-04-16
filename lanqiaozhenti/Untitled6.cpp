#include<iostream>

using namespace std;

const int N = 1e7 + 10 , mod = 1e9 + 7;
int f[N][4];
int d[4][4] = {
	{1,1,1,1},
	{0,0,1,1},
	{0,1,0,1},
	{1,0,0,0}
};
int main(){
	int n;
	cin >> n;
	f[0][0] = 1;
	for(int i = 1 ; i <= n ; i ++ ){
		for(int j = 0 ; j < 4 ; j ++ )
			for(int k = 0 ; k < 4 ; k ++ ){
				if(d[j][k])f[i][k] = (f[i - 1][j] + f[i][k]) % mod;
			}
	}
	cout << f[n][0];
	return 0;
}
