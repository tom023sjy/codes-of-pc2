#include<bits/stdc++.h>
using namespace std;
const int mx=1e5+100;
int a[mx],b[mx];
int vis[mx];
int fread()
{
	int x=0,w=1;char ch=getchar();
	while(ch>'9'||ch<'0') w=ch=='-'?-1:1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*w;
}
int main()
{
	freopen("minmax.in","r",stdin);
	freopen("minmax.out","w",stdout);
	int T=fread();
	while(T--)
	{
		int n=fread(),m=fread();
		for(int i=1;i<=n;i++) 
		a[i]=fread();
		for(int i=1;i<=m;i++) 
		b[i]=fread(),vis[i]=0;
		int pp=1;
		for(int i=1;i<=m;i++)
		{
			while(a[pp]!=b[i]&&pp<=n+1) pp++;
			if(a[pp]==b[i]) vis[i]=1;
		}
		if(vis[m]) 
		{
			cout<<"Yes\n";
		}
		else cout<<"No\n";
	}
	return 0;
}

