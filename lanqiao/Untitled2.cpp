#include<iostream>

using namespace std;

const int N = 1010;

int a[N] , help[N];
int n;

void merge_sort(int arr[] , int l , int r){
	if(l >= r)return ;
	int mid = l + r >> 1;
	merge_sort(arr , l , mid) , merge_sort(arr , mid + 1 , r);
	
	int i = l , j = mid + 1 , k = 0;
	while(i <= mid && j <= r){
		if(a[i] < a[j])help[k++] = a[i++];
		else help[k++] = a[j++];
	}
	while(i <= mid)help[k++] = a[i++];
	while(j <= r)help[k++] = a[j++];
	for(int i = 0 ; i < k ; i ++ ){
		a[l + i] = help[i];
	}
	
}
int main(){
	cin >> n;
	for(int i = 0 ; i < n ; i ++ )cin >> a[i];
	merge_sort(a,0,n - 1);
	for(int i = 0 ; i < n ; i ++ )cout << a[i] << ' ';
	return 0;
}
