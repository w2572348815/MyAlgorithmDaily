#include<iostream>

using namespace std;

const int N = 1010;

int a[N] , help[N];
int n;
int res;

void merge_sort(int l ,int r){
	if(l >= r)return;
	int mid = l + r >> 1 ;
	merge_sort(l , mid) , merge_sort(mid + 1 , r);
	int i = l , j = mid + 1;
	int k = 0;
	while(i <= mid && j <= r){
		if(a[i] <= a[j])help[k++] = a[i++];
		else {
			help[k++] = a[j++];
			res += mid - i + 1;
		}
	}
	while(i <= mid)help[k++] = a[i++];
	while(j <= r)help[k++] = a[j++];
	for(int i = 0 ; i < k ; i ++ ){
		a[i + l] = help[i];
	}
}

int main(){
	cin >> n;
	for(int i = 0 ; i < n ; i ++)cin >> a[i];
	merge_sort(0 , n - 1);
	cout << res;
	return 0;	
}
