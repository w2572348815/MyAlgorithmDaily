#include<iostream>
#include<cmath>
#include<cstring>

using namespace std;

#define x first;
#define y second;

typedef pair<double , double> PDD;
const int N = 18 , M = 1 << N;
const double eps = 1e-6;
int n , m;
int f[M];
PDD d[N];
int path[N][N];

int cmp(double x1 , double y1){
    if(fabs(x1 - y1) < eps)return 0;
    if(x1 > y1)return 1;
    return -1;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 0 ; i < n ; i ++ ){
            cin >> d[i].x;
            cin >> d[i].y;
        }
        memset(path , 0 , sizeof path);
        for(int i = 0 ; i < n ; i ++ ){
            path[i][i] = 1 << i;
            for(int j = 0 ; j < n ; j ++ ){
                int x1 = d[i].x;
                int y1 = d[i].y;
                int x2 = d[j].x;
                int y2 = d[j].y;
                if(!cmp(x1 , x2))continue;
                int a = (y1 / x1 - y2 / x2) / (x1 - x2);
                int b = (y1 / x1) - a * x1; 
                if(a > 0)continue;
                int state = 0;
                for(int k = 0 ; k < n ; k ++ ){
                    int x3 = d[k].x;
                    int y3 = d[k].y;
                    if(!cmp(a * x3 * x3 + b * x3 , y3))state += 1 << k; 
                }
                path[i][j] = state;
            }
        }
        memset(f , 0x3f , sizeof f);
        f[0] = 0;
        for(int i = 0 ; i < 1 << n - 1 ; i ++ ){
            int e = 0;
            while(i >> e & 1)e ++;
            for(int j = 0 ; j < n ; j ++ ){
                f[i | path[e][j]] = min(f[i | path[e][j]] , f[i] + 1);
            }
        }
        cout << f[(1 << n ) - 1] << endl;
    }
}