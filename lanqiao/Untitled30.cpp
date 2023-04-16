#include<iostream>
#include<queue>
#include<unordered_map>
#include<string>

using namespace std;



int bfs(string start){
	string end = "12345678x";
	queue<string> q;
	unordered_map<string , int > map;
	map[start] = 0;
	q.push(start);
	int dx[4] = {0,0,1,-1} , dy[4] = {1,-1,0,0};
	while(q.size()){
		string tmp = q.front();
		q.pop();
		int distance = map[tmp];
		if(tmp == end)return distance;
		int idx = tmp.find('x');
		int x = idx / 3 , y = idx % 3;
		for(int i = 0 ; i < 4 ; i ++ ){
			int a = x + dx[i] , b = y + dy[i];
			if(a >= 0 && a < 3 && b >= 0 && b < 3){
				swap(tmp[a * 3 + b] , tmp[idx]);
				if(!map.count(tmp)){
					map[tmp] = distance + 1;
					q.push(tmp);
				}
				swap(tmp[a * 3 + b] , tmp[idx]);
			}
		}
	}
	return -1;		
}

int main(){
	string s;
	for(int i = 0; i < 9 ; i ++ ){
		char c;
		cin >> c;
		s += c;
	}
	cout << bfs(s);
	return 0;
} 
