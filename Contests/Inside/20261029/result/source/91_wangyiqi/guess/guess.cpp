#include<iostream>
#include<cctype>
#include<math.h>
#define int long long
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

const unsigned int v=400;
int as[v+5];

int gcd(int x,int y){
	if(x<y) swap(x,y);
	while(x&&y){
		x%=y;
		swap(x,y);
	}
	return max(x,y);
}

signed main(){
	freopen("guess.in","r",stdin);
	freopen("guess.out","w",stdout);
	int t;
	cin>>t;
	for(int i=2;i<=v;i++){
		for(int j=1;j<=i;j++) if(gcd(i,j)==1) as[i]+=j;
	}
	for(int i=1;i<=t;i++){
		__int128 a;
		fastio::cin>>a;
		int fg=0;
		for(int i=2;i<=v;i++){
			if(as[i]==a){
				fg=1;
				cout<<i<<"\n";
				break;
			}
		}
		if(!fg) fastio::cout<<(__int128)floor(sqrt(2*a))+1,putchar('\n');
	}
	return 0;
}
			
