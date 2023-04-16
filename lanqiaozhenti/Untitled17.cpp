#include<iostream>

using namespace std;

const int N = 7 , M = 110 , K = 21 , mod = 1e9 + 7;
int f[M][1 << N][1 << N][K];
int n , m , k;
int getx(int x){
	int res = 0;
	while(x){
		res ++;
		x -= x & -x;
	}
	return res;
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	f[0][0][0][0] = 1;
	for(int i = 1 ; i <= m ; i ++ )
		for(int a = 0 ; a < 1 << n ; a ++ )
			for(int b = 0 ; b < 1 << n ; b ++ )
			{
				if(a & (b << 2) || b & (a << 2))continue;
				for(int c = 0 ; c < 1 << n ; c ++ )
				{
					if(c & (b << 2) || b & (c << 2))continue;
					if(c & (a << 1) || a & (c << 1))continue;
					int num = getx(c);
					for(int d = num ; d <= k ; d++){
						f[i][b][c][d] = (f[i][b][c][d] + f[i - 1][a][b][d - num]) % mod;
					}
				}
			}
	int res = 0;
	for(int i = 0 ; i < 1 << n ; i ++ )
		for(int j = 0 ; j < 1 << n ; j ++ )
		res =(res + f[m][i][j][k]) % mod;
	cout << res;
	return 0;
				
}
