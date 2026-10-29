#include<iostream>
using namespace std;

namespace fastio{
    struct reader{
    	template<typename T>reader&operator>>(T&x){
    		char c=getchar_unlocked();short f=1;
    		while(c<'0'||c>'9'){if(c=='-')f*=-1;c=getchar_unlocked();}
    		x=0;while(c>='0'&&c<='9'){
    			x=(x<<1)+(x<<3)+(c^48);
    			c=getchar_unlocked();
    		}x*=f;return *this;
    	}
    }cin;
    struct writer{
        template<typename T>writer&operator<<(T x){
    		if(x==0)return putchar_unlocked('0'),*this;
    		if(x<0)putchar_unlocked('-'),x=-x;
    		static int sta[45];int top=0;
    		while(x)sta[++top]=x%10,x/=10;
    		while(top)putchar_unlocked(sta[top]+'0'),--top;
    		return*this;
    	}
    }cout;
};

int n,m,q,a[1005][1005];

int main(){
	freopen("familiar.in","r",stdin);
	freopen("familiar.out","w",stdout);
	fastio::cin>>n>>m>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) fastio::cin>>a[i][j];
	}
	while(q--){
		int opt,x,y,k;
		fastio::cin>>opt>>x>>y;
		if(opt==1){
			fastio::cin>>k;
			if(k>m){
				k=2*m-k+1;
				int ptrx=1,ptry=1,as=0;
				while(as<k-1){
					if(a[x][ptrx]<a[y][ptry]&&ptrx<=m) ptrx++;
					else ptry++;
					as++;
				}
				fastio::cout<<min(a[x][ptrx],a[y][ptry]);
				putchar_unlocked('\n');
			}
			else{
				int ptrx=m,ptry=m,as=0;
				while(as<k-1){
					if(a[x][ptrx]>a[y][ptry]&&ptrx>=1) ptrx--;
					else ptry--;
					as++;
				}
				fastio::cout<<max(a[x][ptrx],a[y][ptry]);
				putchar_unlocked('\n');
			}
		}
		else{
			int l=1,r=m,mid,as=-1;
			while(l<=r){
				mid=(l+r)>>1;
				if(a[x][mid]<=y){
					as=mid;
					l=mid+1;
				}
				else r=mid-1;
			}
			if(as!=-1) a[x][mid]=y;
		}
	}
	return 0;
}
