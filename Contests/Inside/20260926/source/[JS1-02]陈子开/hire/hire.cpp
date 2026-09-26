#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int num[N],room[N];

void solve() {
    int n,m,k,d;
    cin>>n>>m>>k>>d;
    int all=0;

    while(m--) {
        int x,y;
        cin>>x>>y;
        all+=y;
        num[x]-=y;
        if(all>n*k) {
            cout<<"NO\n";
            continue;
        }
        bool flag=true;
        for(int i=1;i<=n;i++) room[i]=k;
        for(int i=n-d;i>=1;i--) {
            int tmp=num[i];
            for(int j=i+d;j>=i;j--) {
                if(room[i]<tmp) {
                    tmp-=room[i];
                    room[i]=0;
                }
                else {
                    room[i]-=tmp;
                    break;
                }
            }
            if(tmp>0) {
                cout<<"NO\n";
                flag=false;
                break;
            }
        }
        if(flag) {
            cout<<"YES\n";
        }
    }
    return ;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("hire.in","r",stdin);
    freopen("hire.out","w",stdout);
    solve();
    return 0;
}