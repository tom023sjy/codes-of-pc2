#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6+10;
int cid,q;
int b[N],c[N],a[N];
int k;
int lowbit(int x){
    return x&-x;
}
void add(int d[],int x,int v){
    for(;x<=1000000;x+=lowbit(x))d[x]+=v;
}
int query(int d[],int x){
    int res = 0;
    for(;x;x-=lowbit(x))res+=d[x];
    return res;
}
signed main(){
    freopen("name.in","r",stdin);
    freopen("name.out","w",stdout);
    cin>>cid>>q;
    while(q--){
        int op;
        cin>>op;
        if(op==1){
            int x,y;
            cin>>x>>y;
            add(b,x,(y-a[x])*x);
            add(c,x,(y-a[x]));
            a[x] = y;
        }
        if(op==2){
            
            cin>>k;
            int l = 1,r = 1000000,ans = 0;
            while(l<=r){
                int mid = (l+r)>>1;
                if(query(c,mid)>=k)ans = mid,r = mid-1;
                else l = mid+1;
            }
            int tmp = query(b,ans);
            tmp-=ans*(query(c,ans)-k);
            cout<<tmp-k+1<<"\n";
        }
    }




    return 0;
}