#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 1100;
struct stone{
    int s , w , l;
    bool operator< (const stone & r) const{
        return s * r.l < r.s * l;
    }
}st[N];
int f[N];

int main(){
    int t;
    cin >> t;
    for(int e = 1 ; e <= t ; e ++ ){
        int n;
        cin >> n;
        int m = 0;
        for(int i = 1 ; i <= n ; i ++ ){
            cin >> st[i].s >> st[i].w >> st[i].l;
            m += st[i].s;
        }
        sort(st + 1, st + n + 1);
        memset(f,-0x3f,sizeof f);
        f[0] = 0;
        for(int i = 1 ; i <= n ;  i ++ ){
            for(int j = m ; j >= st[i].s ; j --){
                f[j] = max(f[j] , f[j - st[i].s] - (j - st[i].s) * st[i].l + st[i].w);
            }
        }
        int res = 0;
        for(int i = 1 ; i <= m ; i ++ )res = max(res , f[i]);
        cout << res << endl;
    }
}