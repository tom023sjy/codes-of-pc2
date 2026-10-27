const int N = 3e6;
int inv[N + 5];
signed main() {
	int n, p;
    inv[1] = 1;
    for (int i = 2; i <= n; i ++)
        inv[i] = (p - p / i) * inv[p % i] % p;
}