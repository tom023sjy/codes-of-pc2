#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;
const int N=1e6+5,V=3e4+1;
bitset <V>v[2005][2],g[2005][2];
int n,a[N];
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("cup.in","r",stdin);
    freopen("cup.out","w",stdout);
    //freopen("express.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    sort(a+1,a+1+n,cmp);
    int op=1;
    v[0][0][0]=1;
    for(int i=1;i<=n;i++)
    {
        op^=1;
        for(int j=0;j<=n;j++)
        {
            if((a[i]!=a[i-1]&&i!=1)||i==2)//-i
            {
                g[j+1][op^1]|=(v[j][op]<<(a[i]));
            }
            v[j][op^1]|=(v[j][op]<<(a[i]*0));
            if(j>=1)v[j-1][op^1]|=(v[j][op]>>a[i]);
        }
        if((a[i]!=a[i-1]&&i!=1)||i==2)
        {
            for(int j=0;j<=n;j++)//-i
            {
                g[j+1][op^1]|=(g[j][op^1]<<(a[i]));
                v[j][op^1]|=g[j][op^1];
                g[j][op^1]&=0;
            }
        }
        /*cout<<i<<endl;
        for(int j=0;j<=n;j++)
        {
            cout<<j<<" ";
            for(int k=0;k<=n;k++)if(v[j][op^1][k])printf("%d ",k);
            //printf(:\n);
            cout<<endl;
        }*/
    }
    op^=1;
    for(int i=0;i<V;i++)
    {
        if(v[0][op][i])printf("%d ",i);
    }
    printf("\n");
    return 0;
}
/*
8
4 1 3 1 2 1 2 1
3
2 1 2
g++ cup.cpp -O2 -o cup -std=c++14
gdb -q -tui ./cup
b 21
r
3 
50 50 1
10
50 50 2 2 2 1 2 1 2 2

diff ex_cup4.out cup.out



0 1 2 48 49 50 96 97 98 144 145 146 192 193 194 240 241 242 288 289 290 337 338 386
0 1 2 48 49 50 96 97 98 144 145 146 192 193 194 240 241 242 288 289 290 337 338 386 
*/