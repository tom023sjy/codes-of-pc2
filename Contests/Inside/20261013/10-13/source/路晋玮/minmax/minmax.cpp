#include<iostream>
using namespace std;
const int N=1e5+5;
int a[N],b[N];
int read()
{
    int x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9')
        ch=getchar();
    while(ch>='0'&&ch<='9')
    {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x;
}
int main()
{
    freopen("minmax.in","r",stdin);
    freopen("minmax.out","w",stdout);
    int T,n,m,flag;
    T=read();
    while(T--)
    {
        n=read();m=read();
        for(int i=1;i<=n;i++)
            a[i]=read();
        for(int i=1;i<=m;i++)
            b[i]=read();
        if(n<m)
        {
            cout<<"No\n";
            continue;
        }
        int j=1;
        flag=1;
        for(int i=1;i<=m;i++)
        {
            while(j<=n&&a[j]!=b[i])
                j++;
            if(j>n)
            {
                flag=0;
                break;
            }
            j++;
        }
        if(flag==0)
            cout<<"No\n";
        else
            cout<<"Yes\n";
    }
    return 0;
}