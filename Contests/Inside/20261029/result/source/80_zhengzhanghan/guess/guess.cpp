#include<bits/stdc++.h>
using namespace std;
#define int __int128
void read(int &a_){
    char c_='=';
    while(c_!='-'&&(!('0'<=c_&&c_<='9'))){
        c_=getchar();
    }
    __int128 f_=1;
    if(c_=='-'){
        f_=-1;
    }else{
        a_=c_-'0';
    }
    while(1){
        c_=getchar();
        if('0'<=c_&&c_<='9'){
            a_=a_*10+c_-'0';
        }else{
            break;
        }
    }
    a_=a_*f_;
}
void puto(int a_){
    if(a_<(int)0){
        putchar('-');
        a_=-a_;
    }
    int t_[50],len_=0;
    while(a_){
        t_[++len_]=a_%10;
        a_/=10;
    }
    for(signed i_=len_;i_>=1;i_--){
        putchar(t_[i_]+'0');
    }
}
int count_pos(int x){
    int cnt=0;
    while(x){
        cnt++;
        x/=10;
    }
    return cnt;
}
int sqrtt(int x){
    int L=2,R=x,res=1;
    while(L<=R){
        int mid=(L+R)/2;
        if(mid>x/(mid-1)){
            if(mid*(mid-1)>x){
                R=mid-1;
            }else{
                L=mid+1;
                res=mid;
            }
        }else{
            L=mid+1;
            res=mid;
        }
    }
    return res;
}
int sqrtttt(int x){
    int L=2,R=x,res=1;
    while(L<=R){
        int mid=(L+R)/2;
        if(mid-1>=x/mid/mid/mid){
            if(mid*(mid-1)>x/mid/mid){
                if(mid*mid*(mid-1)>x/mid){
                    if(mid*mid*mid*(mid-1)>x){
                        R=mid-1;
                    }else{
                        L=mid+1;
                        res=mid;
                    }
                }else{
                    L=mid+1;
                    res=mid;
                }
            }else{
                L=mid+1;
                res=mid;
            }
        }else{
            L=mid+1;
            res=mid;
        }
    }
    return res;
}
bool is_p(int x){
    for(int i=2;i*i<=x;i++){
        if(x/i*i==x){
            return 0;
        }
    }
    return 1;
}
int m,n;
bool isp[10000010];
int p[5000010],pcnt;
int ps[5000010],pscnt;
void INIT(int x){
    for(signed i=2;i<=x;i++){
        isp[i]=1;
    }
    for(signed i=2;i<=x;i++){
        if(isp[i]==1){
            p[++pcnt]=i;
            for(signed j=i*2;j<=x;j+=i){
                isp[j]=0;
            }
        }
    }
}
// stack<pair<int,int> > ans;
int anss;
int lkans=-1;
int dfs(int cur,int lst){
    if(cur==(int)1){
        return 1;
    }
    int p11=sqrtt(cur);
    if(p11*(p11-1)==cur){
        if(lkans==-1||lkans<p11*anss){
            lkans=p11*anss;
        }
    }
    for(int i=lst+1;i<=pscnt;i++){
        if(cur/ps[i]/(ps[i]-1)*ps[i]*(ps[i]-1)!=cur){
            continue;
        }
        cur=cur/ps[i]/(ps[i]-1);
        anss*=ps[i];
        // ans.push({ps[i],1});
        int res=dfs(cur,i);
        if(res){
            return res;
        }
        int tx=0;
        // ans.pop();
        while(cur/ps[i]/ps[i]*ps[i]*ps[i]==cur){
            tx++;
            cur=cur/ps[i]/ps[i];
            anss*=ps[i];
            // ans.push({ps[i],tx+1});
            int res=dfs(cur,i);
            if(res){
                return res;
            }
            // ans.pop();
        }
        for(signed tm=1;tm<=tx;tm++){
            cur=cur*ps[i]*ps[i];
            anss/=ps[i];
        }
        cur=cur*ps[i]*(ps[i]-1);
        anss/=ps[i];
    }
    return 0;
}
void solve(){
    read(m);
    m*=(int)2;
    int p01=sqrtttt(m);
    if(p01*p01*p01*(p01-1)==m){
        if(is_p(p01)){
            puto(p01*p01);
            putchar('\n');
            return;
        }
    }
    pscnt=0;
    for(signed i=1;i<=pcnt;i++){
        if((m/p[i])*p[i]==m){
            if(m/(p[i]-1)*(p[i]-1)==m){
                ps[++pscnt]=p[i];
            }
        }
    }
    // for(int i=1;i<=pscnt;i++){
    //     printf("%d ",ps[i]);
    // }
    // putchar('\n');
    // while(!ans.empty()){
    //     ans.pop();
    // }
    anss=1;
    int res=dfs(m,0);
    if(res==1){
        // int tmp=1;
        // while(!ans.empty()){
        //     pair<int,int> i=ans.top();
        //     printf("(%lld %lld)\n",(long long)i.first,(long long)i.second);
        //     ans.pop();
        //     for(signed j=1;j<=i.second;j++){
        //         tmp=tmp*i.first;
        //     }
        // }
        puto(anss);
        return;
    }
    if(lkans!=-1){
        puto(lkans);
        return;
    }
    int p11=sqrtt(m);
    if(p11*(p11-1)==m){
        puto(p11);
    }
}
signed main(){
    freopen("guess.in","r",stdin);
    freopen("guess.out","w",stdout);
    int T;
    read(T);
    INIT(10000001);
    for(signed i=1;i<=T;i++){
        solve();
        putchar('\n');
    }
    return 0;
}