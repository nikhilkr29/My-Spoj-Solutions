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

ll n;
vector<pair1> v;

ll dp[10005][10005];

ll solve(ll assis, ll id, ll cap) {

  //Base Case
  if (id == n) {
    return 0;
  }
  if (dp[assis][id] != -1) {
    return dp[assis][id];
  }

  ll res = 0;

  //If no more assis can be there remaining will be captain but not vice versa as age of capt should be more than that of ass
  if (assis == n / 2) {
    res = solve(assis, id + 1, cap + 1) + v[id].first; //Add Salary of Captain and go to nxt index
  }

  //If assist and captain are in equal no then the nxt candidate has only one choice that is to become a Assistant
  //otherwise no one will be of smaller age then him if he becomes a captain
  else if (assis == cap) {
    res = solve(assis + 1, id + 1, cap) + v[id].second; //Add Salary of Assistant and go to nxt idx
  }

  else {
    //Can be picked as both Captain or as an Assistant
    ll op1 = solve(assis + 1, id + 1, cap) + v[id].second; //Choose as Assistant
    ll op2 = solve(assis, id + 1, cap + 1) + v[id].first; //Choose as Captain
    res = min(op1, op2);
  }

  return dp[assis][id] = res;


}

void nk() {

  cin >> n;
  v.resize(n);
  for (ll i = 0; i < n; i++) {
    cin >> v[i].first >> v[i].second;
  }
  memset(dp, -1, sizeof(dp));
  //First one will always be chosen as an assistant
  ll res = v[0].second;
  res += solve(1, 1, 0); //Count of Assist=1 and idx=1 and Count of Captain=0
  cout << res << "\n";
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