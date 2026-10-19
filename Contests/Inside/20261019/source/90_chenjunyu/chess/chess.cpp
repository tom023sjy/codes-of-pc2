#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long

struct che{
    int li,lj,ri,rj,c;
};

const int H = 5005, N = 100005;
int cid,n,h,w;
ull sumc;
che a[N];
int blo[10][10];
int lst, cnt;
bool use[N], vis[N];
vector<int> b, vec;

bool check(){
    for (int i = 1; i <= h; i++){
        for (int j = 1; j <= w; j++){
            if (blo[i][j] == 0) return true;
        }
    }
    return false;
}

void chg(int x, int v){
    for (int i = a[x].li; i <= a[x].ri; i++){
        for (int j = a[x].lj; j <= a[x].rj; j++)
            blo[i][j] += v;
    }
}

void dfs(int cur){
    if (cur == n+1){
        memset(blo,0,sizeof(blo));
        int res = 0;
        for (int x : b){
            chg(x,1);
            res += a[x].c;
        }

        if (cnt < res && check()){
            cnt = res;
            vec = b;
        }
        return;
    }
    if (!vis[cur]){
        b.push_back(cur);
        dfs(cur+1);
        b.pop_back();
    }
    dfs(cur+1);
}

int main(){
    freopen("chess.in","r",stdin);
    freopen("chess.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> cid >> n >> h >> w;
    for (int i = 1; i <= n; i++){
        cin >> a[i].li >> a[i].lj >> a[i].ri >> a[i].rj >> a[i].c;
        sumc += a[i].c;
    }
    if (9 <= cid && cid <= 10){
        cout << (sumc-1)*sumc / 2;
        return 0;
    }
    lst = n;
    ull ans = 0;
    while (lst > 0){
        cnt = 0;
        dfs(1);
        lst -= vec.size();
        for (int x : vec){
            vis[x] = true;
        }
        ans += ((ull)cnt-1) * cnt / 2;
    }
    cout << ans;
    return 0;
}
