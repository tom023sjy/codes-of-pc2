#include <bits/stdc++.h>
using namespace std;
long long f[1000005];
int k[1000005];
long long s[1000005];
long long pre[1000005];
long long suf[1000005];
int n;
inline void add(int x,long long t)
{
    if(x==0) x=1;
    for(;x<=n;x+=x&-x) pre[x]=min(pre[x],t);
}
inline void addd(int x,long long t)
{
    if(x==0) x=1;
    for(;x<=n;x+=x&-x) suf[x]=min(suf[x],t);
}
inline long long query_pre(int x)
{
    long long ans=1e18;
    for(;x;x-=x&-x) ans=min(ans,pre[x]);
    return ans;
}
inline long long query_suf(int x)
{
    long long ans=1e18;
    for(;x;x-=x&-x) ans=min(ans,suf[x]);
    return ans;
}
int main()
{
    freopen("express.in","r",stdin);
    freopen("express.out","w",stdout);
    memset(f,0x3f,sizeof(f));
    memset(pre,0x3f,sizeof(pre));
    memset(suf,0x3f,sizeof(suf));
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    vector<int> nums;
    nums.push_back(0);
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        nums.push_back(k[i]);
        s[i]=s[i-1]+(abs(k[i]-k[i-1]));
    }
    sort(nums.begin(),nums.end());
    for(int i=1;i<=n;i++)
    {
        k[i]=lower_bound(nums.begin(),nums.end(),k[i])-nums.begin();
        // cout<<k[i]<<'\n';
    }
    f[0]=0;
    f[1]=nums[k[1]];
    add(k[0],f[1]-s[1]-nums[k[0]]);
    add(n-k[0]+1,f[1]-s[1]+nums[k[0]]);
    for(int i=2;i<=n;i++)
    {
        f[i]=min(f[i],query_pre(k[i])+nums[k[i]]);
        // cout<<f[i]<<' ';
        f[i]=min(f[i],query_suf(n-k[i]+1)-nums[k[i]]);
        // cout<<f[i]<<'\n';
        // for(int j=0;j<=i;j++)
        // {
            // f[i]=min(f[i],f[j]+s[i-1]-s[j]+abs(k[i]-k[j-1]));
            
            // f[i]=min(f[i],f[j]-s[j]+abs(nums[k[i]]-nums[k[j-1]]));
        // }
        f[i]+=s[i-1];
        add(k[i-1],f[i]-s[i]-nums[k[i-1]]);
        addd(n-k[i-1]+1,f[i]-s[i]+nums[k[i-1]]);
    }
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<n;j++)
    //     {
    //         f[i+1][j]=min(f[i+1][j],f[i][j]+abs(k[i+1]-k[i]));
    //         f[i+1][i]=min(f[i+1][i],f[i][j]+abs(k[i+1]-k[j]));
    //     }
    // }
    long long ans=1e18;
    for(int i=0;i<=n;i++)
    {
        // cout<<f[i]<<'\n';
        ans=min(ans,f[i]+s[n]-s[i]);
    }
    cout<<ans;
}