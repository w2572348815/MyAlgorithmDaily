#include<iostream>
#include<vector>

using namespace std;

const int N = 32;
int f[N][10];

void init()
{
    for(int i = 1 ; i < N ; i ++ )
        for(int j = 0 ; j < 10 ; j ++ )
            for(int k = j ; k < 10 ; k ++ )
            {
                if(i == 1)f[i][j] = 1;
                else f[i][j] += f[i - 1][k];
            }
}
int count(int a)
{
    if(!a)return 1;
    vector<int > num;
    int res = 0;
    while(a)num.push_back(a % 10), a /= 10;
    int last = 0;
    for(int i = num.size() - 1; i >= 0 ; i -- )
    {
        int x = num[i];
        for(int j = last ; j < x ; j++ )
        {
            res += f[i + 1][j];
        }
        if(x < last)break;
        last = x;
        if(!i)res ++;
    }
    return res;
}
int main()
{
    init();
    int a , b;
    cin >> a >> b;
    cout << count(b) - count(a - 1);
    return 0;
}