#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e3 + 5;
const int mod = 1e9 + 7;
int n, m, cnt[maxn];
long long ans;
bool a4 = 0;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("three.in", "r", stdin);
    freopen("three.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1, x; i <= n; i++)
    {
        cin >> x;
        cnt[x]++;
        if (x % 4 == 0)
            a4 = 1;
    }
    if (m <= 3)
    {
        int num = 0;
        while (cnt[1] >= 0)
        {
            if (cnt[2] >= cnt[1] && (cnt[2] - cnt[1]) % 3 == 0 && cnt[3] >= cnt[1] && (cnt[3] - cnt[1]) % 3 == 0 && cnt[2] != 0 && cnt[3] != 0)
            {
                num++;
                num %= mod;
            }
            cnt[1] -= 3;
        }
        cout << num;
        return 0;
    }
    if (!a4)
    {
        int num = 0;
        ans = 1;
        for (int i = 1; i <= m; i += 4)
        {
            while (cnt[i] >= 0)
            {
                if (cnt[i + 1] >= cnt[i] && (cnt[i + 1] - cnt[i]) % 3 == 0 && cnt[i + 2] >= cnt[i] && (cnt[i + 2] - cnt[i]) % 3 == 0 && cnt[i + 1] != 0 && cnt[i + 2] != 0)
                {
                    num++;
                    num %= mod;
                }
                cnt[i] -= 3;
            }
            ans *= num;
            ans %= mod;
        }
        cout << ans;
        return 0;
    }
    for (int i = 1; i <= m; i++)
    {
        if (cnt[i] == 0)
            continue;
        if (cnt[i] < 3)
        {
            if (cnt[i + 1] >= cnt[i] && cnt[i + 2] >= cnt[i])
            {
                cnt[i + 1] -= cnt[i];
                cnt[i + 2] -= cnt[i];
            }
            else
            {
                cout << 0;
                return 0;
            }
        }
    }
    cout << 1;
    return 0;
}