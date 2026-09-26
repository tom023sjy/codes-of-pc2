#include <bits/stdc++.h>
using namespace std;

int n,m,k,d,x,y,cnt[500005];

int main()
{
	freopen("hire.in","r",stdin);
	freopen("hire.out","w",stdout);

	cin >> n >> m >> k >> d;
	while(m--)
	{
		cin >> x >> y;
		int idx = x+d;
		while(y>=k-cnt[x] && x<=idx)
		{
			y -= k-cnt[x];
			cnt[x++] = k;
		}
		if(y > 0)
			cnt[idx] += y;
		else
			for(int i = idx;i >= idx-d;i--)
			{
				if(cnt[i]+y >= 0) cnt[i] += y;
				else y += cnt[i],cnt[i] = 0;
			}
		if(cnt[idx] > k)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
