#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
typedef long long LL;
const int N = 2e5 + 10;
LL a[N];
vector<LL> b[N];

int main(){
	int n;
	cin >> n;
	LL res = 0;
	for(int i = 0 ; i < n ; i ++ )cin >> a[i];
	for(int i = 0 ; i < n ; i ++ )
	{
		while(a[i] > 1){
			b[i].push_back(a[i]);
			int flag = 0;
			for(LL j : b[i - 1]){
				if(a[i] == j){
					flag = 1;
					break;
				}
			}
			if(!flag)res++;
			a[i] = sqrt(a[i] / 2 + 1);
		}
	}
	cout << res;
	return 0;
}
