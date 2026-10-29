#include<bits/stdc++.h>
#define int __int128
using namespace std;
int fread()
{
    int x=0,w=1;char ch=getchar();
    while(ch<'0'||ch>'9') w=ch=='-'?-1:1,ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*w;
}
void fwrite(int x)
{
    if(x>=10) fwrite(x/10);
    putchar(x%10+'0');
    return ;
}
int gcd(int x,int y)
{
    if(y==0) return x;
    return gcd(y,x%y); 
}
signed main()
{
    freopen("guess.in","r",stdin);
    freopen("guess.out","w",stdout);
    int T=fread();
    while(T--)
    {
        int m=fread();
        int fl=0;
        for(int i=1;i<=400;i++)
        {
            int sum=0;
            for(int j=1;j<=i;j++) 
            if(gcd(i,j)==1) sum+=j;
            if(sum==m)
            {
                fl=1;
                fwrite(i);
                cout<<endl;
                break;
            }
        }
        if(fl==0)
        {
            int ans;
            ans=(1+sqrt(1+8*m))/2;
            fwrite(ans);
            cout<<endl;
        }
    }
    return 0;
}