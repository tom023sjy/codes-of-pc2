#include<bits/stdc++.h>
using namespace std;
int mp[10][15][15];
int xxkan[15][15];
int main()
{
	freopen("triangle.in","r",stdin);
	freopen("triangle.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cin>>mp[0][i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cin>>xxkan[i][j];
        }
    }
    for(int i=1;i<=2;i++)
    {
        for(int x1=1,y2=n;x1<=n;x1++,y2--)
        {
            for(int y1=1,x2=1;y1<=x1;y1++,x2++)
            {
                mp[i][x2][y2]=mp[i-1][x1][y1];
            }
        }
        for(int y1=2;y1<=n;y1++)
        {
        	for(int x1=n;x1>=y1-1;x1--)
        	{
        		swap(mp[i][x1][y1],mp[i][x1-y1+1][y1]);
			}
		}
    }
    for(int i=3;i<=5;i++)
    {
    	int pre=i-3;
    	for(int x1=1;x1<=n;x1++)
    	{
    		for(int y1=1;y1<=x1;y1++)
    		{
    			mp[i][x1][x1-y1+1]=mp[pre][x1][y1];
			}
		}
	}
	int ans=24532453;
	for(int i=0;i<=5;i++)
	{
		int cnt=0;
		for(int x1=1;x1<=n;x1++)
		{
			for(int y1=1;y1<=x1;y1++)
			{
				if(mp[i][x1][y1]!=xxkan[x1][y1]) cnt++;
				//cout<<mp[i][x1][y1]<<" ";
			}
			//cout<<"\n";
		}
		//cout<<"\n";
		ans=min(cnt,ans);
	}
	cout<<ans;
	return 0;
}
/*
10
1
1 0
0 1 0
1 1 1 1
0 1 1 1 1
0 0 0 0 0 0
1 1 1 1 0 1 0
0 1 0 1 0 1 0 1
1 1 0 0 1 0 1 0 1 
1 1 1 1 0 0 1 0 1 0
1 
0 1
0 1 0 
1 0 1 0
1 0 0 0 0
1 1 1 1 1 0
1 0 1 0 1 0 0
1 1 1 1 1 0 0 0
1 1 0 1 0 1 0 1 0
1 1 0 1 0 1 1 1 1 0
*/
