#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD=1e9+7;
int n;
string xxkan;
int C[505][505];
void makeC()
{
    C[0][0]=1;
    C[1][0]=1,C[1][1]=1;
    for(int i=2;i<502;i++)
    {
        C[i][0]=1;
        for(int j=0;j<=i;j++)
        {
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
        }
    }
}
signed main()
{
    freopen("jump.in","r",stdin);
    freopen("jump.out","w",stdout);
    makeC();
    cin>>n;
    cin>>xxkan;
    xxkan=" "+xxkan;
    int cnt=0,st=1;
    for(int i=1;i<=n;i++)
    {
        if(xxkan[i]=='1') cnt++;
        if(cnt==1) st=i;
    }
    int en=st+cnt-1;
    if(cnt%2==0) cout<<C[n-cnt/2][cnt/2];
    else
    {
        int ans=0;
        for(int i=st;i<=en;i+=2)
        {
            ans+=(C[i-1-(i-st)/2][(i-st)/2]*C[n-i-(en-i)/2][(en-i)/2]-1)%MOD;
            ans%=MOD;
        }
        cout<<ans+1;
    }
    return 0;
}