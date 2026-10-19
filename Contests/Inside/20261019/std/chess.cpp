#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,ll> pii;
#define fi first
#define se second

const int N = 1e5+10,M = 5010;

int cid,n,X,Y;
ll s1[M][M],s2[M][M];
int xl[N],xr[N],yl[N],yr[N],c[N];
ll ans;

ll get(ll x)
{
    return x*(x-1)/2;
}

void solve(int nx,int ny)
{
    ll sum=0;
    memset(s1,0,sizeof(s1));
    memset(s2,0,sizeof(s2));
    for(int i=1;i<=n;i++)
    {
        sum += c[i];
        s1[xl[i]][yl[i]] += c[i];
        s1[xr[i]+1][yl[i]] -= c[i];
        s1[xl[i]][yr[i]+1] -= c[i];
        s1[xr[i]+1][yr[i]+1] += c[i];
        if(xl[i] <= nx && nx <= xr[i] && yl[i] <= ny && ny <= yr[i])
        {
            s2[xl[i]][yl[i]] += c[i];
            s2[xr[i]+1][yl[i]] -= c[i];
            s2[xl[i]][yr[i]+1] -= c[i];
            s2[xr[i]+1][yr[i]+1] += c[i];
        }
    }
    for(int i=1;i<=X;i++) for(int j=1;j<=Y;j++) s1[i][j] += s1[i][j-1],s2[i][j] += s2[i][j-1];
    for(int i=1;i<=X;i++) for(int j=1;j<=Y;j++) s1[i][j] += s1[i-1][j],s2[i][j] += s2[i-1][j];

    for(int i=1;i<=X;i++) for(int j=1;j<=Y;j++) 
    {
        // cout << sum-s1[i][j] << ' ' << s2[i][j] << ' ' << s1[i][j]-s2[i][j] << '\n';
        ans = max(ans,get(sum-s1[i][j])+get(s2[i][j])+get(s1[i][j]-s2[i][j]));
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("chess.in","r",stdin);
    freopen("chess.out","w",stdout);
    cin >> cid >> n >> X >> Y;
    for(int i=1;i<=n;i++)
    {
        cin >> xl[i] >> yl[i] >> xr[i] >> yr[i] >> c[i];
    }
    solve(1,1);
    solve(1,Y);
    solve(X,1);
    solve(X,Y);
    cout << ans;
}