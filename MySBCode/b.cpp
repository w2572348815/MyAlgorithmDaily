#include<iostream>
#include<unordered_set>
#include<cstring>
using namespace std;

int k,n;

const int N = 10010;
int f[N],s[110];
int sg(int x){
	if(f[x] != -1)return f[x];
	unordered_set<int> se;
	for(int i =0 ; i < k ; i ++ ){
		int e = s[i];
		if(x >= e)se.insert(sg(x - e));
	}
	for(int i = 0 ; ;i ++){
		if(!se.count(i))return f[x] = i;
	}
}
int main(){
	cin >> k;
	for(int i = 0 ; i < k ; i ++ )cin >> s[k];
	cin >> n;
	memset(f,-1,sizeof f);
	int res = 0;
	for(int i = 0 ; i < n ; i ++){
		int a ;
		cin >> a;
		res ^= sg(a);
	}
	if(res)cout<<"yes";
	else cout<<"no";
	return 0;
}