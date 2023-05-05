#include<iostream>

using namespace std;

const int N = 1e5 + 10;
int a[N],q[N];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i ++ )scanf("%d",&a[i]);
    int len = 0;
    q[0] = -2e9 - 10;
    for(int i = 0 ; i < n ; i ++)
    {
        int l = 0 , r = len;
        while(l < r)
        {
            int mid = l + r + 1 >> 1;
            if(a[i] > q[mid])l = mid;
            else r = mid - 1;
        }
        len = max(len , r + 1);
        q[r + 1] = a[i];
    }
    cout << len;
    return 0;
}