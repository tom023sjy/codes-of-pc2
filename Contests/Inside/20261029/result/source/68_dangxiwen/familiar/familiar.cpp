#include<bits/stdc++.h>
using namespace std;
const int mx=1100;
int a[mx][mx];
int n,m;
int fread()
{
    int x=0,w=1;char ch=getchar();
    while(ch<'0'||ch>'9') w=ch=='-'?-1:1,ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*w;
}
void fwrite(int x)
{
    if(x>=10) fwrite(x/10);
    putchar(x%10+'0');
    return ;
}
int che(int mid,int k,int x,int y)
{
    int xx=a[x][m-mid+1];
    int yy=a[y][m-k+mid+1];
    int yyy=a[y][m-k+mid];
    if(yyy<=xx&&xx<=yy) return 0;
    if(xx>yy) return 1;
    return -1;
}
int main()
{
    freopen("familiar.in","r",stdin);
    freopen("familiar.out","w",stdout);
    n=fread(),m=fread();
    int T=fread();
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) a[i][j]=fread();
    for(int i=1;i<=n;i++) a[i][m+1]=2e9;
    // cout<<"DEBUG\n";
    while(T--)
    {
        int opt=fread();
        if(opt==1)
        {
            int x=fread(),y=fread(),k=fread();
            int l=1,r=min(k,m);
            int ans=-1;
            while(l<=r)
            {
                int mid=l+r>>1;
                if(che(mid,k,x,y)>0) l=mid+1;
                else if(che(mid,k,x,y)<0) r=mid-1;
                else 
                {
                    ans=mid;break;
                } 
            }
            if(ans!=-1)
            {
                fwrite(a[x][m-ans+1]);
                putchar('\n');
                continue;
            }
            l=0,r=min(k,m);
            while(l<=r)
            {
                int mid=l+r>>1;
                if(che(mid,k,y,x)>0) l=mid+1;
                else if(che(mid,k,y,x)<0) r=mid-1;
                else 
                {
                    ans=mid;break;
                }
            }
            fwrite(a[y][m-ans+1]);
            putchar('\n');
        }
        else
        {
            int x=fread(),y=fread();
            int l=1,r=m,pos=0;
            while(l<=r)
            {
                int mid=l+r>>1;
                if(a[x][mid]<=y) pos=mid,l=mid+1;
                else r=mid-1;
            }
            if(pos!=0) a[x][pos]=y;
        }
    }
    return 0;
}