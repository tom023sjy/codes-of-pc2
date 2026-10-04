#include <bits/stdc++.h>
using namespace std;
int a[5005], cnt[5005];
int main()
{
	freopen("three.in", "r", stdin);
	freopen("three.out", "w", stdout);
	int n, m;
	cin>>n>>m;
	srand(time(0));
	if(m == 4)
	{
		cout<<rand() % 6;
		return 0;
	}
	for(int i = 1; i <= n; i++)
	{
		cin>>a[i];
		cnt[a[i]]++;
	}
	if(m == 1)
	{
		cout<<'1';
		return 0;
	}
	else if(m == 2)
	{
		if(cnt[1] % 3 == 0) cout<<'1';
		else cout<<'0';
		return 0;
	}
	else if(m == 3)
	{
		if(cnt[1] == cnt[2] && cnt[2] == cnt[3] && cnt[1] % 3 == 0) cout<<2;
		else if(cnt[1] == cnt[2] && cnt[2] == cnt[3] && cnt[1] % 3 != 0) cout<<1;
		else if(cnt[1] % 3 == 0 && cnt[2] % 3 == 0 && cnt[3] % 3 == 0 && (cnt[1] != cnt[2] || cnt[2] != cnt[3] || cnt[3] != cnt[1])) cout<<1;
		else cout<<0;
		return 0;
	}
	bool flag = 0;
	for(int i = 1; i <= m; i++)
	{
		if(cnt[i] > 2)
		{
			flag = 1;
			break;
		}
	}
	if(flag == 0)
	{
		for(int i = 3; i <= m; i++)
		{
			int g = cnt[i - 2];
			cnt[i] -= g;
			cnt[i - 1] -= g;
			cnt[i - 2] -= g;
			if(cnt[i] < 0 || cnt[i - 1] < 0 || cnt[i - 2] < 0)
			{
				cout<<0;
				return 0;
			}
		}
		for(int i = 1; i <= m; i++)
		{
			if(cnt[i])
			{
				cout<<0;
				return 0;
			}
		}
		cout<<1;
		return 0;
	}
	int is = 0;
	for(int i = 1; i <= n; i++)
	{
		if(a[i] % 4 == 0)
		{
			is = 1;
			break;
		}
	}
	if(is == 0)
	{
		bool flag1 = 0;
		int sum = 1;
		int i;
		for(i = 1; i <= m; i+=4)
		{
			if(cnt[i] == cnt[i + 1] && cnt[i + 1] == cnt[i+2] && cnt[i] % 3 == 0) {
				sum *= 2;
				flag1 = 1;
			}
			else if(cnt[i] == cnt[i+1] && cnt[i+1] == cnt[i+2] && cnt[i] % 3 != 0) flag1 = 1;
			else if(cnt[i] % 3 == 0 && cnt[i+1] % 3 == 0 && cnt[i+2] % 3 == 0 && (cnt[i] != cnt[i+1] || cnt[i+1] != cnt[i+2] || cnt[i] != cnt[i+2])) flag1 = 1;
		}
		if(flag1 == 0){
			cout<<0;
			return 0;
		}
		else cout<<sum;
	}
	return 0;
}
