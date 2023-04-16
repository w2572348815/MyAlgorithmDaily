#include<iostream>
#include<algorithm>

using namespace std;
struct line{
	double k , b;
	bool operator< (const line &e ){
		if(k != e.k)return k < e.k;
		return b < e.b;
	}
}l[1000000];
int n;
int main(){

	for(int i = 0; i < 20 ; i ++ )
		for(int j = 0 ; j < 21 ; j ++ )
			for(int x = 0 ; x < 20 ; x ++ )
				for(int y = 0; y < 21 ; y ++ )
				{
					if(i != x && j != y){
						double k = (double)(y - j)/(x - i);
						double b = (double)y - k*x;
						l[n++] = {k,b};
					}
				}
	sort(l , l + n);
	int res = 1;
	for(int i = 1; i < n ; i ++ ){
		if(fabs(l[i].k - l[i - 1].k) > 1e-6 || fabs(l[i].b - l[i - 1].b) > 1e-6)res++;
	}
	cout << res + 41;
	
	return 0;
}
