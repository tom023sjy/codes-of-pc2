#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
int n;
int a[505];

int main(){
//	freopen("jump.in", "r", stdin);
//	freopen("jump.out", "w", stdout);
	cin>>n;
	int cnt = 0;
	for(int i=1; i<=n; i++){
		char c;
		cin>>c;
		if(c == '?'){
			a[i] = -1;
			cnt++;
		}
		else a[i] = c - '0';
	}
	
	return 0;
}
