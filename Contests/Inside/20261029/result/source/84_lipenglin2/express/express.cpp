#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ill __int128
#define ld long double
#define lc(k) st[k].lc
#define rc(k) st[k].rc
#define mids (nl+nr)>>1
#define hh putchar(10);
#define LLM (ll)1e18
#define IM (int)1e9
#define mp(x,y) make_pair(x,y)
#define Re(x) qpow(x,mod-2)
const int N=1e6+50;
template<class T>
inline T read(){
    T x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+(ch-'0');
        ch=getchar();
    }
    return x*f;
}
template<class T>
inline void write(T ans){
    if(ans<0){putchar('-');write<T>(-ans);}
    else if(ans<10) putchar(ans+'0');
    else{write<T>(ans/10);putchar(ans%10+'0');}
    return ;
}
vector<int> id;
int a[N],ta[N],n;
struct node{ll min1,min2,lazy;}st[4*N];
ll ans=LLM;
void up(int k){return st[k].min1=min(st[2*k].min1,st[2*k+1].min1),st[k].min2=min(st[2*k].min2,st[2*k+1].min2),void();}
void down(int k){
    if(st[k].lazy==0) return ;
    st[2*k].lazy+=st[k].lazy,st[2*k].min1+=st[k].lazy,st[2*k].min2+=st[k].lazy;
    st[2*k+1].lazy+=st[k].lazy,st[2*k+1].min1+=st[k].lazy,st[2*k+1].min2+=st[k].lazy;
    return st[k].lazy=0,void();
}
void build(int k,int nl,int nr){
    st[k].min1=st[k].min2=LLM,st[k].lazy=0;
    if(nl==nr) return ;
    int mid=mids;
    build(2*k,nl,mid);build(2*k+1,mid+1,nr);
    return ;
}
ll ask_min(int k,int l,int r,int tp,int nl,int nr){
    if(r<nl||nr<l||l>r||nl>nr) return LLM;
    //cout<<l<<" "<<r<<" "<<tp<<" "<<nl<<" "<<nr<<endl;
    if(l<=nl&&nr<=r) return (tp==1?st[k].min1:st[k].min2);
    down(k);int mid=mids;
    return min(ask_min(2*k,l,r,tp,nl,mid),ask_min(2*k+1,l,r,tp,mid+1,nr));
}
void add(int k,int l,int r,ll d,int nl,int nr){
    if(r<nl||nr<l||l>r||nl>nr) return ;
    if(l<=nl&&nr<=r) return st[k].min1+=d,st[k].min2+=d,st[k].lazy+=d,void();
    down(k);int mid=mids;
    add(2*k,l,r,d,nl,mid);add(2*k+1,l,r,d,mid+1,nr);
    return up(k),void();
}
void update(int k,int x,ll d,int nl,int nr){
    if(x<nl||x>nr) return ;
    if(nl==nr) return st[k].min1=min(st[k].min1,d-id[x-1]),st[k].min2=min(st[k].min2,d+id[x-1]),void();
    down(k);int mid=mids;
    update(2*k,x,d,nl,mid);update(2*k+1,x,d,mid+1,nr);
    //up(k);cout<<"["<<nl<<","<<nr<<"]"<<" "<<st[k].min1<<" "<<st[2*k].min1<<" "<<st[2*k+1].min1<<endl;
    return up(k),void();
}
void getans(int k,int nl,int nr){
    if(nl==nr)
        //cout<<nl<<":"<<st[k].min1+id[nl-1]<<endl;
        return ans=min(ans,st[k].min1+id[nl-1]),void();
    down(k);int mid=mids;
    getans(2*k,nl,mid);getans(2*k+1,mid+1,nr);
    return ;
}
void print(int k,int nl,int nr){
    cout<<" ["<<nl<<","<<nr<<"] "<<st[k].min1<<" "<<st[k].min2<<" "<<st[k].lazy<<endl;
    if(nl==nr) return ;
    int mid=mids;
    print(2*k,nl,mid);print(2*k+1,mid+1,nr);
    return ;
}

int main(){
    freopen("express.in","r",stdin);
    freopen("express.out","w",stdout);
    n=read<int>();
    for(int i=2;i<=n+1;i++){a[i]=read<int>()+1;id.push_back(a[i]);}
    a[1]=1;n++;id.push_back(1);
    sort(id.begin(),id.end());
    id.erase(unique(id.begin(),id.end()),id.end());
    for(int i=1;i<=n;i++) ta[i]=lower_bound(id.begin(),id.end(),a[i])-id.begin()+1;
    //for(int i=1;i<=n;i++) cout<<ta[i]<<" ";cout<<endl;
    int mn=id.size();
    build(1,1,mn);update(1,ta[1],abs(a[2]-a[1]),1,mn);
    //cout<<2<<":"<<endl;print(1,1,mn);
    for(int i=3;i<=n;i++){
        ll newdp=min(ask_min(1,1,ta[i],1,1,mn)+a[i],ask_min(1,ta[i]+1,mn,2,1,mn)-a[i]);
        add(1,1,mn,abs(a[i]-a[i-1]),1,mn);
        update(1,ta[i-1],newdp,1,mn);
        //cout<<i<<":"<<endl;print(1,1,mn);
        //cout<<newdp<<endl;
    }
    getans(1,1,mn);
    write<ll>(ans);hh
    return 0;
    // for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dp[i][j]=LLM;
    // dp[2][1]=abs(a[2]-a[1]);
    // for(int i=2;i<n;i++){
    //     for(int j=1;j<i;j++){
    //         dp[i+1][j]=min(dp[i+1][j],dp[i][j]+abs(a[i+1]-a[i]));
    //         dp[i+1][i]=min(dp[i+1][i],dp[i][j]+abs(a[i+1]-a[j]));
    //     }
    // }
    // ll ans=LLM;
    // for(int j=1;j<n;j++) ans=min(ans,dp[n][j]);
}
/*
g++ express.cpp -o E -O2 -std=c++14 -Wall
./E
time ./E

*/