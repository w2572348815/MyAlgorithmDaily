#include<iostream>
#include<vector>

using namespace std;

const int N = 20 , P = 1e9 + 7;
int power7[N],power9[N];
typedef long long LL;

struct F{
	int s0,s1,s2;
}f[N][10][7][7];

int mod(LL a , int b)
{
	return (a % b + b) % b;
}
void init()
{
	for(int i = 0 ; i < 10 ; i ++ )
	{
		if(i == 7)continue;
		f[1][i][i % 7][i % 7].s0 ++;
		f[1][i][i % 7][i % 7].s1 += i;
		f[1][i][i % 7][i % 7].s2 += i * i;
	}
	LL power = 10;
	for(int i = 2 ; i < N ; i ++ , power *= 10)
		for(int j = 0 ; j < 10 ; j ++ )
		{
			if(j == 7)continue;
			for(int a = 0 ; a < 7 ; a ++ )
				for(int b = 0 ; b < 7 ; b ++ )
					for(int k = 0 ; k < 10 ; k ++ )
					{
						if(k == 7)continue;
						auto &v1 = f[i][j][a][b];
						auto &v2 = f[i - 1][k][mod(a - j * (power % 7) , 7)][mod(b - j ,7)];
						v1.s0 = (v1.s0 + v2.s0) % P;
						v1.s1 = (v1.s1 + j * (power % P) % P * v2.s0 + v2.s1) % P;
						v1.s2 = (v1.s2 + 
								j * j * (power % P) % P * (power % P) % P * v2.s1 + 
								v2.s2 + 
								2 * j * (power % P) % P * v2.s1 % P
								) % P;
						
					}
		}
	power7[0] = power9[0] = 1;
	for(int i = 1 ; i < N ; i ++ )
	{
		power7[i] = power7[i - 1] * 10 % 7;
		power9[i] = power9[i - 1] * 10 % P;
	}
}
F get(int i , int j , int a, int b)
{
	int s0 = 0 , s1 = 0 , s2 = 0;
	for(int x = 0 ; x < 7 ; x ++ )
		for(int y = 0 ; y < 7 ; y ++)
		{
			if(x == a || y == b)continue;
			auto &v = f[i][j][x][y];
			s0 = (s0 + v.s0) % P;
			s1 = (s1 + v.s1) % P;
			s2 = (s2 + v.s2) % P;
		}
		return {s0 , s1 , s2};
}
int count(LL n)
{
	if(!n)return 0;
	LL b_n = n % P;
	vector<int > nums;
	while(n)nums.push_back(n % 10) , n /= 10;
	int res = 0;
	int last_a = 0,  last_b = 0;
	for(int i = nums.size() - 1; i >= 0 ; i -- )
	{
		int x = nums[i];
		for(int j = 0 ; j < x ; j ++ )
		{
			if(j == 7)continue;
			int a = mod(-last_a % 7 * power7[i + 1] , 7);
			int b = mod(-last_b , 7);
			auto v = get(i + 1 , j , a , b);
			res = (res + 
					(last_a % P) * (last_a % P) % P * power9[i + 1]% P * power9[i + 1] % P * v.s0 % P +
					2 * (last_a % P) % P * power9[i + 1] % P * v.s1 % P +
					v.s2
					)  % P;
		}
		if(x == 7)break;
		last_a = last_a * 10 + x;
		last_b += x;
		if(!i && last_a % 7 && last_b % 7)res = (res + b_n * b_n) % P;
	}
	return res;
}

int main()
{
	LL l , r;
	init();
	cin >> l >> r;
	cout << count(r) - count(l - 1);
	return 0;
}