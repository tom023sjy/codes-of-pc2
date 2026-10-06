#include<bits/stdc++.h>
using namespace std;
int T;
string s;
int n;
int Next[10000010];
int maxx = 0,pos = -1;
void getnext(string p,int plen){
	Next[0] = 0,Next[1] = 0;
	for(int i = 1;i < plen;i++){
		int j = Next[i];
		while(j && p[i] != p[j]){
			j = Next[j];
		}
		if(p[i] == p[j]) Next[i + 1] = j + 1;
		else Next[i + 1] = 0;
	}
}
void kmp(string s,string p){
	maxx = 0,pos = -1;
	int slen = s.size(),plen = p.size();
	getnext(p,plen);
	int j = 0;
	for(int i = 0;i < slen;i++){
		while(j && s[i] != p[j]){
			j = Next[j];
		}
		if(s[i] == p[j]){
			if(j + 1 > maxx && i + j - 1 < slen) maxx = j + 1,pos = i - j; 
			j++;
		}	
	}
}
int str_xor(char a,char b){
	if(a == '0' && b == '0') return 0;
	if(a == '0' && b == '1') return 1;
	if(a == '1' && b == '1') return 0;
	if(a == '1' && b == '0') return 1;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> T;
	while(T--){
		cin >> n;
		cin >> s;
		string s1 = "";
		bool chk = false;
		for(int i = 0;i < n;i++){
			if(s[i] != '0' || chk) s1 += s[i],chk = true;
		}
		if(s1 == ""){
			s1 = "0";
			cout << s1 << '\n';
			continue;
		}
		string modify = "";
		for(int i = 0;i < s1.size();i++){
			if(s1[i] == '0') modify += "1";
			else modify += "0";
		}
		if(modify == "") modify = "0";
		kmp(s,modify);
		string ans = "";
		if(pos == -1){
			pos = s.size() - 1;
		}
		for(int i = pos;i < pos + modify.size();i++){
			ans += s[i];
		}
		int delt = s1.size() - ans.size();
		for(int i = 1;i <= delt;i++){
			ans = "0" + ans;
		}
		for(int i = 0;i < s1.size();i++){
			cout << str_xor(s1[i],ans[i]);
		}
		cout << '\n';
	}
}
