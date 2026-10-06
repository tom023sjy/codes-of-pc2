#include<bits/stdc++.h>
using namespace std;
int t1[15][15],t2[15][15],t3[15][15],s1[15],t4[15][15];
int t5[15][15],t6[15][15],b[15][15],v[15];
int main(){
	freopen("triangle.in","r",stdin);
	freopen("triangle.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cin>>t1[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1+i-1;j<=n;j++){
			s1[j]=t1[j][i];
			//cout<<s1[j]<<" ";
		}
		int g=1;
		for(int j=1+i-1;j<=n;j++){
			t2[n-i+1][g]=s1[j];
			//t3[i+g-1][1+g-1]=s1[n-j+1];
			g++;
		}
		g=1;
		for(int j=n;j>=1+i-1;j--){
			//t3[n-i+1][g]=s1[j];
			t3[i+g-1][1+g-1]=s1[j];
			g++;
		}
		//cout<<"\n";
	}
	for(int i=1;i<=n;i++){
		for(int j=1+i-1;j<=n;j++){
			s1[j]=t1[j][i];
			//cout<<s1[j]<<" ";
		}
		int g=1;
		for(int j=1+i-1;j<=n;j++){
			//t2[n-i+1][g]=s1[j];
			t4[i+g-1][1+g-1]=s1[j];
			g++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1+i-1;j<=n;j++){
			s1[j]=t2[j][i];
			//cout<<s1[j]<<" ";
		}
		int g=1;
		for(int j=1+i-1;j<=n;j++){
			//t2[n-i+1][g]=s1[j];
			t5[i+g-1][1+g-1]=s1[j];
			g++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1+i-1;j<=n;j++){
			s1[j]=t3[j][i];
			//cout<<s1[j]<<" ";
		}
		int g=1;
		for(int j=1+i-1;j<=n;j++){
			//t2[n-i+1][g]=s1[j];
			t6[i+g-1][1+g-1]=s1[j];
			g++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cin>>b[i][j];
			if(b[i][j]!=t1[i][j]){
				v[1]++;
			}
			if(b[i][j]!=t2[i][j]){
				v[2]++;
			}
			if(b[i][j]!=t3[i][j]){
				v[3]++;
			}
			if(b[i][j]!=t4[i][j]){
				v[4]++;
			}
			if(b[i][j]!=t5[i][j]){
				v[5]++;
			}
			if(b[i][j]!=t6[i][j]){
				v[6]++;
			}
		}
	}
	sort(v+1,v+1+6);
	cout<<v[1];
} 
/*        0          1                 1
         0 0         11                2
        0 0 0        121               3
                     1221              4
                     12321             5
					 123321            6
					 1234321           7
					 12333321          8
					 122222221         9
					 1111111111        10
		*/
        
