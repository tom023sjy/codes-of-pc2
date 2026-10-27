int a[N + 5];
signed main() {
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 1; i <= n; i ++)
        cin >> a[i], mp[a[i]] ++;
    map<int, int> rnk;
    int curr = 0;
    for (auto kv : mp)
        rnk[kv.first] = ++ curr;
    for (int i = 1; i <= n; i ++)
        cout << rnk[a[i]] << " ";
    return 0;
}