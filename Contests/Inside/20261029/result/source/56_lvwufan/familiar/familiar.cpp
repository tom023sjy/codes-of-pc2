#include<bits/stdc++.h>
using namespace std;
int n,m,t,op,x,y,k;
int a[1010][1010];
int calx(int p,int l,int r,int k)
{
    int pos1=lower_bound(a[r]+1,a[r]+m+1,a[l][p])-a[r];
    int pos2=upper_bound(a[r]+1,a[r]+m+1,a[l][p])-a[r];
    int p1=(m-p+1)+(m-pos1+1),p2=(m-p+1)+(m-pos2+1);
    if(p2<=k&&k<=p1) return 1;
    else if(p2<k&&p1<k) return 2;
    else return 0;
}
int caly(int p,int l,int r,int k)
{
    int pos1=lower_bound(a[l]+1,a[l]+m+1,a[r][p])-a[l];
    int pos2=upper_bound(a[l]+1,a[l]+m+1,a[r][p])-a[l];
    int p1=(m-p+1)+(m-pos1+1),p2=(m-p+1)+(m-pos2+1);
    if(p2<=k&&k<=p1) return 1;
    else if(p2<k&&p1<k) return 2;
    else return 0;
}
int main()
{
    freopen("familiar.in","r",stdin);
    freopen("familiar.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m>>t;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++) cin>>a[i][j];
    }
    while(t--)
    {
        cin>>op;
        if(op==1)
        {
            cin>>x>>y>>k;
            bool tick=0;
            int l=0,r=m,mid;
            while(l+1<r)
            {
                mid=(l+r)/2;
                int res=calx(mid,x,y,k);
                if(res==2) r=mid;
                else if(res==0) l=mid;
                else
                {
                    cout<<a[x][mid]<<'\n';
                    tick=1;
                    break;
                }
            }
            if(!tick)
            {
                int res=calx(r,x,y,k);
                if(res==1)
                {
                    cout<<a[x][r]<<'\n';
                    tick=1;
                }
            }
            if(!tick)
            {
                l=0,r=m,mid;
                while(l+1<r)
                {
                    mid=(l+r)/2;
                    int res=caly(mid,x,y,k);
                    if(res==2) r=mid;
                    else if(res==0) l=mid;
                    else
                    {
                        cout<<a[y][mid]<<'\n';
                        tick=1;
                        break;
                    }
                }
                if(!tick)
                {
                    int res=caly(r,x,y,k);
                    if(res==1)
                    {
                        cout<<a[y][r]<<'\n';
                        tick=1;
                    }
                }
            }
        }
        else
        {
            cin>>x>>y;
            int p=upper_bound(a[x]+1,a[x]+m+1,y)-a[x]-1;
            a[x][p]=y;
        }
    }
}