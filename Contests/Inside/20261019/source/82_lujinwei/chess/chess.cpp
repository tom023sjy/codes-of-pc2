#include<iostream>
#include<cstring>
using namespace std;
#define ull unsigned long long
struct node
{
    int x1,y1,x2,y2;
    ull c;
}a[100005];
ull ans;
long long mp[5005][5005],sum[5005][5005],ans1;
int n,h,w,vis[100005];
void calc()
{
    ull res=0;
    for(int i=1;i<=h;i++)
        for(int j=1;j<=w;j++)
            res+=(mp[i][j])*(mp[i][j]-1)/2;
    ans=max(ans,res);
    return ;
}
void dfs(int k)
{
    if(k>n)
    {
        calc();
        return ;
    }
    for(int i=1;i<=h;i++)
        for(int j=1;j<=w;j++)
        {
            if(i>=a[k].x1&&i<=a[k].x2&&j>=a[k].y1&&j<=a[k].y2)
                continue;
            mp[i][j]+=a[k].c;
            dfs(k+1);
            mp[i][j]-=a[k].c;
        }
    return ;
}
void add()
{
    for(int i=1;i<=h;i++)
        for(int j=1;j<=w;j++)
            sum[i][j]+=sum[i][j-1];
    for(int i=1;i<=h;i++)
        for(int j=1;j<=w;j++)
            sum[i][j]+=sum[i-1][j];
    return ;
}
int main()
{
    freopen("chess.in","r",stdin);
    freopen("chess.out","w",stdout);
    int cid;
    cin>>cid>>n>>h>>w;
    for(int i=1;i<=n;i++)
        cin>>a[i].x1>>a[i].y1>>a[i].x2>>a[i].y2>>a[i].c;
    if(cid<=8)
    {
        dfs(1);
        cout<<ans;
        return 0;
    }
    if(cid<=10)
    {
        for(int i=1;i<=n;i++)
            ans+=a[i].c;
        ans=ans*(ans-1)/2;
        cout<<ans;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        sum[a[i].x1][a[i].y1]-=a[i].c;
        sum[a[i].x1][a[i].y2+1]+=a[i].c;
        sum[a[i].x2+1][a[i].y1]+=a[i].c;
        sum[a[i].x2+1][a[i].y2+1]-=a[i].c;
        ans1+=a[i].c;
    }
    add();
    int cx=1,cy=1;
    for(int i=1;i<=h;i++)
        for(int j=1;j<=w;j++)
            if(sum[i][j]>sum[cx][cy])
            {
                cx=i;
                cy=j;
            }
    ans1+=sum[cx][cy];
    ans+=(ans1-1)*ans1/2;
    while(sum[cx][cy]<0)
    {
        ans1=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i].x1>cx||a[i].y1>cy||a[i].x2<cx||a[i].y2<cy)
                vis[i]=1;
        }
        memset(sum,0,sizeof(sum));
        for(int i=1;i<=n;i++)
        {
            if(vis[i])
                continue;
            sum[a[i].x1][a[i].y1]-=a[i].c;
            sum[a[i].x1][a[i].y2+1]+=a[i].c;
            sum[a[i].x2+1][a[i].y1]+=a[i].c;
            sum[a[i].x2+1][a[i].y2+1]-=a[i].c;
            ans1+=a[i].c;
        }
        add();
        cx=1,cy=1;
        for(int i=1;i<=h;i++)
            for(int j=1;j<=w;j++)
                if(sum[i][j]>sum[cx][cy])
                {
                    cx=i;
                    cy=j;
                }
        ans1+=sum[cx][cy];
        ans+=(ans1-1)*ans1/2;
    }
    cout<<ans;
    return 0;
}