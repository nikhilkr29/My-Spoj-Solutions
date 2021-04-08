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

ll lcs(vi &s, vi &p) {

  ll n = s.size(), m = p.size();
  ll dp[n + 1][m + 1];
  memset(dp, 0, sizeof(dp));

  for (ll i = 1; i <= n; i++) {
    for (ll j = 1; j <= m; j++) {
      if (s[i - 1] == p[j - 1]) {
        dp[i][j] = 1 + dp[i - 1][j - 1];
      }
      else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }

  return dp[n][m];


}


void solve() {

  vector<ll> v;
  ll x;
  while (cin >> x && x != 0) {
    v.pb(x);
  }

  vector<vector<ll>> d;

  while (1) {
    vector<ll> temp;
    while (cin >> x && x != 0) {
      temp.pb(x);
    }
    if (temp.empty()) {
      break;
    }
    d.pb(temp);
  }

  ll mx = 0;

  for (auto x : d) {
    mx = max(lcs(x, v), mx);
  }
  cout << mx << "\n";



}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  w(t) {
    solve();
  }
  return 0;
}