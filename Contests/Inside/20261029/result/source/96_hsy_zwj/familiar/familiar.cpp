#include <bits/stdc++.h>
using namespace std;

const int N = 1010;

int n,m,T;
int a[N][N];

int query(int x,int y,int k)
{
    // vector<int> X;
    // for(int i=1;i<=m;i++) X.push_back(a[x][i]),X.push_back(a[y][i]);
    // sort(X.begin(),X.end(),greater<int>());
    // return X[k-1];
    int ret=1e9,rk=1e9;
    int l=max(m-k+1,1),r=m;
    while(l <= r)
    {
        int mid = (l+r)>>1;
        int pos = lower_bound(a[y]+1,a[y]+m+1,a[x][mid]) - a[y];
        pos = m-pos+1;
        if(pos+m-mid+1 >= k)
        {
            if(rk > pos+m-mid+1) ret=a[x][mid],rk=pos+m-mid+1;
            l = mid+1;
        }
        else
        {
            r = mid-1;
        }
    }
    l=max(m-k+1,1),r=m;
    while(l <= r)
    {
        int mid = (l+r)>>1;
        int pos = lower_bound(a[x]+1,a[x]+m+1,a[y][mid]) - a[x];
        pos = m-pos+1;
        if(pos+m-mid+1 >= k)
        {
            if(rk > pos+m-mid+1) ret=a[y][mid],rk=pos+m-mid+1;
            l = mid+1;
        }
        else
        {
            r = mid-1;
        }
    }
    return ret;
}

int main()
{
    freopen("familiar.in","r",stdin);
    freopen("familiar.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    auto X = chrono::steady_clock::now().time_since_epoch().count();
    cin >> n >> m >> T;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin >> a[i][j];
        }
    }
    int op,x,y,k;
    while(T--)
    {
        cin >> op;
        if(op == 1)
        {
            cin >> x >> y >> k;
            cout << query(x,y,k) << '\n';
        }
        else
        {
            cin >> x >> y;
            int pos = upper_bound(a[x]+1,a[x]+m+1,y) - a[x] - 1;
            if(pos) a[x][pos] = y;
        }
    }
    cerr << (chrono::steady_clock::now().time_since_epoch().count()-X)*1.0/1e6 << " ms\n";
}