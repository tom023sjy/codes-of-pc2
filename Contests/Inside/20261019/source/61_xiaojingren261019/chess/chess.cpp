#include<bits/stdc++.h>
using namespace std;
#define int long long
int tc,n,h,w,a[5005][5005],nans;
struct pp
{
    int c,xa,ya,xb,yb;
};
pp now;
vector<pp> v,tmp;
signed main()
{
    freopen("chess.in","r",stdin);
    freopen("chess.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>tc>>n>>h>>w;
    for(int i = 1; i <= n; i++)
    {
        cin>>now.xa>>now.ya>>now.xb>>now.yb>>now.c;
        v.push_back(now);
    }
    while(!v.empty())
    {
        for(int i = 0; i <= h; i++)
        {
            for(int j = 0; j <= w; j++)
            {
                a[i][j]=0;
            }
        }
        int nsu=0,mxposx=0,mxposy=0;
        for(int i = 0; i < v.size(); i++)
        {
            a[v[i].xa][v[i].ya]+=v[i].c;
            a[v[i].xa][v[i].yb+1]-=v[i].c;
            a[v[i].xb+1][v[i].ya]-=v[i].c;
            a[v[i].xb+1][v[i].yb+1]+=v[i].c;
            nsu+=v[i].c;
        }
        for(int i = 1; i <= h; i++)
        {
            for(int j = 1; j <= w; j++)
            {
                a[i][j]=a[i][j]+a[i-1][j]+a[i][j-1]-a[i-1][j-1];
            }
        }
        for(int i = 1; i <= h; i++)
        {
            for(int j = 1; j <= w; j++)
            {
                a[i][j]=nsu-a[i][j];
                if(a[i][j]>a[mxposx][mxposy])
                {
                    mxposx=i;
                    mxposy=j;
                }
            }
        }
        cout<<a[mxposx][mxposy]<<'\n';
        nans+=a[mxposx][mxposy]*(a[mxposx][mxposy]-1)/2;
        tmp.clear();
        for(int i = 0; i < v.size(); i++)
        {
            if(v[i].xa<=mxposx&&v[i].xb>=mxposx&&v[i].ya<=mxposy&&v[i].yb>=mxposy) tmp.push_back(v[i]);
        }
        v=tmp;
    }
    cout<<nans<<'\n';
}