#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=32,M=101,P=998244353;

int count(ll S)//求二进制 1的个数
{
	int cnt=0;
	while(S)
	{
		cnt++;
		S&=S-1;//末尾1消除 
	}
	return cnt;
} 

ll n,m,k,C[M][M],v[M][N];
int c[M];
ll ans=0;
void dfs(int res,int num)//剩余，第Num个 
{
	if(num==m)
	{
		c[m]=res;
		ll S=0,val=1,cnt=1,sum=n;
		for(int i=0;i<=m;i++)
		{
			S+=c[i]*(1<<i);
			val=val*v[i][c[i]]%P;
			cnt=cnt*C[sum][c[i]]%P;
			sum-=c[i];
		}
		if(count(S)>k) return;
		//权值 
		
		ans=(ans+val*cnt)%P;
		return;
	}
	for(int i=0;i<=res;i++)
	{
		c[num]=i;
		dfs(res-i,num+1);
	}
}


ll dp[M][N][N][16];//第几个,当前的和，1的数量，当前4位 
int main()
{
	cin>>n>>m>>k;
	for(int i=0;i<=m;i++) 
	{
		v[i][0]=1;
		cin>>v[i][1];
		for(int j=2;j<=n;j++)
			v[i][j]=v[i][j-1]*v[i][1]%P;
	}
	
	for(int i=0;i<=100;i++)
	{
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;j++)
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%P;
	}
	
	//dfs(n,0);
	
	for(int x=0;x<=n;x++) dp[0][x][x%2][x/2]=v[0][x]*C[n][x]%P;
	
	for(int i=1;i<=m;i++)
	{
		for(int n1=0;n1<=n;n1++) for(int k1=0;k1<=k;k1++)
		for(int s=0;s<16;s++) 
		{
			for(int x=0;x+n1<=n;x++)
			//dp[i-1][n1][k1][s] -> dp[i][n1+x][k1+(s+x)%2][(s+x)/2]
			{
				if(k1+(s+x)%2>k) continue;
				ll& tmp=dp[i][n1+x][k1+(s+x)%2][(s+x)/2];
				
				tmp=(tmp+dp[i-1][n1][k1][s]*v[i][x]%P*C[n-n1][x])%P;
			}
		}
	}
	//dp[m][n][][]
	for(int k1=0;k1<=k;k1++) for(int s=0;s<16;s++) 
	{
		if(k1+count(s)<=k) ans=(ans+dp[m][n][k1][s])%P;
	}
	cout<<ans;
}
