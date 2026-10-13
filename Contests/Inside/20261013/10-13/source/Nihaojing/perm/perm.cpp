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
int n,a[20],b[20],c[20];
vector<int> gg[20],g[20];
int dfs(int u,int dep,int k){
	int tmp=1e9;
	if(c[u]<c[k]) tmp=dep;
	for(auto v:g[u]){
		tmp=min(tmp,dfs(v,dep+1,k));
	}
	return tmp;
}
void ini(int u,int f){
	for(auto v:gg[u]){
		if(v==f) continue;
		g[u].push_back(v);
		ini(v,u);
	}
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("perm.in","r",stdin);
    freopen("perm.out","w",stdout);
    cin>>n;
    if(n<=18){
	    for(int i=1;i<=n;i++){
	    	cin>>a[i];
		}
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			gg[u].push_back(v);
			gg[v].push_back(u);
		}
		ini(1,0);
		for(int i=1;i<=n;i++){
			b[i]=i;
		}
		do{
			for(int i=1;i<=n;i++){
				c[b[i]]=i;
			}
			bool fl=0;
			for(int i=1;i<=n;i++){
				int k=dfs(i,0,i);
				if(k>1e8) k=-1;
				if(a[i]!=k){
					fl=1;
					break;
				} 
			}
			if(fl==0){
				for(int i=1;i<=n;i++){
					cout<<b[i]<<" ";
				}
				I AK IOI;
			}
		}while(next_permutation(b+1,b+n+1));
		cout<<-1;
	}
    else cout<<-1;
    I AK IOI;
}
//fc C:\Users\Administrator\Desktop\NOI_P\gloves\ex_gloves4.out C:\Users\Administrator\Desktop\NOI_P\gloves\gloves.out
/*
6 5
2 3 4 11 16 19
5 8 12 13 14
*/

