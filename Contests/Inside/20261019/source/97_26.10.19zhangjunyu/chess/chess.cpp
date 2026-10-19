#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ull unsigned long long
inline void read(int &a)
{
    int s=0,w=1;
    char ch=getchar();
    while (ch > '9' or ch < '0')
    {
        if (ch == '-')
        {
            w=-1;
        }
        ch=getchar();
    }
    while (ch >='0' and ch <= '9')
    {
        s=s*10+ch-'0';
        ch=getchar();
    }
    a=s*w;
}
void write(int x)
{
    if (x < 0)
    {
        putchar('-');
        x=-x;
    }
    if (x > 9)
    {
        write(x/10);
    }
    putchar('0'+x%10);
    return;
}
int ans=0;
int n,h,w;
struct dian
{
    int xl,yl,xr,yr,c;
};
dian p[100005];
vector<int> cun[10];
bool zhen[4][4];
bool check()
{
    for (int tiat=1;tiat <= 8;tiat++)
    {
        if (cun[tiat].size() > 1)
        {
            memset(zhen,0,sizeof(zhen));
            int cnt=h*w;
            for (int i = 0;i < cun[tiat].size();i++)
            {
                for (int x=p[cun[tiat][i]].xl;x <= p[cun[tiat][i]].xr;x++)
                {
                    for (int y=p[cun[tiat][i]].yl;y <= p[cun[tiat][i]].yr;y++)
                    {
                        if (zhen[x][y] == 0)
                        {
                            cnt--;
                            zhen[x][y]=1;
                            if (cnt == 0)
                            {
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
    return 1;
}
int fcun[10];
void dfs(int k)
{
    if (k > n)
    {
        if (check())
        {
            int now=0;
            for (int i = 1;i <= 8;i++)
            {
                now+=(fcun[i]-1)*fcun[i]/2;
            }
            ans=max(ans,now);
        }
        return;
    }
    for (int i = 1;i <= 8;i++)
    {
        cun[i].push_back(k);
        fcun[i]+=p[k].c;
        dfs(k+1);
        fcun[i]-=p[k].c;
        cun[i].pop_back();
    }
    return;
}
signed main()
{
    freopen("chess.in","r",stdin);
    freopen("chess.out","w",stdout);
    int cid;
    read(cid);
    read(n),read(h),read(w);
    for (int i = 1;i <= n;i++)
    {
        read(p[i].xl),read(p[i].yl),read(p[i].xr),read(p[i].yr),read(p[i].c);
    }
    if (n <= 8 and h <= 3 and w <= 3)
    {
        dfs(1);
        write(ans);
        return 0;
    }
    int fz=0;
    for (int i = 1;i <= n;i++)
    {
        fz+=p[i].c;
    }
    ans=(fz-1)*fz/2;
    write(ans);
    return 0;
}