#include<iostream>
#include<vector>

using namespace std;

const int N = 11;
int f[N][10];
void init()
{
    for(int i = 0; i <= 9 ; i ++ )f[1][i] = 1;
    for(int i = 2 ; i < N ; i ++ )
        for(int j = 0 ; j <= 9 ; j ++ )
            for(int k = 0 ; k <= 9 ; k ++ )
                if(abs(j - k) >= 2)
                    f[i][j] += f[i - 1][k];
}
int count(int n)
{
    if(!n)return 0;
    vector<int> num;
    int res = 0;
    int last = -2;
    while(n)num.push_back(n % 10),n/=10;
    for(int i = num.size() - 1 ; i >= 0 ; i -- )
    {
        int x = num[i];
        for(int j = i == num.size() - 1 ; j < x ; j ++ )
            if(abs(j - last) >= 2)res += f[i + 1][j];
        if(abs(x - last) >= 2)last = x;
        else break;
        if(!i)res++;
    }
    for(int i = 1 ; i < num.size() ; i ++ )
        for(int j = 1 ; j < 10 ; j ++ )
        res += f[i][j];
    return res;
}
int main()
{
    int l , r;
    init();
    cin >> l >> r;
    cout << count(r) - count(l - 1) << endl;
    return 0;    
}