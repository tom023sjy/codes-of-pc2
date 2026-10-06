/**
我常常追忆过去。

生命瞬间定格在脑海。我将背后的时间裁剪、折叠、蜷曲，揉捻成天上朵朵白云。

云朵之间亦有分别：积云厚重，而卷云飘渺。生命里震撼的场景掠过我的思绪便一生无法忘怀，而更为普通平常的记忆在时间的冲刷下只留下些许残骸。追忆宛如入梦，太过清楚则无法愉悦自己的幻想，过分模糊却又坠入虚无。只有薄雾间的山水，面纱下的女子，那恰到好处的朦胧，才能满足我对美的苛求。

追忆总在不经意间将我裹进泛黄的纸页里。分别又重聚的朋友，推倒又重建的街道，种种线索协助着我从一个具体的时刻出发沿时间的河逆流而上。曾经的日子无法重来，我只不过是一个过客。但我仍然渴望在每一次追忆之旅中留下闲暇时间，在一个场景前驻足，在岁月的朦胧里瞭望过去的自己，感受尽可能多的甜蜜。美好的时光曾流过我的身体，我便心满意足。

过去已经凝固，我带着回忆向前，只是时常疏于保管，回忆也在改变着各自的形态。这给我的追忆旅程带来些许挑战。

我该在哪里停留？我问我自己。
*　　┏┓　　　┏┓+ +
*　┏┛┻━━━┛┻┓ + +
*　┃　　　　　　　┃
*　┃　　　━　　　┃ ++ + + +
*  ████━████+
*  ◥██◤　◥██◤ +
*　┃　　　┻　　　┃
*　┃　　　　　　　┃ + +
*　┗━┓　　　┏━┛
*　　　┃　　　┃ + + + +Code is far away from 　
*　　　┃　　　┃ + bug with the animal protecting
*　　　┃　 　 ┗━━━┓ 神兽保佑,代码无bug　
*　　　┃ 　　　　　　 ┣┓
*　　  ┃ 　　　　　 　┏┛
*　    ┗┓┓┏━┳┓┏┛ + + + +
*　　　　┃┫┫　┃┫┫
*　　　　┗┻┛　┗┻┛+ + + +
*/
#include<bits/stdc++.h>
#define I return
#define AK 0
#define IOI
#define ll long long
using namespace std;
int n,q,l[100010],r[100010],a[100010],dfn,op,L,R,x;
bool fd=0;
void qry(int u,int xx){
	if(!u) return ;
	if(a[u]==-1){
		dfn++;
		if(u==xx){
			fd=1;
			cout<<dfn<<"\n";
			return ;
		}
	}
	if(!fd) qry(l[u],xx);
	if(a[u]==0){
		dfn++;
		if(u==xx){
			cout<<dfn<<"\n";
			fd=1;
			return ;
		}
	}
	if(!fd) qry(r[u],xx);
	if(a[u]==1){
		dfn++;
		if(u==xx){
			fd=1;
			cout<<dfn<<"\n";
			return ;
		}
	}
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("traversing.in","r",stdin);
    freopen("traversing.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
    	cin>>l[i]>>r[i];
	}
	memset(a,-1,sizeof(a));
	while(q--){
		cin>>op;
		if(op==1){
			cin>>L>>R>>x;
			for(int i=L;i<=R;i++){
				a[i]=x;
			}
		}
		if(op==2){
			cin>>x;
			dfn=0;
			fd=0;
			qry(1,x);
		} 
	}
    I AK IOI;
}
//fc C:\Users\Administrator\Desktop\CCF_IOI\traversing\traversing.out C:\Users\Administrator\Desktop\CCF_IOI\traversing\ex_traversing1.out


