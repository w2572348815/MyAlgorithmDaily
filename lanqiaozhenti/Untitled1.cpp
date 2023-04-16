#include<iostream>
#include<cstring>

using namespace std;

int months[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
bool check(char str[10]){
	for(int i = 0 ; i < 8 ; i ++ ){
		if(str[i + 1] == str[i] + 1 && str[i + 2] == str[i] + 2)return true;
	}
	return false;
}
int main(){
	int res = 0;
	int year = 2022 , month = 1 , day = 1;
	int size = 1;
	for(int i = 0 ; i < 365 ; i ++ ){
		char str[12];
		sprintf(str,"%04d%02d%02d",year,month,day);
		if(check(str))res++;
		if(++day > months[size++]){
			day = 1 , month++;
		}
	}
	cout << res;
	return 0;
}
