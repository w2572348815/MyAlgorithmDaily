#include<iostream>
#include<vector>

using namespace std;

const int N = 9;
int f[N][10];
void init()
{
    for(int i = 0 ; i <= 9 ; i ++ )
        if(i != 4)f[1][i] ++;
    for(int i = 2 ; i < N ; i ++ )
        for(int j = 0 ; j <= 9 ; j ++ )
        {
            if(j == 4)continue;
            for(int k = 0 ; k < 10 ; k ++ )
            {
                if(k == 4 || j == 6 && k == 2)continue;
                f[i][j] += f[i - 1][k];
            }
        }
}
int count(int n)
{
    if(!n)return 1;
    vector<int > num;
    int last = 0;
    int res = 0;
    while(n)num.push_back(n % 10) , n /= 10;
    for(int i = num.size() - 1 ; i >= 0 ; i --)
    {
        int x = num[i];
        for(int j = 0 ; j < x ; j ++ )
        {
            if(i == 4 || i == 2 && last == 6)continue;
            res += f[i + 1][j];
        }
        if(x == 4 || last == 6 && x == 2)break;
        last = x;
        if(!i)res++;
    }
    return res;
}
int main()
{
    int l , r;
    cin >> l >> r;
    init();
    cout << count(r) - count(l - 1);
    return 0;
}