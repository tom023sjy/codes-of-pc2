#include<bits/stdc++.h>
using namespace std;
int a[5005],v[5005];
int main(){
	freopen("three.in","r",stdin);
	freopen("three.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		v[a[i]]++;
	}
	if(m==1){
	    cout<<1;
	}
	if(m==2){
		if(v[1]%3==0&&v[2]%3==0){
			cout<<1;
		}
		cout<<"0";
	}
	if(m==3){
		if(v[1]==0){
			if(v[2]%3==0&&v[3]%3==0){
			    cout<<1;
		    }
		    cout<<"0";
		    return 0;
		}
		if(v[2]==0){
			if(v[1]%3==0&&v[3]%3==0){
			    cout<<1;
		    }
		    cout<<"0";
		    return 0;
		}
		if(v[3]==0){
			if(v[1]%3==0&&v[2]%3==0){
			    cout<<1;
		    }
		    cout<<"0";
		    return 0;
		}
		if(v[1]%3==v[2]%3&&v[2]%3==v[3]%3){
			cout<<min(v[1],min(v[2],v[3]))/3+1;
		}
		else cout<<"0";
		return 0;
	}
	if(m==4){
		int ans=0;
		if(v[1]==0){
			if(v[4]==0){
			if(v[2]%3==0&&v[3]%3==0){
			    cout<<1;
		    }
		    cout<<"0";
		    return 0;
		}
		if(v[2]==0){
			if(v[4]%3==0&&v[3]%3==0){
			    cout<<1;
		    }
		    cout<<"0";
		    return 0;
		}
		if(v[3]==0){
			if(v[4]%3==0&&v[2]%3==0){
			    cout<<1;
		    }
		    cout<<"0";
		    return 0;
		}
		if(v[4]%3==v[2]%3&&v[2]%3==v[3]%3){
			cout<<min(v[4],min(v[2],v[3]))/3+1;
		}
		else cout<<"0";
		return 0;
		}
		if(v[4]==0){
			if(v[1]==0){
			if(v[2]%3==0&&v[3]%3==0){
			    cout<<1;
		    }
		    cout<<"0";
		    return 0;
		}
		if(v[2]==0){
			if(v[1]%3==0&&v[3]%3==0){
			    cout<<1;
		    }
		    cout<<"0";
		    return 0;
		}
		if(v[3]==0){
			if(v[1]%3==0&&v[2]%3==0){
			    cout<<1;
		    }
		    cout<<"0";
		    return 0;
		}
		if(v[1]%3==v[2]%3&&v[2]%3==v[3]%3){
			cout<<min(v[1],min(v[2],v[3]))/3+1;
		}
		else cout<<"0";
		return 0;
		}
		if(v[2]==0){
			if(v[1]%3==0&&v[3]%3==0&&v[4]%3==0) cout<<"1";
			else cout<<"0";
			return 0;
		}
		if(v[3]==0){
			if(v[1]%3==0&&v[2]%3==0&&v[4]%3==0) cout<<"1";
			else cout<<"0";
			return 0;
		}
		if(v[1]%3==v[2]%3&&v[2]%3==v[3]%3&&v[4]%3==0){
			ans+=min(v[1],min(v[2],v[3]))/3+1;
		}
		if(v[4]%3==v[2]%3&&v[2]%3==v[3]%3&&v[1]%3==0){
			ans+=min(v[4],min(v[2],v[3]))/3+1;
		}
		cout<<ans;
		return 0;
	}
	else{
		int f1=0,f2=0;
		for(int i=1;i<=m;i++){
			if(v[i]==0) f1=1;
			if(v[i]>1) f2=1;
		}
		if(f1==0&&f2==0) cout<<"1";
		cout<<"0";
	}
}
