#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e7 + 5;
int n, t, nxt[maxn];
string s, k, c;
void getnext(string &s, int p)
{
    nxt[0] = nxt[1] = 0;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> t;
    while (t--)
    {
        cin >> n;
        cin >> s;
        s = " " + s;
        int fs1 = 0,fs0 = 0;
        for (int i = 1; i <= n; i++)
        {
            if (fs1 == 0 && s[i] == '1')
            {
                fs1 = i;
                break;
            }
        }
        if (fs1 == 0)
        {
            cout << "0\n";
            continue;
        }
        else
        {
            string ans, num;
            k = c = " ";
            for (int i = fs1; i <= n; i++)
            {
                k[i - fs1 + 1] = s[i];
                if (s[i] == 0 && !fs0)
                    fs0 = i - fs1 + 1;
            } // 不记得kmp...
            int len = n - fs1 + 1;
            for (int j = 1; j <= fs0; j++)
            {
                num = "";
                for (int ks = 1; ks <= len; ks++)
                {
                    if (k[ks + fs0 - 1] != k[j + ks - 1])
                        num = num + '1';
                    else
                        num = num + '0';
                }
                if (num > ans)
                    ans = num;
            }
            for(int i=0;i<=ans.length();i++){
                cout<<ans[i];
            }
            cout<<"\n";
        }
    }
    return 0;
}