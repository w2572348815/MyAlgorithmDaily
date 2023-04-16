#include<iostream>

using namespace std;

const int N = 1e5 + 10;
int a[N];
int n , q;

int main(){
	scanf("%d%d",&n,&q);
	for(int i = 0 ; i < n ; i ++ )scanf("%d",&a[i]);
	while(q--){
		int k;
		scanf("%d",&k);
		int l = 0 , r = n - 1;
		while(l < r){
			int mid = l + r >> 1;
			if(a[mid] < k)l = mid + 1;
			else r = mid;
		}
		if(a[l] != k){
			cout << "-1 -1" << endl;
			continue;
		}
		else cout << l << ' ';
		l = 0 , r = n - 1;
		while(l < r){
			int mid = l + r + 1>> 1;
			if(a[mid] > k)r = mid - 1;
			else l = mid;
			
		}
		cout << r << endl;
	}
}
