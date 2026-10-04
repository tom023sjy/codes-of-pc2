#include<bits/stdc++.h>
using namespace std;
int n;
int a[15][15],b[15][15],c[15][15];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("triangle.in","r",stdin);
	freopen("triangle.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cin>>b[i][j];
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(a[n-j+1][i-j+1]!=b[i][j]){
			ans++;}
		}
	}int ans2=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
		//	cout<<n-i+1<<","<<j<<' '<<i<<","<<j<<"\n"<<a[n-i+1][j]<<" "<<b[i][j]<<"\n";
			
			if(a[n-i+j][j]!=b[i][j])ans2++;
		}
	}
	int ans3=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(a[i][i+1-j]!=b[i][j])ans3++;
		}
	}
	int ans4=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(a[n+j-i][n-i+1]!=b[i][j])ans4++;
		}
	}
	int ans5=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(a[n-j+1][n-i+1]!=b[i][j])ans5++;
		}
	}
	int ans6=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(a[i][j]!=b[i][j])ans6++;
		}
	}
//	cout<<ans<<" "<<ans2<<" "<<ans3<<" "<<ans4<<" "<<ans5<<"\n";
	cout<<min({ans,ans2,ans3,ans4,ans5,ans6});
	return 0;
	
}



