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

  ll w, n;
  cin >> w >> n;

  ll wt[n], val[n];
  for (ll i = 0; i < n; i++) {
    cin >> wt[i] >> val[i];
  }

  ll dp[n + 1][w + 1];

  for (ll i = 0; i <= n; i++) {
    for (ll j = 0; j <= w; j++) {
      if (i == 0 || j == 0) {
        dp[i][j] = 0; //If number of items availavle is 0 or If capacity that bag can carry is 0 then
        //Profit in that case is 0
      }
    }
  }

  for (ll i = 1; i <= n; i++) {
    for (ll j = 1; j <= w; j++) {
      //If the wt of ith item is less than  or equal to j
      if (wt[i - 1] <= j) {
        //Then we have to Options either we can take it or we can't take it
        //We will take the one that maximizes the profit
        ll op1 = val[i - 1] + dp[i - 1][j - wt[i - 1]]; //Taking that item we have profit of val[i-1] but capacity reduces by j-wt[i-1]
        ll op2 = dp[i - 1][j]; //Not taking that item
        dp[i][j] = max(op1, op2);
      }
      else {
        //Only option is to not take that item
        dp[i][j] = dp[i - 1][j];
      }
    }
  }

  cout << dp[n][w] << ".\n";


}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  w(t) {
    cout << "Hey stupid robber, you can get ";
    solve();
  }
  return 0;
}
