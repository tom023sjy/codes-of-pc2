#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	auto sd = chrono::duration_cast<chrono::nanoseconds>(chrono::system_clock::now().time_since_epoch()).count();
	mt19937 rnd(sd);
	int n=10,m=rnd()%5+3,k=rnd()%3+1;
	cout<<n<<" "<<m<<" "<<k<<"\n";
	for(int i=1;i<=n;i++){
		cout<<rnd()%5+1<<" ";
	}	
	return 0;
} 
