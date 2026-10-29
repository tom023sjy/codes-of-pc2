#include<bits/stdc++.h>
using namespace std;
int t;
__int128 n,m;
string str;
void write(__int128 x)
{
    if(x<=9)
    {
        putchar(x+'0');
        return;
    }
    write(x/10),write(x%10);
    return;
}
long long gcd(long long x,long long y)
{
    if(x<y) swap(x,y);
    if(y==0) return x;
    return gcd(y,x%y);
}
int main()
{
    freopen("guess.in","r",stdin);
    freopen("guess.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>str;
        int siz=str.size();
        m=0;
        for(int i=0;i<siz;i++) m=10ll*m+(str[i]-'0');
        for(int i=1;i<=400;i++)
        {
            __int128 res=0;
            for(int j=1;j<=i;j++) if(gcd(i,j)==1) res+=j;
            if(res==m)
            {
                cout<<i<<'\n';
                goto mn;
            }
        }
        n=(1ll+sqrt(1ll+8ll*m))/2ll;
        write(n);
        cout<<'\n';
        mn:;
    }
}