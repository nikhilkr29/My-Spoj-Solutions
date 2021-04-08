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
#define  w(t) long long int t;t=1;while(t--)


void solve() {

  ll n;
  cin >> n;

  vector<pair1> v;
  for (ll i = 0; i < n; i++) {
    ll x, y;
    cin >> x >> y;
    if (x > y) {
      swap(x, y);
    }
    v.pb({x, y});
  }

  ll dp[n][2]; //dp[index][alingment of rectangle]
  memset(dp, 0, sizeof(dp));

  dp[0][0] = v[0].first;
  dp[0][1] = v[0].second;


  for (ll i = 1; i < n; i++) {
    //We have 2 choice either to place the current one horizontally or as vertically

    //Placing horizontally
    dp[i][0] = v[i].first ;
    ll op1 = dp[i][0] + dp[i - 1][0] + (max(v[i - 1].second, v[i].second) - min(v[i - 1].second, v[i].second));
    ll op2 = dp[i][0] + dp[i - 1][1] + (max(v[i - 1].first, v[i].second) - min(v[i - 1].first, v[i].second));
    dp[i][0] = max(op1, op2);

    //Placing Vertically
    dp[i][1] = v[i].second ;
    ll op11 = dp[i][1] + dp[i - 1][0] + (max(v[i].first, v[i - 1].second) - min(v[i].first, v[i - 1].second));
    ll op21 = dp[i][1] + dp[i - 1][1] + (max(v[i].first, v[i - 1].first) - min(v[i].first, v[i - 1].first));
    dp[i][1] = max(op11, op21);
  }


  cout << max(dp[n - 1][0], dp[n - 1][1]) << "\n";


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