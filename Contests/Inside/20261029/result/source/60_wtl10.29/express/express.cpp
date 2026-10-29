#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6+10;
inline int ls(int x){
    return x<<1;
}
inline int rs(int x){
    return x<<1|1;
}
int n;
int c[N];
int pos[N];
int tmp[N];
struct node{
    int l,r,num1,num2,tag;
}a[4*N];
void push_up(int x){
    a[x].num1 = min(a[ls(x)].num1,a[rs(x)].num1);
    a[x].num2 = min(a[ls(x)].num2,a[rs(x)].num2);
}
void push_down(int x){
    if(a[x].tag){
        a[ls(x)].num1+=a[x].tag;
        a[rs(x)].num1+=a[x].tag;
        a[ls(x)].num2+=a[x].tag;
        a[rs(x)].num2+=a[x].tag;
        a[ls(x)].tag+=a[x].tag;
        a[rs(x)].tag+=a[x].tag;
        a[x].tag = 0;
    }
}
void build(int x,int l,int r){
    a[x].l = l,a[x].r = r;
    if(l==r){
        a[x].num1 = a[x].num2 = 1e18;
        return;
    }
    int mid = (l+r)>>1;
    build(ls(x),l,mid);
    build(rs(x),mid+1,r);
    push_up(x);
}
void update(int x,int l,int r,int v){
    if(l>r)return;
    if(l<=a[x].l&&a[x].r<=r){
        a[x].num1+=v;
        a[x].num2+=v;
        a[x].tag+=v;
        return;
    }
    push_down(x);
    int mid = (a[x].l+a[x].r)>>1;
    if(l<=mid)update(ls(x),l,r,v);
    if(r>mid)update(rs(x),l,r,v);
    push_up(x);
}
void modify(int x,int pos,int v){
    if(pos<=a[x].l&&a[x].r<=pos){
        a[x].num1 = v-tmp[pos];
        a[x].num2 = v+tmp[pos];
        return;
    }
    push_down(x);
    int mid = (a[x].l+a[x].r)>>1;
    if(pos<=mid)modify(ls(x),pos,v);
    else modify(rs(x),pos,v);
    push_up(x);
}

int query1(int x,int l,int r){
    if(l>r)return 1e18;
    if(l<=a[x].l&&a[x].r<=r){
        return a[x].num1;
    }
    push_down(x);
    int mid = (a[x].l+a[x].r)>>1;
    int res = 1e18;
    if(l<=mid)res = min(res,query1(ls(x),l,r));
    if(r>mid)res = min(res,query1(rs(x),l,r));
    return res;
}
int query2(int x,int l,int r){
    if(l>r)return 1e18;
    if(l<=a[x].l&&a[x].r<=r){
        return a[x].num2;
    }
    push_down(x);
    int mid = (a[x].l+a[x].r)>>1;
    int res = 1e18;
    if(l<=mid)res = min(res,query2(ls(x),l,r));
    if(r>mid)res = min(res,query2(rs(x),l,r));
    return res;
}
signed main(){
    freopen("express.in","r",stdin);
    freopen("express.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i = 1;i<=n;i++)cin>>c[i],tmp[i] = c[i];
    tmp[n+1] = 0;
    sort(tmp+1,tmp+n+2);
    int m = unique(tmp+1,tmp+n+2)-tmp-1;
    build(1,1,m);
    for(int i = 1;i<=n;i++){
        pos[i] = lower_bound(tmp+1,tmp+m+1,c[i])-tmp;
    }
    modify(1,1,0);
    for(int i = 1;i<=n;i++){
        int v = min(c[i]+query1(1,1,pos[i]),-c[i]+query2(1,pos[i]+1,m));
        update(1,1,m,abs(c[i]-c[i-1]));
        modify(1,pos[i-1],v);
    }
    int ans = 1e18;
    for(int i = 1;i<=m;i++){
        int r = query1(1,i,i)+tmp[i];
        ans = min(ans,r);
    }
    cout<<ans;
    return 0;
}