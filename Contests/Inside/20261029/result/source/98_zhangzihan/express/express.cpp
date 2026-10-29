#include <iostream>
#include <algorithm>
#include <cstring>
#define int long long
/*#define lc(t) t*2;
#define rc(t) t*2+1*/

using namespace std;
const int N=1e6+5,MX=1e15;
int v1[N],v2[N];
int p[N],n,top,s[N];
int l,r,V,tag[N];
int lc(int t)
{
    return t*2;
}
int rc(int t)
{
    return t*2+1;
}
void push_down(int x,int y,int t)
{
    if(tag[t]==0)return ;
    int mid=(x+y)/2;
    v1[lc(t)]+=tag[t];
    v1[rc(t)]+=tag[t];
    v2[lc(t)]+=tag[t];
    v2[rc(t)]+=tag[t];
    tag[lc(t)]+=tag[t];
    tag[rc(t)]+=tag[t];
    tag[t]=0;
}
void add(int x,int y,int t,int op)
{
    int mid=(x+y)/2;
    if(l<=x&&y<=r)
    {
        if(op==1)
        {
            v1[t]+=V;
            v2[t]+=V;
            tag[t]+=V;

        }
        else
        {
            v1[t]=min(v1[t],V-s[x]);
            v2[t]=min(v2[t],V+s[x]);
        }
        return ;
    }
    push_down(x,y,t);
    if(l<=mid)add(x,mid,lc(t),op);
    if(r>mid)add(mid+1,y,rc(t),op);
    v1[t]=min(v1[lc(t)],v1[rc(t)]);
    v2[t]=min(v2[lc(t)],v2[rc(t)]);
    return ;
}
int ask(int x,int y,int t,int op)
{
    int mid=(x+y)/2;
    if(l<=x&&y<=r)
    {
        if(op==1)return v1[t];
        return v2[t];
    }
    int cnt=MX;
    push_down(x,y,t);
    if(l<=mid)cnt=min(cnt,ask(x,mid,lc(t),op));
    if(r>mid)cnt=min(cnt,ask(mid+1,y,rc(t),op));
    return cnt;
}
int ANS=MX;
void ans(int x,int y,int t)
{
    if(x==y)
    {
        ANS=min(ANS,v1[t]+s[x]);
        return ;
    }
    int mid=(x+y)/2;
    push_down(x,y,t);
    ans(x,mid,lc(t));
    ans(mid+1,y,rc(t));
}
/*void pt(int x,int y,int t)
{
    if(x==y)
    {
        cout<<x<<" "<<v1[t]<<" "<<v2[t]<<endl;
        return ;
    }
    int mid=(x+y)/2;
    //push_down(x,y,t);
    pt(x,mid,lc(t));
    pt(mid+1,y,rc(t));
    return ;
}*/
//int fd(int x,int ,int v)
signed main()
{
    freopen("express.in","r",stdin);
    freopen("express.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&p[i]);
        s[i]=p[i];
    }
    s[n+1]=0;
    sort(s+1,s+1+n+1);
    top=n+1;
    memset(v1,0x3f,sizeof(v1));
    memset(v2,0x3f,sizeof(v2));
    //cout<<v1[1]<<endl;
    l=1;
    r=1;
    V=0;
       // pt(1,top,1);
    //return 0;
    add(1,top,1,0);//1 + 0tui
    //return 0;
    for(int i=1;i<=n;i++)
    {
        //cout<<i<<endl;
        //pt(1,top,1);
        //cout<<endl;
        int P=(lower_bound(s+1,s+1+n+1,p[i])-s);
        //cout<<P<<endl;
       // cout<<;
        int cnt=MX;
        l=1;
        r=P-1;
        if(l<=r)cnt=ask(1,top,1,1)+p[i];
        l=P;
        r=n+1;
        if(l<=r)cnt=min(cnt,ask(1,top,1,2)-p[i]);
        l=1;
        r=top;
        V=max(p[i]-p[i-1],p[i-1]-p[i]);
        add(1,top,1,1);
        P=lower_bound(s+1,s+1+n+1,p[i-1])-s;
        V=cnt;
        l=P;
        r=P;
        add(1,top,1,0);
        //return 0;
    }
    ans(1,top,1);
    printf("%lld",ANS);
    return 0;
}
/*
cd 10-29-down
cd down
cd familiar
g++ a.cpp -o a -std=c++14
*/