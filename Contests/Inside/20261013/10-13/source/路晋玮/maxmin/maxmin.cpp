#include<iostream>
using namespace std;
const int N=5e5+5;
int a[N],b[N],ans[N];
int n;
bool f[305][305][305];
bool check()
{
    for(int i=1;i<=n;i++)
        if(a[i]!=b[i])
            return 0;
    return 1;
}
int main()
{
    freopen("maxmin.in","r",stdin);
    freopen("maxmin.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>b[i];
    if(check())
    {
        cout<<n<<" ";
        for(int i=2;i<=n;i++)
            cout<<"0 ";
        return 0;
    }
    f[1][a[1]][b[1]]=1;
    for(int i=1;i<n;i++)
        for(int x=1;x<=n;x++)
            for(int y=1;y<=n;y++)
            {
                f[i+1][max(x,a[i+1])][max(y,b[i+1])]|=f[i][x][y];
                f[i+1][min(x,a[i+1])][min(y,b[i+1])]|=f[i][x][y];
            }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            ans[abs(i-j)]+=f[n][i][j];
    for(int i=0;i<n;i++)
        cout<<ans[i]<<" ";
    return 0;
}