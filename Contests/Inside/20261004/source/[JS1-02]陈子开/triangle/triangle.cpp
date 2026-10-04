#include<bits/stdc++.h>

using namespace std;
const int N=15;
const int INF=0x3f3f3f3f;
int n;
int a[N][N];
int b[N][N];
int tmp[N][N];
int ans=INF;

void op1() {//旋转
    for(int j=n,ni=1;j>=1;j--,ni++) {
        for(int i=n,nj=ni;i>=j;i--,nj--) {
            tmp[ni][nj]=a[i][j];
        }
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            a[i][j]=tmp[i][j];
        }
    }
    return ;
}

void op2() {//对称
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=i/2;j++) {
            swap(a[i][j],a[i][i-j+1]);
        }
    }
    return ;
}

void check() {
    int cnt=0;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=i;j++) {
            if(a[i][j]!=b[i][j]) {
                cnt++;
            }
        }
    }
    ans=min(ans,cnt);
    return ;
}

void solve() {
    cin>>n;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=i;j++) {
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=i;j++) {
            cin>>b[i][j];
        }
    }
    for(int i=1;i<=3;i++) {
        op1();
        check();
        op2();
        check();
        op2();
    }
    cout<<ans;
    return ;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("triangle.in","r",stdin);
    freopen("triangle.out","w",stdout);
    solve();
    return 0;
}