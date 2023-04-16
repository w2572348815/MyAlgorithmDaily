#include<iostream>

using namespace std;

const int N = 1e5 + 10;
int a[N];
int n , m;
typedef pair<int,int> PII;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i = 1 ;i <= n ; i ++ )a[i] = i;
	PII stk[N];
	int top = 0;
	while(m--)
	{
		int p , q;
		scanf("%d%d",&p,&q);
		if(p == 0)
		{
			int t = q;
			if(top > 0 && stk[top].first == 0)t = max(stk[top--].second , q);
			if(top >= 2 && stk[top - 1].second < t)top -= 2;
			stk[++top] = {p,q};
		}else if(top){
			if(top > 0 && stk[top].first == 1)q = max(stk[top--].second , q);
			if(top >= 2 && stk[top - 1].second > q)top -= 2;
			stk[++top] = {p,q};
		}
	}
	int l = 1 , r = n , k = n;
	for(int i = 1 ; i <= top ; i ++ ){
		int p = stk[i].first ;int q = stk[i].second;
		while(p == 0 && l <= r && r > q)a[r--] = k--;
		while(p == 1 && l <= r && l < q)a[l++] = k--;
		if(l > r)break;
	}
	if(top % 2)
		while(l <= r)a[l++] = k--;
	else 
		while(l <= r)a[r--] = k--;
	for(int i = 1 ; i <= n ; i ++ )
		printf("%d ",a[i]);
	return 0;
}
