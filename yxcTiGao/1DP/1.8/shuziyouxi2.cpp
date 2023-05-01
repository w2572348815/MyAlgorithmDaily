#include<iostream>
#include<vector>

using namespace std;

typedef long long LL;

const int N = 15,mod = 110;
int f[N][10][mod];
int m;
int getmod(int a, int b)
{
    return (a % b + b) % b;
}
void init()
{
    for(int i = 0 ; i <= 9 ; i ++ )f[1][i][getmod(i,m)]++;
    for(int i = 2 ; i < N ; i ++ )
        for(int j = 0 ; j <= 9 ; j ++ )
            for(int k = 0 ; k < m ; k ++ )
                for(int x = 0 ; x < 10 ; x ++ )
                f[i][j][k] += f[i - 1][x][getmod(k - j , m)];
}
int count(int n)
{
    if(!n)return 1;
    int last = 0;
    vector<int> num;
    while(n)num.push_back(n % 10) , n /= 10;
    int res = 0;
    for(int i = num.size() - 1 ; i >= 0 ; i -- )
    {
        int x = num[i];
        for(int j = 0 ; j < x; j ++ )
        {
            res += f[i + 1][j][getmod(-last,m)];
        }
        last += x;
        if(!i && last % m == 0)res ++;
    }
    return res;
}
int main()
{
    LL l , r;
    
    scanf("%lld%lld%d",&l,&r,&m);
    init();
    cout << count(r) - count(l - 1);
    return 0;
}