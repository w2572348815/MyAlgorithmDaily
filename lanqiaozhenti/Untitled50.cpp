#include<bits/stdc++.h>

using namespace std;

int main(){
	
	int a[5] = {0,1,2,3,4};
	do{
		cout << a[0] << a[1] << a[2] << a[3] << a[4] << endl;
	}while(next_permutation(a,a + 5));
	return 0;
} 
