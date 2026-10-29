#include <bits/stdc++.h>
using namespace std;
namespace nqio{const unsigned R=4e5,W=4e5;char*a,*b,i[R],o[W],*c=o,*d=o+W,h[40],*p=h,y;bool s;struct q{void r(char&x){x=a==b&&(b=(a=i)+fread(i,1,R,stdin),a==b)?-1:*a++;}void f(){fwrite(o,1,c-o,stdout);c=o;}~q(){f();}void w(char x){*c=x;if(++c==d)f();}q&operator>>(char&x){do r(x);while(x<=32);return*this;}q&operator>>(char*x){do r(*x);while(*x<=32);while(*x>32)r(*++x);*x=0;return*this;}template<typename t>q&operator>>(t&x){for(r(y),s=0;!isdigit(y);r(y))s|=y==45;if(s)for(x=0;isdigit(y);r(y))x=x*10-(y^48);else for(x=0;isdigit(y);r(y))x=x*10+(y^48);return*this;}q&operator<<(char x){w(x);return*this;}q&operator<<(char*x){while(*x)w(*x++);return*this;}q&operator<<(const char*x){while(*x)w(*x++);return*this;}template<typename t>q&operator<<(t x){if(!x)w(48);else if(x<0)for(w(45);x;x/=10)*p++=48|-(x%10);else for(;x;x/=10)*p++=48|x%10;while(p!=h)w(*--p);return*this;}}qio;}using nqio::qio;
typedef long long ll;
map<ll, int> m;
const int mod = 10000019;
const int times = 50;
ll mul(ll a, ll b, ll m)
{
  ll ans = 0;
  a %= m;
  while (b)
  {
    if (b & 1)
      ans = (ans + a) % m;
    b /= 2;
    a = (a + a) % m;
  }
  return ans;
}
ll pow(ll a, ll b, ll m)
{
  ll ans = 1;
  a %= m;
  while (b)
  {
    if (b & 1)
      ans = mul(a, ans, m);
    b /= 2;
    a = mul(a, a, m);
  }
  ans %= m;
  return ans;
}
bool Miller_Rabin(ll n, int repeat)
{
  if (n == 2 || n == 3)
    return true;
  if (n % 2 == 0 || n == 1)
    return false;

  ll d = n - 1;
  int s = 0;
  while (!(d & 1))
    ++s, d >>= 1;
  for (int i = 0; i < repeat; i++)
  {
    ll a = rand() % (n - 3) + 2;
    ll x = pow(a, d, n);
    ll y = 0;
    for (int j = 0; j < s; j++)
    {
      y = mul(x, x, n);
      if (y == 1 && x != 1 && x != (n - 1))
        return false;
      x = y;
    }
    if (y != 1)
      return false;
  }
  return true;
}
ll gcd(ll a, ll b)
{
  return b == 0 ? a : gcd(b, a % b);
}
ll pollard_rho(ll n, ll c)
{
  ll x = rand() % (n - 2) + 1;
  ll y = x, i = 1, k = 2;
  while (1)
  {
    i++;
    x = (mul(x, x, n) + c) + n;
    ll d = gcd(y - x, n);
    if (1 < d && d < n)
      return d;
    if (y == x)
      return n;
    if (i == k)
    {
      y = x;
      k <<= 1;
    }
  }
}
void Find(ll n, ll c)
{
  if (n == 1)
    return;

  if (Miller_Rabin(n, times))
  {
    m[n]++;
    return;
  }
  ll p = n;
  while (p >= n)
    p = pollard_rho(p, c--);
  Find(p, c);
  Find(n / p, c);
}
vector<pair<ll, int>> num;
void solve(ll n)
{
  n *= 2;
  m.clear();
  num.clear();
  Find(n, rand() % (n - 1) + 1);
  for (auto p : m)
    num.emplace_back(p);
  ll ans = -1;
  function<void(int, ll, ll)> dfs = [&](int u, ll number, ll phi)
  {
    if (n % (number * phi) != 0)
      return ;
    // printf("dfs(%d, %lld, %lld), ans = %lld\n", u, number, phi, ans);
    if (u == (int)num.size())
    {
      if (number * phi == n)
      {
        ans = number;
      }
      return;
    }
    dfs(u + 1, number, phi);
    if (ans != -1)
      return;
    for (int i = 1; i <= num[u].second; i++)
    {
      number *= num[u].first;
      dfs(u + 1, number, phi * (num[u].first - 1));
      if (ans != -1)
        return;
      phi *= num[u].first;
    }
  };
  dfs(0, 1, 1);
  qio << ans << '\n';
}
int main()
{
  freopen("guess.in", "r", stdin);
  freopen("guess.out", "w", stdout);
  int t;
  srand((unsigned)time(NULL));
  scanf("%d", &t);
  while (t--)
  {
    __int128 n;
    qio >> n;
    if (n <= 1000000000000000000)
    {
      solve((ll)n);
    }
    else
    {
      __int128 res = (__int128)sqrt((double)8 * n + 1);
      while (res * res < 8 * n + 1)
        ++res;
      while (res * res > 8 * n + 1)
        --res;
      qio << (res + 1) / 2 << '\n';
    }
  }
  return 0;
} 