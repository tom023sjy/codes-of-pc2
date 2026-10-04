#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
    
    cin>>t;
    for(int i=1;i<=t;i++){
        int n;
        string r;
        cin>>n;
        cin>>r;
        bool s[n+5],as[n+5];
        for(int i=1;i<=n;i++){
            s[i]=r[i-1]-'0';
            as[i]=(!s[i]);
        }
        for(int i=1;i<=n;i++) cout<<s[i]<<" ";
        cout<<"\n";
        for(int i=1;i<=n;i++) cout<<as[i]<<" ";
    }
    return 0;
}