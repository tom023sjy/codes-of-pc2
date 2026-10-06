#include <bits/stdc++.h>
using namespace std;

# define Rep(i,a,b) for(int i=a;i<=b;i++)
# define _Rep(i,a,b) for(int i=a;i>=b;i--)
# define RepG(i,u) for(int i=head[u];~i;i=e[i].next)

typedef long long ll;

const int N=20005;
const int base=19260817;
const int mod=1004535809;

template<typename T> void read(T &x){
   x=0;int f=1;
   char c=getchar();
   for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
   for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+c-'0';
    x*=f;
}

int n,k;
int a[N];
int ha[N];
int fac[N];

map<int,int> var;

void hs(){
	fac[0]=1;
	Rep(i,1,n)fac[i]=1ll*fac[i-1]*base%mod;
	Rep(i,1,n)ha[i]=(ha[i-1]+1ll*a[i]*fac[n-i]%mod)%mod;
}

int gethash(int l,int r){
	return 1ll*(ha[r]-ha[l-1]+mod)*fac[l]%mod;	
}

bool check(int delta){
	var.clear();
	int mx=0;
	Rep(i,1,n)
		if(i+delta-1<=n){
			var[gethash(i,i+delta-1)]++;
			mx=max(mx,var[gethash(i,i+delta-1)]);
		}
		else break;
	return mx>=k;
}

int main()
{
	read(n),read(k);
	Rep(i,1,n)read(a[i]);
	hs();	
	int l=1,r=n,ans=0;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid))ans=mid,l=mid+1;
		else r=mid-1;
	}
	printf("%d\n",ans);
	return 0;
}
