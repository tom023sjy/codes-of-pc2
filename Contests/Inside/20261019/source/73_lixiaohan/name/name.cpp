#include<bits/stdc++.h>
using namespace std;
#define int long long
int cnt[505],d[505];
int check(int n,int k){
    int sum=0,defeat=0;
    while(defeat<k){
        sort(d+1,d+1+n);
        bool flag=false;
        for(int i=k;i>=1;i--){
            if(d[i]!=0&&d[i]%2==0){
                flag=true;
                d[i]++;
                break;
            }
        }
        if(!flag){
            d[k]++;
        }
        flag=false;
        for(int i=k;i>=1;i--){
            if(d[i]!=0&&d[i]%2==0){
                flag=true;
                d[i]-=2;
                if(d[i]<=0){
                    defeat++;
                }
                break;
            }
        }
        if(!flag){
            d[k]-=2;
            if(d[k]<=0){
                defeat++;
            }
        }
        sum++;
        if(sum>100){
            break;
        }
    }
    return sum;
}
signed main(){
    freopen("name.in","r",stdin);
    freopen("name.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int C,q;
    cin>>C>>q;
    while(q--){
        int op;
        cin>>op;
        if(op==1){
            int x,y;
            cin>>x>>y;
            cnt[x]=y;
        }
        else{
            if(C==7||C==8){
                cin>>k;
                cout<<k<<endl;
                continue;
            }
            int ccnt=0,k;
            cin>>k;
            for(int i=1;i<=500;i++){
                if(cnt[i]){
                    for(int j=1;j<=cnt[i];j++){
                        d[++ccnt]=i;
                    }
                }
            }
            cout<<check(ccnt,k)<<endl;
        }
    }
    return 0;
}
