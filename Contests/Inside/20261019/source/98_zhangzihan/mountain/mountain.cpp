#include <iostream>
using namespace std;
const int N=5e2+5;
int a[N],dp[N][N][N][2],n;
string s;
int f[55][505][505][2];

int main()
{
    cin>>s>>s;
    n=s.size();
    int op=1;
    if(s[0]=='U')dp[1][1][1][0]=1;
    else dp[1][0][1][1]=1;
    for(int i=1;i<s.size();i++)
    {
        op^=1;
        for(int j=0;j<=i;j++)
        {
            for(int k=1;k<=n;k++)
            {
                if(s[i]=='U')
                {
                    dp[i+1][j][i+1][0]+=dp[i][j][k][0];
                    dp[i+1][j][k][0]+=dp[i][j][k][0]*(j-1);
                    dp[i+1][j][k][1]+=dp[i][j][k][1]*j;//jie hou mian

                    dp[i+1][j+1][i+1][0]+=dp[i][j][k][0];
                    dp[i+1][j+1][k][0]+=dp[i][j][k][0]*j;
                    dp[i+1][j+1][k][1]+=dp[i][j][k][1]*(j+1);
                }
                else
                {
                    dp[i+1][j][k][0]+=dp[i][j][k][0]*j;
                    dp[i+1][j][k][1]+=dp[i][j][k][1]*j;

                    if(j>=1)dp[i+1][j-1][k][0]+=dp[i][j][k][0]*(j-1);
                    if(j>=1)dp[i+1][j-1][k][1]+=dp[i][j][k][1]*(j-1);
                    if(j==1)
                    {
                        dp[i+1][0][k][1]+=dp[i][j][k][1];
                    }
                    dp[i+1][j][i+1][1]+=dp[i][j][k][0];
                    dp[i+1][j][k][1]+=dp[i][j][k][1];
                }
            }
        }
    }
    //cout<<dp[2][2][1][0]<<endl;
    for(int i=1;i<=n;i++)
    {
        printf("%d ",dp[n][1][i][0]+dp[n][0][i][0]+dp[n][0][i][1]+dp[n][0][i][1]);//
    }
    return 0;
}
/*
3
UDU
*/

/*
0
UUD

0
UDUUUD

g++ mountain.cpp -o mountain -std=c++14
*/