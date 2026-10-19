#include<bits/stdc++.h>
using namespace std;
int n,h,w,mp[505][505][10],mmp[505][505];
struct {
    int x,y,xx,yy,c;
} a[80];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("chess.in","r",stdin);
    freopen("chess.out","w",stdout);
    int cid;
    cin>>cid>>n>>h>>w;
    if (cid==9 || cid==10){
        unsigned long long ans=0;
        for (int i=1;i<=n;i++){
            unsigned long long c;
            cin>>c>>c>>c>>c>>c;
            ans+=c;
        }
        // cout<<ans<<"\n";
        if (ans&1) cout<<(unsigned long long)((ans-1)/2*ans)<<"\n";
        else cout<<(unsigned long long)(ans/2*(ans-1))<<"\n";
    }else {
        for (int i=1;i<=n;i++){
            cin>>a[i].x>>a[i].y>>a[i].xx>>a[i].yy>>a[i].c;
            for (int j=1;j<=h;j++)
                for (int k=1;k<=w;k++)
                    if ((j<a[i].x || j>a[i].xx) || (k<a[i].y || k>a[i].yy))
                        mp[j][k][i]=1,mmp[j][k]+=a[i].c;
        }
        int now=0;
        unsigned long long ans=0;
        while(now<n){
            unsigned long long x=0;
            vector<int> v;
            for (int i=1;i<=h;i++)
                for (int j=1;j<=w;j++)
                    if (mmp[i][j]>x){
                        x=mmp[i][j];
                        v.clear();
                        for (int k=1;k<=n;k++)
                            if (mp[i][j][k])
                                v.push_back(k);
                    }
            ans+=((x-1)*x/2);
            for (auto i : v)
                for (int j=1;j<=h;j++)
                    for (int k=1;k<=w;k++)
                       if ((j<a[i].x || j>a[i].xx) || (k<a[i].y || k>a[i].yy))
                           mp[j][k][i]=0,mmp[j][k]-=a[i].c;// cout<<i<<" "<<j<<" "<<k<<"\n";
            now+=v.size();
        }
        cout<<ans<<"\n";
    }
    return 0;
}
