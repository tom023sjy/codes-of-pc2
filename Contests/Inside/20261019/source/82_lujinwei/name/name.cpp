#include<iostream>
using namespace std;
int main()
{
    freopen("name.in","r",stdin);
    freopen("name.out","w",stdout);
    int cid,q,op,x,y;
    cin>>cid>>q;
    for(int i=1;i<=q;i++)
    {
        cin>>op;
        if(op==1)
            cin>>x>>y;
        else
        {
            cin>>x;
            cout<<x<<"\n";
        }
    }
    return 0;
}