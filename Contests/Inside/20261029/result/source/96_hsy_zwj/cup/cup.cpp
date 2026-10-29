#include <bits/stdc++.h>
using namespace std;

const int N = 2010,K = 60;
bool st;

int n,cnt[K],sum[K];
bitset<100000> f[N];

bool ed;
int main()
{
    cerr << (&st-&ed)*1.0/1024/1024 << " MB\n";
    freopen("cup.in","r",stdin);
    freopen("cup.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for(int i=1,x;i<=n;i++)
    {
        cin >> x;
        cnt[x]++;
    }
    sum[50] = cnt[50];
    for(int i=49;i>=1;i--)
    {
        sum[i] = sum[i+1] + cnt[i];
    }
    f[n][0] = 1;
    bitset<100000> ans;
    for(int i=2;i<=51;i++)
    {
        if(cnt[i-1])
        {
            for(int j=n-1;j>=sum[i];j--)
            {
                f[j] |= f[j+1];
            }
        }
        if(sum[i] <= 1) {ans = f[sum[i]];break;}
        for(int j=sum[i];j<=n;j++)
        {
            f[j] <<= j-sum[i];
        }
    }
    for(int i=0;i<100000;i++)
    {
        if(ans[i]) cout << i << ' ';
    }
}
