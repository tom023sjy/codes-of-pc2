#include<bits/stdc++.h>
using namespace std;
set<int> l[5010],c[5010];
int n,x[500010],y[500010];
long long ans[500010];
inline void work(int x,int y)
{
    l[x].insert(y),c[y].insert(x);
    return;
}
int main()
{
    freopen("maxmin.in","r",stdin);
    freopen("maxmin.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    bool f=0;
    for(int i=1;i<=n;i++) cin>>x[i];
    for(int i=1;i<=n;i++) 
    {
        cin>>y[i];
        if(x[i]!=y[i]) f=1;
    }
    if(n>5000||!f)
    {
        cout<<n<<" ";
        for(int i=1;i<n;i++) cout<<"0 ";
        return 0;
    }
    work(x[1],y[1]);
    for(int i=2;i<=n;i++)
    {
        bool f=0;
        for(int k=1;k<x[i];k++)
        {
            if(l[k].size()==0) continue;
            if(!f)
            {
                set<int>::iterator it=l[k].begin();
                if(*it<=y[i]) f=1;
            }
            set<int>::iterator it=l[k].end();
            it--;
            if(*it>=y[i]) work(k,y[i]);
        }
        for(int k=x[i]+1;k<=n;k++)
        {
            if(l[k].size()==0) continue;
            if(!f)
            {
                set<int>::iterator it=l[k].end();
                it--;
                if(*it>=y[i]) f=1;
            }
            set<int>::iterator it=l[k].begin();
            if(*it<=y[i]) work(k,y[i]);
        }
        for(int k=1;k<y[i];k++)
        {
            if(c[k].size()==0) continue;
            if(!f)
            {
                set<int>::iterator it=c[k].begin();
                if(*it<=x[i]) f=1;
            }
            set<int>::iterator it=c[k].end();
            it--;
            if(*it>=x[i]) work(x[i],k);
        }
        for(int k=y[i]+1;k<=n;k++)
        {
            if(c[k].size()==0) continue;
            if(!f)
            {
                set<int>::iterator it=c[k].end();
                it--;
                if(*it>=x[i]) f=1;
            }
            set<int>::iterator it=c[k].begin();
            if(*it<=x[i]) work(x[i],k);
        }
        if(f) work(x[i],y[i]);
        int p[200010],len=0;
        for(int k=1;k<=n;k++)
        {
        	if(k==x[i]) continue;
            set<int>::iterator it;
            len=0;
            for(it=l[k].begin();it!=l[k].end();it++)
            {
            	int sum=*it;
            	if(k<x[i])
            	{
            		if(sum>y[i]) p[++len]=sum;
				}
                else
                {
	                if(sum<y[i]) p[++len]=sum;
	                else break;	
				}
            }
            for(int j=1;j<=len;j++) l[k].erase(p[j]);
        }
        for(int k=1;k<=n;k++)
        {
        	if(k==y[i]) continue;
            set<int>::iterator it;
            len=0;
            for(it=c[k].begin();it!=c[k].end();it++)
            {
            	int sum=*it;
            	if(k<y[i])
            	{
            		if(sum>x[i]&&k<y[i]) p[++len]=sum;
				}
                else
                {
	                if(sum<x[i]) p[++len]=sum;
	                else break;	
				}
                
            }
            for(int j=1;j<=len;j++) c[k].erase(p[j]);
        }
    }
    for(int i=1;i<=n;i++)
    {
        set<int>::iterator it;
        for(it=l[i].begin();it!=l[i].end();it++) ans[abs(i-*it)]++;
    }
    for(int i=0;i<n;i++) cout<<ans[i]<<" ";
}