#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
int id,n,h,w,ans=0;
int a[5010][5010];
bool vis[100010];
struct qu
{
    int x1,y1,x2,y2,c;
}s[100010];
bool check()
{
    for(int i=1;i<=n;i++) 
    {
        if(!vis[i]) return 1;
    }
    return 0;
}
signed main()
{
    freopen("chess.in","r",stdin);
    freopen("chess.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>id>>n>>h>>w;
    for(int i=1;i<=n;i++) cin>>s[i].x1>>s[i].y1>>s[i].x2>>s[i].y2>>s[i].c;
    while(check())
    {
        int tot=0;
        for(int i=1;i<=n;i++)
        {
            if(!vis[i]) tot+=s[i].c;
        }
        for(int i=0;i<=h;i++)
        {
            for(int j=0;j<=w;j++) a[i][j]=0;
        }
        a[1][1]=tot;
        int maxn=0,x=0,y=0;
        for(int i=1;i<=n;i++)
        {
            if(!vis[i]) 
            {
                a[s[i].x1][s[i].y1]-=s[i].c;
                a[s[i].x1][s[i].y2+1]+=s[i].c;
                a[s[i].x2+1][s[i].y1]+=s[i].c;
                a[s[i].x2+1][s[i].y2+1]-=s[i].c;
            }
        }
        for(int i=1;i<=h;i++)
        {
            for(int j=1;j<=w;j++) a[i][j]+=a[i][j-1];
        }
        for(int i=1;i<=h;i++)
        {
            for(int j=1;j<=w;j++) a[i][j]+=a[i-1][j];
        }
        for(int i=1;i<=h;i++)
        {
            for(int j=1;j<=w;j++)
            {
                if(a[i][j]>maxn) x=i,y=j,maxn=a[i][j];
            }
        }
        if(maxn%2==0) ans+=(maxn/2)*(maxn-1);
        else ans+=((maxn-1)/2)*maxn;
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                if(x>=s[i].x1&&x<=s[i].x2&&y>=s[i].y1&&y<=s[i].y2) continue;
                else vis[i]=1;    
            }
        }
    }
    cout<<ans;
}