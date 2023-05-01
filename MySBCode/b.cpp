#include<iostream>
#include<cstring>

using namespace std;

const int N = 1010;
struct a{
    int x,y,k,c;
}country[N];
int n;
typedef long long LL;
LL f[N];

int main()
{
    scanf("%d",&n);
    for(int i = 1 ; i <= n ; i ++ )
    {
        int a,b;
        scanf("%d%d",&a,&b);
        country[i].x = a , country[i].y = b;
    }

    for(int i = 1 ; i <= n ; i ++ )scanf("%d",&country[i].c);
    for(int i = 1 ; i <= n ; i ++ )scanf("%d",country[i].k);
    memset(f,0x3f,sizeof f);
    f[0] = 0;
    for(int i = 1 ; i <= n ; i ++ )
    {
        for(int j = 0 ; j < 2 ; j ++ )
        {
            if(!j)
            {
                f[i] = min(f[i] , f[i - 1] + country[i].c);
            }
            else
            {
                for(int k = 1 ; k <= i ; k ++ )
                {
                    LL sum = abs((country[i].x - country[k].x) + abs(country[i].y - country[k].y))*country[i].c;
                    f[i] = min(f[i] , f[i - 1] + sum);
                }
            }
        }
    }
    cout << f[n];
    return 0;
}