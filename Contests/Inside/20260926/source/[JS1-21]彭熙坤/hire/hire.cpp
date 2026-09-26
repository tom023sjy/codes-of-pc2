#include<bits/stdc++.h>
using namespace std;
int n,m,k,d,x,y;
int cnt[2005];
int room[2005];
int main(){
	freopen("hire.in","r",stdin);
	freopen("hire.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&k,&d);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		cnt[x]+=y;
		bool flag=true;
		for(int i=1;i<=n;i++){
			int kpi=cnt[i];
			for(int j=i;j<=i+d;j++){
				if(kpi<=k-room[j]){
					room[j]+=kpi;
					kpi=0;
					break;
				}
				else{
					kpi-=k-room[j];
					room[j]=k;
				}
			}
			if(kpi!=0){
				flag=false;
				break;
			}
		}
		if(flag) printf("YES\n");
		else printf("NO\n");
		memset(room,0,sizeof(room));
	}
	return 0;
}
