#include<bits/stdc++.h>
using namespace std;
const int N=1e6+55;
int q,mx;
int ct[N],tmp[N];
typedef long long ll;
int main(){
    freopen("name.in","r",stdin);
    freopen("name.out","w",stdout);
    scanf("%*d%d",&q);
    while(q--){
        int op;scanf("%d",&op);
        if(op==1){
            int x,y;scanf("%d%d",&x,&y);ct[x]=y;mx=max(mx,x);
        }else{
            int x;scanf("%d",&x);
            if(x<=ct[1]){
                printf("%d\n",x);
                continue;
            }x-=ct[1];
            ll ans=ct[1];
            for(int i=2;i<=mx+30;i++)tmp[i]=ct[i];
            for(int i=2,lst=1;i<=mx+30;i++)if(tmp[i]){
                if(lst){
                    lst=0;
                    tmp[i]--;
                    tmp[i+1]++;
                }
                if(tmp[i]){
                    int nw=(tmp[i]+1)/2;lst=tmp[i]&1;
                    if(nw>=x){
                        ans+=1ll*x*(i-1);
                        break;
                    }
                    ans+=1ll*nw*(i-1);
                    tmp[i+1]+=tmp[i]-nw;
                    x-=nw;
                }
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}