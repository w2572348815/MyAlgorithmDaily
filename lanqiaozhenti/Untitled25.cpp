#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 5010 , mod = 1e9 + 7;
int f[N][N];
char str[N];
int len;
int calc(){
	memset(f,0,sizeof f);
	f[0][0] = 1;
	for(int i = 1 ; i <= len ; i ++ )
	{
		if(str[i] == '('){
			for(int j = 1 ; j <= len ; j ++ )
				f[i][j] = f[i - 1][j - 1];
		}
		else{
			f[i][0] = (f[i - 1][0] + f[i - 1][1]) % mod;
			for(int j = 1 ; j <= len ; j ++ )
				f[i][j] = (f[i - 1][j + 1] + f[i][j - 1]) % mod;
		}
	}
	for(int i = 0 ; i <= len ; i ++ )
		if(f[len][i])
			return f[len][i];
	return -1;
}
int main(){
	scanf("%s",str + 1);
	len = strlen(str + 1);
	int x = calc();
	reverse(str + 1 , str + 1 + len);
	for(int i = 1 ; i <= len ; i ++ )
		if(str[i] == '(')str[i] = ')';
		else str[i] = '(';
	int y = calc();
	cout << x * y % mod;
	return 0;		
}

