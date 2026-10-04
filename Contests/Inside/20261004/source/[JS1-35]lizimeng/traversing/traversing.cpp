#include<bits/stdc++.h>
using namespace std;
struct node{
    int l,r,opt=-1;
};
struct op{
    int t,l,r,n;
}o[100010];
node x[100010];
bool s[100010];
bool flag=1;
int n,q,t,root,ord[100010],cnt;
queue<int> qe;
void dfs(int typ,int pos){
    if(typ==1){
        if(x[pos].l!=0) dfs(x[x[pos].l].opt,x[pos].l);
        if(x[pos].r!=0) dfs(x[x[pos].r].opt,x[pos].r);
        qe.push(pos);
    }
    if(typ==0){
        if(x[pos].l!=0) dfs(x[x[pos].l].opt,x[pos].l);
        qe.push(pos);
        if(x[pos].r!=0) dfs(x[x[pos].r].opt,x[pos].r);
    }
    if(typ==-1){
        qe.push(pos);
        if(x[pos].l!=0) dfs(x[x[pos].l].opt,x[pos].l);
        if(x[pos].r!=0) dfs(x[x[pos].r].opt,x[pos].r);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("traversing.in","r",stdin);
    freopen("traversing.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        int l,r;
        cin>>l>>r;
        s[l]=s[r]=1;
        x[i].l=l,x[i].r=r;
    }
    for(int i=1;i<=n;i++){
        if(!s[i]){
            root=i;
            break;
        }
    }
    for(int i=1;i<=q;i++){
        cin>>o[i].t;
        if(o[i].t==1){
            cnt++;
            cin>>o[i].l>>o[i].r>>o[i].n;
        }else cin>>o[i].n;
        if(o[i].t==1&&o[i-1].t==2) flag=0;
    }
    if(flag){
        for(int i=1;i<=cnt;i++){
            for(int l=o[i].l;l<=o[i].r;l++){
                x[l].opt=o[i].n;
            }
        }
        int i=1;
        dfs(x[root].opt,root);
        while(!qe.empty()){
            ord[qe.front()]=i;
            qe.pop();
            i++;
        }
        for(int i=cnt+1;i<=q;i++){
            cout<<ord[o[i].n]<<"\n";
        }
    }else{
        for(int i=1;i<=q;i++){
            if(o[i].t==1){
                for(int l=o[i].l;l<=o[i].r;l++){
                    x[l].opt=o[i].n;
                }                
            }else{
                if(o[i-1].t!=2){
                    dfs(x[root].opt,root);
                    int now=1;
                    while(!qe.empty()){
                        ord[qe.front()]=now;
                        qe.pop();
                        now++;
                    }
                }
                cout<<ord[o[i].n]<<"\n";
            }
        }
    }
    return 0;
}