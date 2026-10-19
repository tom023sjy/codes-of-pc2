#include<bits/stdc++.h>
#define uint unsigned long long 
using namespace std;
constexpr int X=1e5+5,V=5005;

int cid,N,H,W;
uint res;
int sum[V][V],S;

struct Node
{
    int x1,y1,x2,y2,c;
    inline Node() {}
    inline Node(int a,int b,int d,int e,int f):
        x1(a), y1(b), x2(d), y2(e), c(f) {}
}
n[X];

inline uint f(uint x)
{
    return x*(x-1)>>1;
}
inline void add(int a,int b,int c,int d,int f)
{
    sum[a][b]+=f, sum[c+1][d+1]+=f;
    sum[a][d+1]-=f, sum[c+1][b]-=f;
}
inline void Add(int a,int b,int d,int e,int f)
{  
    add(1,1,H,b-1,f); add(1,e+1,H,W,f);
    add(1,b,a-1,e,f); add(d+1,b,H,e,f);
}
inline void SUM()
{
    for(int i=1;i<=H;i++) 
        for(int j=1;j<=W;j++) sum[i][j]+=sum[i][j-1];
    
    for(int i=1;i<=H;i++) 
        for(int j=1;j<=W;j++) sum[i][j]+=sum[i-1][j];
}
inline void DIFF()
{
    for(int i=1;i<=H;i++){
        vector<int> tmp(W+1);
        for(int j=1;j<=W;j++) tmp[j]=sum[i][j]-sum[i][j-1];
        for(int j=1;j<=W;j++) sum[i][j]=tmp[j];
    }
    for(int i=1;i<=W;i++){
        vector<int> tmp(H+1);
        for(int j=1;j<=H;j++) tmp[j]=sum[j][i]-sum[j-1][i];
        for(int j=1;j<=H;j++) sum[j][i]=tmp[j];
    }
}


signed main()
{   
    freopen("chess.in","r",stdin);
    freopen("chess.out","w",stdout);


    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    double CL=clock();

    cin>>cid>>N>>H>>W;

    for(int i=1;i<=N;i++){
        int a,b,d,e,f; cin>>a>>b>>d>>e>>f;
        n[i]={a,b,d,e,f}; S+=f;
        add(1,1,H,b-1,f); add(1,e+1,H,W,f);
        add(1,b,a-1,e,f); add(d+1,b,H,e,f);
    }

    int TM=6;

    while(TM--&&S){
        if((clock()-CL)/CLOCKS_PER_SEC>3.5) break;
        int mxn=0, px=0, py=0;
        SUM();
        for(int i=1;i<=H;i++) 
            for(int j=1;j<=W;j++){
                if(sum[i][j]>mxn) mxn=sum[i][j], px=i, py=j;
            }
        
        DIFF();
        if(mxn==0) break;
        res+=f(mxn); S-=mxn;
        if((clock()-CL)/CLOCKS_PER_SEC>3.5) break;
        int cnt=0;
        for(int i=1;i<=N;i++){
            if(n[i].x1>px||n[i].x2<px||n[i].y1>py||n[i].y2<py) 
                Add(n[i].x1,n[i].y1,n[i].x2,n[i].y2,-n[i].c), cnt++;
        }
    }
    cout<<res;
}