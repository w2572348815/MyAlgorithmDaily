#include<iostream>

using namespace std;
const int N = 510;
int d[N][N];
int n,m,k;
void floyd(){
	for(int i = 1; i <= n ; i ++ )
		for(int j = 1 ; j <= n ; j ++)
			for(int k = 1 ; k <= n ;k ++){
				d[j][k] = min(d[j][k] , d[j][i] + d[i][k]);
			}
}
int main(){
	cin >> n >>m>>k;
	for(int i = 1 ; i <= n ; i ++ ){
		for(int j = 1 ; j <= n ; j ++ ){
			if(i == j)d[i][j] = 0;
			else d[i][j] = 0x3f3f3f3f;
		}
	}
	for(int i = 0;i<m;i++){
		int a,b,c;
		cin >>a>>b>>c;
		d[a][b] = min(d[a][b],c);
	}
	floyd();
	for(int i = 0 ;i < k ;i ++){
		int a , b;
		cin >> a >> b;
		cout << d[a][b];
		cout << endl;
	}
	return 0;
}
