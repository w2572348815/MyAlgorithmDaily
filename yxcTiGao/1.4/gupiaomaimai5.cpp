#include<iostream>
#include<cstring>

using namespace std;

const int N = 1e5 + 10 , M = 110;
int w[N] , f[N][3];

int main(){
    int n;
    cin >> n;
    memset(f , -0x3f , sizeof f);
    f[0][0] = 0;
    for(int i = 1 ; i <= n ;  i++)cin >> w[i];
    for(int i = 1 ; i <= n ; i ++ ){
        //�����޹�Ʊ������
        f[i][0] = max(f[i - 1][0] , f[i - 1][2]);
        
        //�����й�Ʊ
        f[i][1] = max(f[i - 1][1] , f[i - 1][0] - w[i]);
        //�����޹�Ʊ��������
        f[i][2] = f[i - 1][1] + w[i];
    }
    cout  << max(f[n][0] , f[n][2]);
    return 0;
}