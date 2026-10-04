#include<bits/stdc++.h>

using namespace std;
const int N=1e7+5;
int n;
bool a[N];

void solve() {
    cin>>n;
    //前导0无意义
    int st1=-1;//是否全0并记录第一个1的位置
    int st0=-1;//是否全1并记录第一个0的位置
    int len1=-1,len0=-1;//记录长度
    bool has0=false;
    bool flag=false;
    for(int i=1;i<=n;i++) {
        char c;
        cin>>c;
        if(c=='0') {
            has0=true;
            a[i]=false;
            if(st1!=-1&&st0==-1) {
                st0=i;
                len1=i-st1;
                flag=true;//开始记录len0
            }
        }
        else {
            a[i]=true;
            if(flag) {
                flag=false;
                len0=i-st0;
            }
            if(st1==-1) {
                st1=i;
            }
        }
    }
    if(len0==-1&&st0!=-1) {
        len0=n+1-st0;
    }
    if(st1==-1) {
        cout<<0<<'\n';
        return ;
    }
    if(st0==-1) {
        if(has0) {
            for(int i=st1;i<=n;i++) {
                cout<<1;
            }
            cout<<'\n';
            return ;
        }
        for(int i=st1;i<n;i++) {
            cout<<1;
        }
        cout<<0<<'\n';
        return ;
    }
    int d=min(len1,len0);
    for(int i=st1;i<=n;i++) {
        if(i<st0) {
            cout<<1;
            continue;
        }
        cout<<((a[i]==a[i-d])?0:1);
    }
    cout<<'\n';
    return ;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int T;
    cin>>T;
    while(T--) {
        solve();
    }
    return 0;
}