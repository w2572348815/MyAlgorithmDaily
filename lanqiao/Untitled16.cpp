#include<iostream>

using namespace std;

const int N = 1e5 + 10;
int stk[N] ,tt;
int n;
int main(){
	cin >> n;
	for(int i = 0 ; i < n ; i ++ ){
		int x;
		cin >> x;
		while(tt && x <= stk[tt])tt--;
		if(tt > 0 && x > stk[tt])cout << stk[tt] << endl;
		else cout << "-1" << endl;
		stk[++tt] = x;
	}
	
}
