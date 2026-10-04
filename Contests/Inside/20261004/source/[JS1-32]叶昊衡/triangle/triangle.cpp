#include<bits/stdc++.h>
using namespace std;
const int N=50;
int n,ans=1e9;
struct Node{
	bool Tr[N][N],V[N][N];
	void GetV()
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=i;j++)
				V[i][j]=Tr[i][j];
	}
	void Subturn(int x,int m)
	{
		for(int X1=2*x+1,Y1=x+1,X2=n-x,Y2=x+1,X3=n-x,Y3=n-2*x;X1<=n-x;X1++,Y2++,X3--,Y3--)
			Tr[X1][Y1]=V[X2][Y2],Tr[X2][Y2]=V[X3][Y3],Tr[X3][Y3]=V[X1][Y1];
		if(m>3) Subturn(x+1,m-2);
	}
	void Turn()
	{
		GetV();
		Subturn(0,n);
	}
	void Flap()
	{
		GetV();
		for(int i=1;i<=n;i++)
			for(int j=1;j<=i;j++)
				Tr[i][j]=V[i][i-j+1];
	}
	void in()
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=i;j++)
				cin>>Tr[i][j];
	}
	void out()
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=i;j++)
				cout<<Tr[i][j]<<' ';
			cout<<endl;
		}
			
	}
}a,b;
int cha()
{
	int num=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			if(a.Tr[i][j]!=b.Tr[i][j]) num++;
	return num;
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("triangle.in","r",stdin);
	freopen("triangle.out","w",stdout);
	cin>>n;
	a.in();b.in();
	a.Turn();ans=min(ans,cha());
	a.Turn();ans=min(ans,cha());
	a.Turn();ans=min(ans,cha());
	a.Flap();ans=min(ans,cha());
	a.Turn();ans=min(ans,cha());
	a.Turn();ans=min(ans,cha());
	a.Turn();ans=min(ans,cha());
	cout<<ans;
}
