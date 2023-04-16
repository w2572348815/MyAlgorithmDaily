#include<iostream>

const int N = 2e5 + 10 , M = N / 2;
using namespace std;

bool f[110][N];
int w[110];
int m;
int main(){
	int n;
	cin >> n;
	for(int i = 1 ; i <= n ; i ++ )cin >> w[i] , m += w[i];
	f[0][M] = true;
	for(int i = 1 ; i <= n ; i ++ )
		for(int j = -m ; j <= m ; j ++ )
		{
			f[i][j + M] = f[i - 1][j + M];
			if(j + w[i] <= m)f[i][j + M] |= f[i - 1][j + M + w[i]];
			if(j - w[i] >= -m)f[i][j + M] |= f[i - 1][j +M - w[i]];
		}
		int res = 0;
	for(int i = 1; i <= m ; i ++){
		if(f[n][i + M])res++;
	}
	cout << res;
	return 0;
}
