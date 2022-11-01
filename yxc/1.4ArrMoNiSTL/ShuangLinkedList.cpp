#include<iostream>

using namespace std;

const int N = 100010;
int r[N],l[N],e[N],idx;
void init(){
    idx = 2;
    r[0] = 1;
    l[1] = 0;
}
void add(int k,int x){
     e[idx] = x;
     r[idx] = r[k];
     l[idx] = k ;
     l[r[k]] = idx;
     r[k] = idx;
     idx++;
}
void remove(int k){
    r[l[k]] = r[k];
    l[r[k]] = l[k];
}
int main(){
    init();
    int m;
    cin>>m;
    char s[10];
    while(m--){
        cin>>s;
        if(s[0]=='L'){
            int x;
            cin>>x;
            add(0,x);
        }else if(s[0] == 'R'){
                int x;
                cin>>x;
                add(l[1],x);
        }else if(s[0] == 'D'){
            int k;
            cin>>k;
            remove(k + 1);
        }else if(s[0]=='I'&&s[1] == 'L'){
            int k,x;
            cin>>k>>x;
            add(l[k+1],x);


        }else{
            int k,x;
            cin>>k>>x;
            add(k+1,x);
        }
    }
    int i = r[0];
    while(i!=1){
        cout<<e[i]<<" ";
        i = r[i];
    }
    return 0;
}
