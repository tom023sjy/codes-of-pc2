#include<bits/stdc++.h>
using namespace std;
int n,h,w,mmp[5050][5050],A[5050][5050];
struct uu{
    int x,y,xx,yy,c;
} a[5050];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("chess1.in","r",stdin);
    // freopen("chess.out","w",stdout);
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
        //memset(mmp,0x3f,sizeof mmp);
        long long mi=0;
        for (int i=1;i<=n;i++){
            cin>>a[i].x>>a[i].y>>a[i].xx>>a[i].yy>>a[i].c;
            mmp[a[i].x][a[i].y]-=a[i].c;
            mmp[a[i].x][a[i].yy+1]+=a[i].c;
            mmp[a[i].xx+1][a[i].y]+=a[i].c;
            mmp[a[i].xx+1][a[i].yy+1]-=a[i].c;
            mi+=a[i].c;
        }
        int now=0;
        unsigned long long ans=0;
        while(now<n){
            long long x=-0x3f3f3f3f;
            int X,Y;
            vector<int> v;
            for (int i=1;i<=h;i++)
                for (int j=1;j<=w;j++){
                    A[i][j]=mmp[i][j]+A[i-1][j]+A[i][j-1]-A[i-1][j-1];
                    cout<<A[i][j]<<" "<<i<<" "<<j<<"\n";
                    if (A[i][j]>x){
                        x=A[i][j];
                        X=i,Y=j;
                    }
                }
            x=x+mi;
            cout<<x<<" "<<X<<" "<<Y<<" "<<mi<<"\n";
            ans+=((x-1)*x/2);
            int cnt=0;
            for (int i=1;i<=n;i++){
                if (X<a[i].x || X>a[i].xx || Y<a[i].y || Y>a[i].yy){
                    cnt++;
                    int dif=-mi+a[i].c;
                    //cout<<mmp[a[i].x][a[i].y]<<" ";
                    mmp[a[i].x][a[i].y]+=dif;
                    mmp[a[i].x][a[i].yy+1]-=dif;
                    mmp[a[i].xx+1][a[i].y]-=dif;
                    mmp[a[i].xx+1][a[i].yy+1]+=dif;
                    mi-=dif;
                    //cout<<" "<<i<<" "<<mmp[a[i].x][a[i].y]<<" "<<dif<<"\n";
                }

            }
            cout<<cnt<<" "<<now<<"\n";
            now+=cnt;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
