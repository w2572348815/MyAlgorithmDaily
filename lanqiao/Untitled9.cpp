#include<iostream>

using namespace std;

const int N = 1010;
int a[N][N] , c[N][N];

void insert(int x1 , int y1 , int x2 , int y2 , int e){
	c[x1][y1] += e;
	c[x1][y2 + 1] -= e;
	c[x2 + 1][y1] -= e;
	c[x2 + 1][y2 + 1] += e;
}

int main(){
	int n , m , q;
	cin >> n >> m >> q;
	for(int i = 1 ; i <= n ; i ++ )
		for(int j = 1 ; j <= m ; j ++ ){
			cin >> a[i][j];
			insert(i , j , i , j , a[i][j]);
		}
	for(int i = 0 ; i < q ; i ++ ){
		int q , w , e , r , t;
		cin >> q >> w >>e >> r >>t;
		insert(q,w,e,r,t);
	}
	for(int i = 1 ; i <= n ; i ++ )
		for(int j = 1 ; j <= m ; j ++ ){
			c[i][j] += c[i - 1][j] + c[i][j - 1] - c[i - 1][j - 1];
		}
	for(int i = 1 ; i <= n ; i ++ ){
	
		for(int j = 1 ; j <= m ; j ++ )
			cout << c[i][j] << ' ';
		cout  <<endl;
	}
	return 0;
}
