#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int N = 300010;
int a[N] , s[N];
typedef pair<int , int > PII;
vector<PII> add , query;
vector<int > alls;
int n , m ;

int main(){
	scanf("%d%d",&n,&m);
	for(int i= 0 ; i< n ; i ++ ){
		int x , c;
		scanf("%d%d",&x,&c);
		add.push_back({x , c});
		alls.push_back(x);
	}
	for(int i = 0 ; i< m ; i ++ ){
		int l , r;
		query.push_back({l , r});
		alls.push_back(l);
		alls.push_back(r);
	}
	sort(alls.begin(),alls.end());
	alls.erase(	unique(alls.begin(),alls.end()) , alls.end());
	for(auto item : add ){
		int x = find(item.first);
		a[x] += item.second;
	}
	
} 