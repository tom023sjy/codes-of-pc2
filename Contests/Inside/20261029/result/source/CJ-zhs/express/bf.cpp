#include <bits/stdc++.h>

using namespace std;

using i64=long long;
using u64=unsigned long long;
using db=double;
using pii=pair<int,int>;
using vi=vector<int>;

template<typename T>
inline T read(){
    T x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=x*10+(ch-'0'),ch=getchar();
    return f?-x:x;
}

#define rdi read<int>
#define rdi64 read<i64>
#define fi first
#define se second
#define pb push_back

const int N=1e6+10;
const i64 INFl=0x3f3f3f3f3f3f3f3f;

int n,p[N];
i64 ans;

int pos[2];
void dfs(int x,i64 sum=0){
    if(x>n) {ans=min(ans,sum);return;}
    for(int i=0;i<2;i++){
        sum+=abs(pos[i]-p[x]),swap(pos[i],p[x]);
        dfs(x+1,sum);
        swap(pos[i],p[x]),sum-=abs(pos[i]-p[x]);
    }
}

int main(){
    freopen("express.in","r",stdin);
    freopen("express.ans","w",stdout);
    n=rdi();
    for(int i=1;i<=n;i++) p[i]=rdi();
    ans=1e18;dfs(1);
    cout<<ans<<endl;
    return 0;
}