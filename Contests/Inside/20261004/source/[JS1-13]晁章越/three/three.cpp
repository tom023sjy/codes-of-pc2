#include<bits/stdc++.h>
#define florr(a,b,c) for(int a=(b);a<=(c);a++)
#define AC_AK return 0;
using namespace std;
inline int in(){
	char c=getchar();
	int f=1,k=0;
	for(;!isdigit(c);c=getchar()) f=(c=='-')?-1:1;
	for(;isdigit(c);c=getchar()) k=10*k+c-'0';
	return f*k;
}
inline void out(int x){
	if(x<0) putchar('-'),x=-x;
	if(x<10) putchar(x+'0');
	else out(x/10),putchar(x%10+'0');
	return;
}
constexpr int N=5e3+10,Mod=1e9+7;
int n,m,x,fst,lst=-1,a[N],jmp[N],f[2][N][N];
map<int,int> mp;
signed main(){
//	freopen("three.in","r",stdin);
//	freopen("three.out","w",stdout);
	n=in(),m=in();
    for(int i=1;i<=n;i++) mp[in()]++;
    for(auto i:mp){
        if(lst==0) fst=i.first;
        jmp[lst]=i.first,lst=i.first;
    }
    for(int i=0;i<=m;i++){
        for(int j=0;j<=m;j++) f[0][i][j]=1;
    }
    for(int i=1;i<=m;i++){
        for(int x=0;x<=mp[i-2];x++)
            for(int y=0;y<=mp[i-1];y++){
                if(mp[i]>=x)
                for(int z=mp[i]-x;z>=0;z-=3){
                    if(z>=y-x) f[1][y-x][z]+=f[0][x][y];
                }
            }
        for(int x=0;x<=m;x++){
            for(int y=0;y<=m;y++){
                out(f[0][x][y]),putchar(' ');
            }
        putchar('\n');}
        putchar('\n');
        swap(f[0],f[1]);
    }
        for(int x=0;x<=m;x++){
            for(int y=0;y<=m;y++){
                out(f[0][x][y]),putchar(' ');
            }
            
        putchar('\n');}
    // int cnt=0;
    // for(int x=1;x<=m;x++){
    // for(int i=1;i<=m;i++){
    //     for(int j=1;j<=m;j++) out(f[x][i][j]),putchar(' ');
    //     putchar('\n');
    // }
    //     putchar('\n');

    // }
    out(f[0][0][0]);
	AC_AK
}
