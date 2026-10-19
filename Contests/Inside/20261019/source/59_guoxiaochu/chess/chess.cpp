#include <bits/stdc++.h>
using namespace std;
long long a[5005][5005];
inline void add(int x,int y,int xx,int yy,int v)
{
    a[x][y]+=v;
    a[x][yy+1]-=v;
    a[xx+1][y]-=v;
    a[xx+1][yy+1]+=v;
}
struct node
{
    int x,y,xx,yy,c;
};
vector<node> b;
int main()
{
    freopen("chess.in","r",stdin);
    freopen("chess.out","w",stdout);
    int cid;
    cin>>cid;
    int n,h,w;
    cin>>n>>h>>w;
    for(int i=1;i<=n;i++)
    {
        int x,y,xx,yy,c;
        cin>>x>>y>>xx>>yy>>c;
        b.push_back({x,y,xx,yy,c});
    }
    unsigned long long ans=0;
    while(!b.empty())
    {
        vector<node> c;
        for(int i=1;i<=h;i++)
        {
            for(int j=1;j<=w;j++)
            {
                a[i][j]=0;
            }
        }
        for(auto i:b)
        {
            // cout<<i.x<<" "<<i.y<<" "<<i.xx<<" "<<i.yy<<" "<<i.c<<'\n';
            a[1][1]+=i.c;
            add(i.x,i.y,i.xx,i.yy,-i.c);
        }
        int mx=-1,x,y;
        for(int i=1;i<=h;i++)
        {
            for(int j=1;j<=w;j++)
            {
                // cerr<<a[i][j]<<' ';
                a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
                
                if(a[i][j]>mx)
                {
                    mx=a[i][j];
                    x=i,y=j;
                }
            }
            // cout<<'\n';
        }
        // cerr<<mx<<'\n';
        if(mx&1) ans=(ans+1ull*mx*((mx-1)/2));
        else ans=(ans+1ull*(mx/2)*(mx-1));
        for(auto i:b)
        {
            if(i.x<=x&&x<=i.xx&&i.y<=y&&y<=i.yy)
            {
                c.push_back(i);
            }
        }
        b=c;
    }
    cout<<ans<<'\n';
}