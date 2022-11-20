/*
 * @Author: wujiahao 2572348815@qq.com
 * @Date: 2022-11-19 23:21:23
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-11-20 08:44:18
 * @FilePath: \MyAlgorithmDaily\yxcJiChu\4.2OlaAndQmiAndEXgcdAndChinaLeft\GetOlaToN.cpp
 * @Description:
 *
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved.
 */
#include <iostream>

using namespace std;

const int N = 100010;
int prime[N], cnt;
bool st[N];
int phi[N];
int n;
typedef long long LL;
LL get_ola()
{
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!st[i])
        {
            prime[cnt++] = i;
            phi[i] = i - 1;
        }
        for (int j = 0; prime[j] <= n / i; j++)
        {
            st[prime[j] * i] = true;
            if (i % prime[j] == 0)
            {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            }
            
            phi[prime[j] * i] = phi[i] * (prime[j] - 1);
        }
    }
    LL res = 0;
    for (int i = 1; i <= n; i++)
    {
        res += phi[i];
    }
    return res;
}
int main()
{
    scanf("%d", &n);
    LL res = get_ola();
    cout << res << endl;
    return 0;
}