#include<bits/stdc++.h>
using namespace std;
#define  vi vector<long long int>
#define  set1 set<long long int>
#define  pb push_back
#define  pob pop_back
#define  map1 map<long long int,long long int>
#define  ll long long int
#define  mp make_pair
#define  inf 1e17
#define  minf INT_MIN
#define  setbits(x) __builtin_popcountll(x)
#define  pres(x,y) fixed<<setprecision(y)<<x
#define  pair1 pair<long long int,long long int>
#define  mk(arr,n,type) type *arr=new type[n];
#define  mod 1000000007
#define  pi  3.1415926535897932384626433832
#define  ins insert
#define  what_is(x) cerr << #x << " is " << x << endl;
#define  w(t) long long int t;cin>>t;while(t--)



void solve() {

  ll n;
  cin >> n;
  ll a[n + 1];
  for (ll i = 1; i <= n; i++) {
    cin >> a[i];
  }

  ll dp[n + 1];
  dp[0] = 0;

  if (n == 0) {
    cout << dp[0] << "\n";
    return;
  }
  if (n == 1) {
    cout << a[1] << "\n";
    return;
  }

  if (n >= 1) {
    dp[1] = a[1];
  }
  if (n >= 2) {
    dp[2] = max(a[1],a[2]);  //2nd element ko lenge ya 1st element ko lenge
  }

  for (ll i = 3; i <= n; i++) {
    dp[i] = max(dp[i - 1], a[i] + dp[i - 2]);
  }
  cout << max(dp[n], dp[n - 1]) << "\n";

}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  ll c = 1;
  w(t) {
    cout << "Case " << c << ": ";
    solve();
    c += 1;
  }
  return 0;
}