#include <bits/stdc++.h>
using namespace std;
int n;
int A[15][15][4], B[15][15][4];

void input(int &n)
{
	cin >> n;
}

void output(int n, char c)
{
	cout << n << c;
}

void output(char c)
{
	cout << c;
}

int main()
{
	freopen("triangle.in", "r", stdin);
	freopen("triangle.out", "w", stdout);
	input(n);
	int addx = n * 2 + 1, addy = n + 2;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			input(A[i][j][0]);
			A[i][i-j+1][3] = A[i][j][0];
			A[n-j+1][i-j+1][1] = A[i][j][0];
			A[n-i+j][n-i+1][2] = A[i][j][0];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			input(B[i][j][0]);
			B[n-i+j][n-i+1][1] = B[i][j][0];
			B[n-j+1][i-j+1][2] = B[i][j][0];
			B[i][i-j+1][3] = B[i][j][0];
		}
	}
//	for (int i = 0; i < 4; i++)
//	{
//		for (int x = 1; x <= n; x++)
//		{
//			for (int y = 1; y <= x; y++)
//			{
//				output(A[x][y][i], ' ');
//			}
//			output('\n');
//		}
//		output('\n');
//	}
	int mi = 998244353;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int cnt = 0;
			for (int x = 1; x <= n; x++)
			{
				for (int y = 1; y <= x; y++)
				{
					cnt += (A[x][y][i] != B[x][y][j]);
				}
			}
			mi = min(mi, cnt);
		}
	}
	output(mi, '\n');
	return 0;
}
