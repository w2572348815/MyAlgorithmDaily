#include<iostream>
#include<cstring>
#include<queue>
#include<unordered_map>
using namespace std;


string target= "12345678x";

int  bfs(string str){
	queue<string > q;
	q.push(str);
	unordered_map<string , int> d;
	d[str] = 0;
	int dx[4] = {1,-1,0,0} , dy[4] = {0,0,1,-1};
	while(q.size()){
		string s = q.front();
		q.pop();
		int distance = d[s];
		if(s == target)return distance;
		int index = s.find('x');
		int x = index / 3 , y = index % 3;
		for(int i = 0 ; i< 4 ; i ++ ){
			int a = x + dx[i] , b = y + dy[i];
			if(a >= 0 && a < 3 && b >= 0 && b < 3){
				swap(s[index] , s[a*3+b]);
				if(!d.count(s)){
					d[s] = distance + 1;
					q.push(s);
				}
				swap(s[index] , s[a*3 + b]);
			}
		}
	}	
	return -1;
}
int main(){
	string str;
	for(int i = 0 ; i < 9 ; i ++ ){
		char c;
		cin >> str[i];
		
	}
	for(int i = 0 ; i < 9 ; i ++ )cout << str[i];
	cout << bfs(str);
	return 0;
}
