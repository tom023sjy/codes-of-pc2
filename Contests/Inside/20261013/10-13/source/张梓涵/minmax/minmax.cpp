#include <iostream>
using namespace std;
const int N=1e6+5;
int T,n,m,a[N],b[N];
int main()
{
	freopen("minmax.in","r",stdin);
	freopen("minmax.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		int top;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		for(int i=1;i<=m;i++)scanf("%d",&b[i]);
		top=1;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==b[top]&&top<=m)
			{
				top++;
			}
		}
		if(top==m+1)
		{
			printf("Yes\n");
		}
		else printf("No\n");
	}
	return 0;
}
