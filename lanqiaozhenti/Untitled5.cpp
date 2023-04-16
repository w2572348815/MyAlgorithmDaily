#include<iostream>

using namespace std;

const int N = 510;
int a[N][N];

int main(){
	int n , m , e;
	cin >> n >> m >> e;
	long long res = 0;
	for(int i = 1 ; i <= n ; i ++ )
		for(int j = 1 ; j <= m ; j ++ ){
			cin >> a[i][j];
			a[i][j] += a[i - 1][j];
		}
			
	for(int i = 1 ; i <= n ; i ++ )
		for(int j = 1 ; j <= i ; j ++ )
			for(int r = 1 , l = 1 , sum = 0 ; r <= m ; r ++ )
			{
				sum += a[i][r] - a[j - 1][r];
				while(sum > e){
					sum -= a[i][l] - a[j - 1][l - 1];
					l++;
				}
				res += r - l + 1;
			}
	cout << res;
	return 0;
}
