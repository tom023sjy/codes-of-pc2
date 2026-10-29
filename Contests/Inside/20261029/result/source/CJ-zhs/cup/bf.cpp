#include <algorithm>
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

const int N=510;

int n,h[N];
set<int> s;

int main(){
    freopen("cup.in","r",stdin);
    freopen("cup.ans","w",stdout);
    n=rdi();
    for(int i=1;i<=n;i++) h[i]=rdi();
    sort(h+1,h+n+1);
    do{
        int sum=0;
        for(int i=1;i<=n;i++){
            int mx=0;
            for(int j=1;j<i;j++)
                for(int k=i+1;k<=n;k++)
                    mx=max(mx,min(h[j],h[k]));
            if(mx>=h[i]) sum+=mx-h[i];
        }
        s.insert(sum);
    }while(next_permutation(h+1,h+n+1));
    for(auto x:s) cout<<x<<' ';
    return 0;
}