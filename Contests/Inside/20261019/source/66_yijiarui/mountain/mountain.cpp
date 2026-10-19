#include<bits/stdc++.h>
using namespace std;
constexpr int X=505,Mod=1e9+7;

int cid,N; string s;
int f[X][X][X],g[5005][5005][2];

int p[X];

inline void add(int &x,int y)
{
    x+=y; if(x>=Mod) x-=Mod;
}

signed main()
{
    freopen("mountain.in","r",stdin);
    freopen("mountain.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>cid>>s; N=s.size(); s=' '+s;

    if(cid==10){
        vector<int> res(N+1); 
        res[1]=1;
        for(int i=2;i<N;i++) res[i]=res[i-1]*2%Mod;
        res[N]=1;
        for(int i=1;i<=N;i++) cout<<res[i]<<' ';
        return 0;
    } 
    if(cid==11){
        vector<int> res(N+1); 
        res[1]=1;
        for(int i=2;i<N;i++) res[i]=res[i-1]*2%Mod;
        res[N]=1;
        reverse(res.begin()+1,res.end());
        for(int i=1;i<=N;i++) cout<<res[i]<<' ';
        return 0;
    } 

    if(cid==12||cid==13){

        g[1][1][s[1]=='U']=1;

        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                if(s[i]=='U'){
                    add(g[i][j][1],1ll*g[i-1][j][1]*j%Mod);
                    add(g[i][j][0],1ll*g[i-1][j][0]*(j-1)%Mod);
                    add(g[i][j][1],1ll*g[i-1][j-1][1]*j%Mod);
                    add(g[i][j][0],1ll*g[i-1][j-1][0]*(j-1)%Mod);
                }
                if(s[i]=='D'){
                    add(g[i][j][1],1ll*g[i-1][j][1]*j%Mod);
                    add(g[i][j][0],1ll*g[i-1][j][0]*j%Mod);
                    add(g[i][j][0],1ll*g[i-1][j][1]%Mod);
                    add(g[i][j][1],1ll*g[i-1][j+1][1]*j%Mod);
                    add(g[i][j][0],1ll*g[i-1][j+1][0]*j%Mod);
                    add(g[i][j][0],1ll*g[i-1][j-1][1]%Mod);
                }
            }
        }

        cout<<g[N][1][0]<<' ';
        for(int i=2;i<=N;i++) cout<<0<<' ';

        return 0;

    }

    f[1][1][1]=1; g[1][1][s[1]=='U']=1;

    for(int i=2;i<=N;i++){
        for(int j=1;j<=N;j++){
            for(int k=1;k<i;k++){
                if(s[k]=='U'){
                    if(s[i]=='U'){
                        add(f[i][j][k],1ll*f[i-1][j][k]*(j-1)%Mod);
                        add(f[i][j][k],1ll*f[i-1][j-1][k]*(j-1)%Mod);
                    }
                    else{
                        add(f[i][j][k],1ll*f[i-1][j][k]*j%Mod);
                        add(f[i][j][k],1ll*f[i-1][j+1][k]*j%Mod);
                    }
                }
                else{
                    if(s[i]=='U'){
                        add(f[i][j][k],1ll*f[i-1][j][k]*(j-1)%Mod);
                        add(f[i][j][k],1ll*f[i-1][j-1][k]*(j-1)%Mod);
                    }
                    else{
                        add(f[i][j][k],1ll*f[i-1][j][k]*j%Mod);
                        add(f[i][j][k],1ll*f[i-1][j+1][k]*j%Mod);
                    }
                }
                add(g[i][j][s[k]=='U'],1ll*f[i][j][k]%Mod);
            }

            if(s[i]=='U'){
                add(f[i][j][i],1ll*g[i-1][j][1]%Mod);
                add(f[i][j][i],1ll*g[i-1][j-1][1]%Mod);
            }
            else{
                add(f[i][j][i],1ll*g[i-1][j][1]%Mod);
                add(f[i][j][i],1ll*g[i-1][j-1][1]%Mod);
            }

            add(g[i][j][s[i]=='U'],1ll*f[i][j][i]%Mod);
        }
    }

    for(int i=1;i<=N;i++) cout<<f[N][1][i]<<' ';
}