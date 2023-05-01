#include<iostream>
#include<algorithm>

using namespace std;

const int N = 5010;
typedef pair<int , int > PII;
PII q[N];
int f[N];

int main(){
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; i ++ ){
        int a , b;
        cin >> a >> b;
        q[i].first = a;
        q[i].second = b;
    }
    sort( q ,q + n);
    int res = 0;
    for(int i = 0 ; i < n ; i ++ ){
        f[i] = 1;
        for(int j = 0 ; j < i ; j ++ ){
            if(q[i].second > q[j].second)f[i] = max(f[i] , f[j] + 1);
        }
        res = max(res , f[i]);
    }
    cout << res;
    return 0;
    
}