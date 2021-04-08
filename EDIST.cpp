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

ll dp[2005][2005];

ll solve(string &s, string &p, ll id1, ll id2) {

  ll ans = 0;
  //Base Case
  if (id1 == s.length() && id2 == p.length()) {
    return 0;
  }
  else if (id1 == s.length()) {
    return p.length() - id2;
  }
  else if (id2 == p.length()) {
    return s.length() - id1;
  }

  if (dp[id1][id2] != -1) {
    return dp[id1][id2];
  }

  if (s[id1] == p[id2]) {
    ans = solve(s, p, id1 + 1, id2 + 1);
  }
  else {
    //Insert
    ll op1 = 1 + solve(s, p, id1, id2 + 1);
    //Delete
    ll op2 = 1 + solve(s, p, id1 + 1, id2);
    //Replace
    ll op3 = 1 + solve(s, p, id1 + 1, id2 + 1);
    ans = min({op1, op2, op3});
  }

  return dp[id1][id2] = ans;
}

void nk() {

  string s, p;
  cin >> s >> p;
  memset(dp, -1, sizeof(dp));
  cout << solve(s, p, 0, 0) << "\n";



}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  w(t) {
    nk();
  }
  return 0;
}
