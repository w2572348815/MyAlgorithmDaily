#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 5010 ,mod = 1e9 + 7;
typedef long long LL;
char str[5010];
LL f[N][N];
int n;
int calc(){
	f[0][0] = 1;
	for(int i = 1 ; i <= n ; i ++ )
	{
		if(str[i] == '(')
		for(int j = 0 ; j <= n ; j ++ )
			f[i][j] = f[i - 1][j - 1];
		else 
		{
			f[i][0] = (f[i - 1][0] + f[i - 1][1]) % mod;
			for(int j = 1; j <= n ; j ++ )
			{
				f[i][j] = (f[i - 1][j + 1] + f[i][j - 1]) % mod;
			}
		}
	}
	for(int i = 0 ; i <= n ; i ++ )
		if(f[n][i])
		return f[n][i];
	return -1;
}
int main(){
	scanf("%s",str + 1);
	n = strlen(str + 1);
	int a = calc();
	reverse(str + 1 , str + 1 + n);
	for(int i = 1 ; i <= n ; i ++ )
		if(str[i] == '(')str[i] = ')';
		else str[i] = '(';
	int b = calc();
	printf("%lld",(LL) a * b % mod);
	return 0;
}
