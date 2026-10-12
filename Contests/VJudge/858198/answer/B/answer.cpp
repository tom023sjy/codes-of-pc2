#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int>ve[1000005];
map<int,bool>mp[1000005];
bool cmp(int a,int b){
    return a>b;
}
signed main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int u,v;
        cin>>u>>v;
        mp[u][v]=1;
        ve[u].push_back(v);
    }
    int ans=0;
    for(int i=1;i<=1000000;i++){
        if(ve[i].size()==0)continue;
        sort(ve[i].begin(),ve[i].end(),cmp);
        for(int j=0;j<ve[i].size();j++){
            if(mp[i-1][ve[i][j]+1])mp[i-1][ve[i][j]+1]=0;
            else if(mp[i-1][ve[i][j]])mp[i-1][ve[i][j]]=0;
            else if(mp[i-1][ve[i][j]-1])mp[i-1][ve[i][j]-1]=0;
            else ans++;
        }
    }
    cout<<ans;
    return 0;
}
