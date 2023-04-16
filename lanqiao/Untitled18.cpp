#include<iostream>

using namespace std;

const int N = 1e5 + 10;
char c[N] , d[N];
int ne[N];
int lenc , lend;

int main(){
	cin >> lend >> d + 1 >> lenc >> c + 1;
	for(int i = 2 , j = 0 ; i <= lend ; i ++ ){
		while(j && d[i] != d[j + 1])j = ne[j];
		if(d[i] == d[j + 1])j++;
		ne[i] = j;
	}
	for(int i = 1 , j = 0 ; i <= lenc ; i ++ ){
		while(j && c[i] != d[j + 1])j = ne[j];
		if(c[i] == d[j + 1])j++;
		if(j == lend){
			cout << i - lend;
			j = ne[j];
		}
	}
	return 0;
}
