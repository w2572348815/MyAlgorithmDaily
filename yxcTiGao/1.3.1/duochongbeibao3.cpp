#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 1010;
int f[N] , g[N] , q[N];

int main(){
    int n , m;
    cin >> n >> m;
    for(int i = 0 ; i < n ; i ++ ){
        int v , w , s;
        cin >> v >> w >> s;
        memcpy(g,f,sizeof f);
        for(int j = 0 ; j < v ; j ++ ){
            int hh = 0 , tt = -1;
            for(int k = j ; k <= m ; k += v){
                if(hh <= tt && k - s * v > q[hh])hh++;
                if(hh <= tt)f[k] = max(f[k] , g[q[hh]] + (k - q[hh]) / v * w);
                while(hh <= tt && g[q[tt]] - (q[tt] - j) / v * w <= g[k] - (k - j) / v * w)tt--;
                f[++tt] = k;
            }
        }

    }
    cout << f[m];
    return 0;
}