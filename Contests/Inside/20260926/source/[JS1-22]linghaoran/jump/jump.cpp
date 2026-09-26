#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll mod=1e9+7;
ll n,cnt;
string str;


ll get_cnt(string S){
    ll ans=0;
    queue<string> que;
    map<string,bool> mp;
    que.push(S);
    mp[S]=true;
    ++ans;

    while(!que.empty()){
        string ft=que.front();que.pop();
        for(ll i=0;i<n-1;++i){
            string ft1=ft;
            if(i+2<n&&ft1[i]=='1'&&ft1[i+1]=='1') swap(ft1[i],ft1[i+2]);
            if(!mp[ft1]){
                ++ans;
                que.push(ft1);
                mp[ft1]=true;
            }

            string ft2=ft;
            if(i-1>=0&&ft2[i]=='1'&&ft2[i+1]=='1') swap(ft2[i-1],ft2[i+1]);
            if(!mp[ft2]){
                ++ans;
                que.push(ft2);
                mp[ft2]=true;
            }
        }
    }
    return ans;
}

void dfs(ll dep,string ak){
    if(dep==n){
        ll val=get_cnt(ak);
		cnt+=val;
    }
    else{
        if(str[dep]=='?'){
            dfs(dep+1,ak+"0");
            dfs(dep+1,ak+"1");
        }
        else{
            dfs(dep+1,ak+str[dep]);
        }
    }
}


int main(){
    freopen("jump.in","r",stdin);
    freopen("jump.out","w",stdout);
    cin>>n>>str;

    dfs(0,"");
    
    cout<<cnt;
    return 0;
}
