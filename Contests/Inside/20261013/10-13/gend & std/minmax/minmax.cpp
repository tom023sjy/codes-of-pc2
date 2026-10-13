#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,a[N],b[N];
int solve(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    for(int i=1;i<=m;i++)scanf("%d",b+i);
    int cur=1;
    for(int i=1;i<=m;i++){
        while(cur<=n&&a[cur]!=b[i])cur++;
        if(cur>n)return puts("No");
        cur++;
    }puts("Yes");
    return 0;
}
int main(){
    int t;scanf("%d",&t);
    while(t--)solve();
    return 0;
}