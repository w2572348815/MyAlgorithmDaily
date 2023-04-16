#include<iostream>

using namespace std;
bool check(int x){
	if(x % 10 - 1 != (x/100)%10)return false;
	if((x/10)%10 != (x/1000)%10)return false;
	return true;
}
int main(){
	int res = 0;
	for(int i = 0 ; i < 5 ; i ++ )
	{
		int a;
		cin >> a;
		if(check(a))res++;
	}
	cout << res;
	return 0;
}
