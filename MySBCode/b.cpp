#include<iostream>
#include<set>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<set<int>> v;
    for(int i = 0 ; i < n ; i ++ ){
        int k;
        set<int > s;
        cin >> k;
        int a;
        while(k--){
            cin >> a;
            s.insert(a);
        }
        v.push_back(s);
    }
	
	int k;
	cin >> k;
	while(k--){
            int e , q;
            cin >> e >> q;
            int sum = v[e - 1].size() + v[q - 1].size();
            set<int > s;
            set_intersection(begin(v[e - 1]) , end(v[e - 1]) ,
                    begin(v[q - 1]) , end(v[q - 1]),inserter(s,s.begin()));
                    for(int i : s){
                        cout << i << ' ';
                    }
                    cout << endl;
            int num = s.size();
            sum -= num;
            float w = num * 1.0 / sum * 100;
            printf("%.2f%%\n",w);
        }
    
}
