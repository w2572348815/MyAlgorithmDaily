#include<algorithm>
#include<iostream>

using namespace std;

const int N = 1e5 + 10;
typedef pair<int,int> PII;
PII m[N];
int n;
int res;
void merge(){
	int st = -2e9 , ed = -2e9;
	for(int i = 0 ; i < n ; i ++ ){
		int a = m[i].first , b = m[i].second;
		if(ed < a){
			if(st != -2e9)res++;
			st = a , ed = b;
		}else{
			ed = b;
		}
	}
	if(st != -2e9)res++;
}
int main(){
	cin >> n;
	for(int i = 0 ; i < n ; i ++ )cin >> m[i].first >> m[i].second;
	sort(m , m + n);
	merge();
	cout << res;
	return 0;
}
