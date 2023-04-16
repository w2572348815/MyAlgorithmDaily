#include<iostream>

using namespace std;

const int N = 110 , mod = 1e9 + 7;
int f[N][N][N];

int main(){
	f[0][0][2] = 1;
	int n , m;
	scanf("%d%d",&n,&m);
	for(int i = 0 ; i <= n ; i ++ )
		for(int j = 0 ; j <= m ; j ++ )
			for(int k = 0 ; k <= m ; k ++ )
			{
				if(k%2 == 0 && i > 0)f[i][j][k] =(f[i][j][k] +  f[i - 1][j][k/2]) % mod;
				if(j > 0)f[i][j][k] =(f[i][j][k] +  f[i][j - 1][k + 1]) % mod;
			}
			cout << f[n][m - 1][1];
			return 0;
}

