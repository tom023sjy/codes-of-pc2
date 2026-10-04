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
int t,n;
string s;
vector<int> v;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>t;
    while(t--){
    	cin>>n>>s;
    	s=" "+s; 
    	int k=-1;
    	for(int i=1;i<=n;i++){
    		if(s[i]=='1'){
    			k=i;
    			break;
			}
		}
		if(k==-1){
			cout<<"0\n";
			continue; 
		}
		bool f=0;
		for(int i=k;i<=n;i++){
			if(s[i]=='0'){
				f=1;
				break;
			}
		}
		if(!f){
			if(k==1){
				for(int i=k;i<n;i++){
					cout<<s[i];
				}
				cout<<"0\n";
			}
			else{
				for(int i=k;i<=n;i++){
					cout<<s[i]<<"\n";
				}
			}
			continue;
		}
		string ss;
		for(int j=0;j<=n;j++){
			ss+=" ";
		}
		for(int i=1;i<=n;i++){//i结尾 
			string tmp=s;
			for(int j=0;j<=min(i-1,n-k);j++){
				tmp[n-j]='0'+(s[i-j]!=s[n-j]);
				ss=max(ss,tmp);
			}
		}
		bool fl=0;
		for(int i=0;i<ss.size();i++){
			if(s[i]!=' '&&s[i]!='0') fl=1;
			if(fl) cout<<ss[i];
		}
		cout<<"\n";
		v.clear();
	}
    I AK IOI;
}
//fc C:\Users\Administrator\Desktop\CCF_IOI\xor\xor.out C:\Users\Administrator\Desktop\CCF_IOI\xor\ex_xor1.out
