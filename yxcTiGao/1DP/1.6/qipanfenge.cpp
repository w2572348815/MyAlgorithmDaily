#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;
const int N = 16;
const double INF = 1e9 + 10;
int s[N][N];
double f[N][N][N][N][N];
int n , m = 8;
double dx;
double getSum(int x , int y , int i , int j)
{
    double sum = 0;
    sum += s[i][j];
    sum -= s[i][y - 1];
    sum -= s[x - 1][j];
    sum += s[x - 1][y - 1];
    sum -= dx;
    return sum * sum / n;
}
double dp(int x1 , int y1 , int x2 , int y2 , int left)
{
    if(left == 1)return getSum(x1,y1,x2,y2);
    if(f[x1][y1][x2][y2][left] >= 0)return f[x1][y1][x2][y2][left];
    //纵切
    double &v = f[x1][y1][x2][y2][left];
    v = INF;
    for(int i = y1 ; i < y2 ; i ++ )
    {
        v = min(v , dp(x1 , y1 , x2 , i , left - 1) + getSum(x1 , i + 1 , x2 , y2));
        v = min(v , dp(x1 , i + 1 , x2 , y2 , left - 1) + getSum(x1 , y1 , x2 , i));
    }
    //横切
    for(int i = x1 ; i < x2 ; i ++ )
    {
        v = min(v , dp(x1,y1,i,y2,left - 1) + getSum(i + 1 , y1 , x2 , y2));
        v = min(v , dp(i + 1 , y1 , x2 , y2 , left - 1) + getSum(x1,y1,i,y2));
    }
    return v;
}
int main()
{
    scanf("%d",&n);
    for(int i = 1 ; i <= m ; i ++ )
        for(int j = 1 ; j <= m ; j ++ )
        {
            scanf("%d",&s[i][j]);
            s[i][j] += s[i - 1][j];
            s[i][j] += s[i][j - 1];
            s[i][j] -= s[i - 1][j - 1];
        }
    memset(f,-1,sizeof f);
    dx = (double)s[m][m] / n;
    dp(1,1,m,m,n);
    printf("%.3lf",sqrt(f[1][1][m][m][n]));
    return 0;
}
