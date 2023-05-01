#include<iostream>
#include<vector>

using namespace std;

int K ,B;
const int N = 35;
int f[N][N];
int count(int a)
{
    if(!a)return 0;
    vector<int > num;
    while(a)num.push_back(a % B),a /= B;
    int res = 0;
    int last = 0;
    for(int i = num.size() - 1 ; i >= 0 ; i -- )
    {
        int x = num[i];
        if(x)
        {
            res += f[i][K - last];
            if(x > 1)
            {
                if(K - last - 1 >= 0)res += f[i][K - last - 1];
                break;
            }
            else
            {
                last ++;
                if(last > K)break;
            }
        }
        if(!i && last == K)res ++;
        
    }
    return res;
    
}
void init()
{
    for(int i = 0 ; i < N ; i ++ )
        for(int j = 0 ; j <= i ; j ++ )
            if(!j)f[i][j] = 1;
            else f[i][j] = f[i - 1][j] + f[i - 1][j - 1]; 
}
int main()
{
    int a,b;
    init();
    cin >> a >> b >> K >> B;
    cout << count(b) - count(a - 1);
    return 0;
}