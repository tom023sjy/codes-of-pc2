#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mx=20;
int h[mx];
int pl[mx];
int vis[mx];
vector<int> ans;
int n;
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
int hh[mx];
int qmax[mx],hmax[mx];
map<int,int> mp;
void getans()
{
    for(int i=1;i<=n;i++) hh[i]=h[pl[i]];
    int sum=0;
    for(int i=1;i<=n;i++) qmax[i]=max(qmax[i-1],hh[i]);
    for(int i=n;i>=1;i--) hmax[i]=max(hh[i],hmax[i+1]);
    for(int i=1;i<=n;i++) sum+=min(qmax[i],hmax[i])-hh[i];
    if(!mp[sum])
    ans.push_back(sum);
    mp[sum]=1;
}
void dfs(int k)
{
    if(k==n) 
    {
        getans();
        return ;
    }
    for(int i=1;i<=n;i++)

    {
        if(!vis[i]) pl[k+1]=i,vis[i]=1,dfs(k+1),vis[i]=0;
    }
}
signed main()
{
    freopen("cup.in","r",stdin);
    freopen("cup.out","w",stdout);
    n=fread();
    for(int i=1;i<=n;i++) h[i]=fread();
    dfs(0);
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<' ';
    return 0;
}