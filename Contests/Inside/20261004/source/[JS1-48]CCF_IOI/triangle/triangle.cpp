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
int n,a[15][15],b[15][15],c1[15][15],c2[15][15],ans=1e9;
int ck(){
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(a[c1[i][j]][c2[i][j]]!=b[i][j]) cnt++;
		}
	}
	return cnt;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("triangle.in","r",stdin);
    freopen("triangle.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=i;j++){
    		cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cin>>b[i][j];
		}
	}
	//cout<<"T1:\n";
	int x=0,y=0;
	for(int i=1;i<=n;i++){
		y=0;
		x++;
		for(int j=1;j<=i;j++){
			y++;
			c1[x][y]=i,c2[x][y]=j;//task 1
			//cout<<x<<" "<<y<<"\n";
		}
	}
	ans=min(ans,ck());
	x=0,y=0;
	//cout<<"T2:\n";
	for(int i=1;i<=n;i++){
		y=i;
		x++;
		for(int j=1;j<=i;j++){
			//cout<<x<<" "<<y<<"\n";
			c1[x][y]=i,c2[x][y]=j;//task 2
			y--;
		}
	}
	ans=min(ans,ck());
	x=0,y=n;
	//cout<<"T3:\n";
	for(int i=1;i<=n;i++){
		x=n;
		for(int j=1;j<=i;j++){
			c1[x][y]=i,c2[x][y]=j;//task 3
			//cout<<x<<" "<<y<<"\n";
			x--;
		}
		y--;
	}
	ans=min(ans,ck());
	/*for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cout<<c1[i][j]<<c2[i][j]<<" ";
		}
		cout<<"\n";
	}*/
	//cout<<ck()<<"\n";
	y=n,x=0;
	//cout<<"T4:\n";
	for(int i=1;i<=n;i++){
		x=n-i+1;
		for(int j=1;j<=i;j++){
			c1[x][y]=i,c2[x][y]=j;//task 4
			//cout<<x<<" "<<y<<"\n";
			x++;
		}
		y--;
	}
	ans=min(ans,ck());
	x=n,y=0;
	//cout<<"T5:\n";
	for(int i=1;i<=n;i++){
		y=1;
		x=n-i+1;
		for(int j=1;j<=i;j++){
			c1[x][y]=i,c2[x][y]=j;//task 5
			//cout<<x<<" "<<y<<"\n";
			y++;
			x++;
		}
	}
	ans=min(ans,ck());
	x=n,y=0;
	//cout<<"T6:\n";
	for(int i=1;i<=n;i++){
		y=i;
		x=n;
		for(int j=1;j<=i;j++){
			c1[x][y]=i,c2[x][y]=j;//task 6
			//cout<<x<<" "<<y<<"\n";
			y--;
			x--;
		}
	}
	ans=min(ans,ck());
	cout<<ans;
    I AK IOI;
}
//fc C:\Users\Administrator\Desktop\CCF_IOI\triangle\ex_triangle1.out C:\Users\Administrator\Desktop\CCF_IOI\triangle\ex_triangle.out
