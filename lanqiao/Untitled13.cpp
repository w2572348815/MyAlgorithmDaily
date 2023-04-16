#include<iostream>

using namespace std;

const int N = 1e5 + 10;

int a[N];
int n ;

int quick_sort2(int arr[] , int l , int r , int k){
	if(l == r)return a[l];
	int i = l - 1 , j = r + 1 , x = a[l];
	while(i < j){
		do i ++;while(a[i] < x);
		do j -- ;while(a[j] > x);
		if(i < j)swap(a[i] , a[j]);
	}
	if(j - l + 1 >= k)return quick_sort2(a , l , j , k);
	else return quick_sort2(a,j + 1, r , k - (j - l + 1));
}
int main(){
	int k;
	cin >> n >> k;
	
	for(int i = 0 ; i < n ; i ++ )cin >> a[i];
	int e = quick_sort2(a , 0 , n - 1 , k);
	cout << e;
	return 0;
}
