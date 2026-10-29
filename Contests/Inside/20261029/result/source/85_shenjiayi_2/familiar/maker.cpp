#include <bits/stdc++.h>
using namespace std;
const int N = 1000, M = 1e8, T = 1e6;
signed main() {
    int n = N, m = N, t = T;
    printf("%d %d %d\n", n, m, t);
    vector<int> tmp;
    for (int i = 1; i <= n; i ++) {
        mt19937 rnd(random_device{}());
        tmp.clear();
        for (int j = 1; j <= m; j ++)
            tmp.push_back(rnd() % M + int(9e8));
        sort(tmp.begin(), tmp.end());
        for (int v : tmp)
            printf("%d ", v);
        printf("\n");
    }
    mt19937 rnd(random_device{}());
    while (t --) {
        int a = rnd() % N + 1, b = rnd() % N + 1;
        if (a == b) {
            if (a > 1) a --;
            else a ++;
        }
        int k = rnd() % (2 * m) + 1;
        printf("1 %d %d %d\n", a, b, k);
    }
    return 0;
}

/*
#include<bits/stdc++.h>
using namespace std;
int n=1000,m=1000,T=1000000,a[1005][1005];
int main(){
	srand(time(0));
	cout<<n<<' '<<m<<' '<<T<<'\n';
	for(int i=1;i<=n;i++){
		a[i][0]=rand()%1000000;
		for(int j=1;j<m;j++)a[i][j]=a[i][j-1]+rand()%1000000;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<m;j++)cout<<a[i][j]<<' ';
		cout<<'\n';
	}
	while(T--){
		int opt=rand()%2+1;
		if(opt==1){
			int x=rand()%n+1,y=rand()%n+1,k=rand()%(m*2)+1;
			while(x==y)x=rand()%n+1,y=rand()%n+1;
			cout<<opt<<' '<<x<<' '<<y<<' '<<k<<'\n';
		}
		else{
			int x=rand()%n+1,y=rand()%500000000+1;
			cout<<opt<<' '<<x<<' '<<y<<'\n';
		}
	}
	return 0;
}

*/
