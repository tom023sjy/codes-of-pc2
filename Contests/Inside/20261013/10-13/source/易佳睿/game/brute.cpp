#include<bits/stdc++.h>
using namespace std;
constexpr int X=3005;

int N,f[X][X];

inline int calc(int u,int d)
{
    if(f[u][d]) return f[u][d];

    int t=1;

    for(int v=u-d-1;v>=1;v--){
        int x=calc(v,u-v);
        if(x==1) t=2;
    }
    for(int v=u+d+1;v<=N;v++){
        int x=calc(v,v-u);
        if(x==1) t=2;
    }
    
    return f[u][d]=t;
}

signed main()
{
    cin>>N;

    for(int i=1;i<=N;i++){
        for(int d=0;d<=N-1;d++) cout<<calc(i,d)<<' ';
        cout<<endl;
    }
}