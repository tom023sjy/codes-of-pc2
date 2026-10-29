#include<iostream>
using namespace std;
const int N=1005;
int a[N][N],n,m;
int calc(int x,int y)
{
    int l=1,r=m,mid,pos=m+1;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(a[x][mid]>=y)
        {
            pos=mid;
            r=mid-1;
        }
        else
            l=mid+1;
    }
    return m-pos+1;
}
int main()
{
    freopen("familiar.in","r",stdin);
    freopen("familiar.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int q,op,x,y,k,l,r,mid,ans;
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>a[i][j];
    for(int i=1;i<=q;i++)
    {
        cin>>op;
        if(op==1)
        {
            cin>>x>>y>>k;
            l=1,r=m,ans=-1;
            while(l<=r)
            {
                mid=(l+r)/2;
                int cnt=m-mid+1+calc(y,a[x][mid]);
                if(cnt==k)
                {
                    ans=a[x][mid];
                    break;
                }
                if(cnt<k)
                    r=mid-1;
                else
                    l=mid+1;
            }
            if(ans!=-1)
            {
                cout<<ans<<"\n";
                continue;
            }
            l=1,r=m;
            while(l<=r)
            {
                mid=(l+r)/2;
                int cnt=m-mid+1+calc(x,a[y][mid]);
                //cout<<mid<<" "<<a[y][mid]<<" "<<cnt<<"\n";
                if(cnt<k)
                    r=mid-1;
                else
                {
                    ans=a[y][mid];
                    l=mid+1;
                }
                    
            }
            cout<<ans<<"\n";
        }
        else
        {
            cin>>x>>y;
            int p=m-calc(x,y+1);
            if(p)
                a[x][p]=y;
        }
    }
    return 0;
}