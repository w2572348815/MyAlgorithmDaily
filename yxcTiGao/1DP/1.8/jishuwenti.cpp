#include<iostream>
#include<vector>

using namespace std;

int getSum(vector<int> num , int a , int b)
{
    int res = 0;
    int x = 1;
    for(int i = a ; i <= b ; i ++ )
    {
        res += num[i] * x;
        x *= 10;
    }
    return res;
}
int pow10(int i)
{
    int res = 1;
    while(i -- )
    {
        res *= 10;
    }
    return res;
}
int count(int n , int x)
{
    if(!n)return 0;
    int res = 0;
    vector<int > num;
    while(n)
    {
        num.push_back(n % 10);
        n /= 10;
    }
    n = num.size();
    for(int i = n - 1 - !x; i >= 0 ; i -- )
    {
        if(i < n - 1)
        {
            res += getSum(num,i + 1,n - 1) * pow10(i);
            if(!x)res -= pow10(i);
        }
        if(num[i] > x)res += pow10(i);
        if(num[i] == x)res += getSum(num,0,i - 1) + 1;
    }
    return res;
}
int main()
{
    int a, b;
    scanf("%d%d",&a,&b);
    if(a < b)swap(a , b);
    for(int i = 0 ; i < 10 ; i ++ )
    {
        cout << count(a , i) - count(b - 1 , i) << ' ';
    }
    return 0;
}