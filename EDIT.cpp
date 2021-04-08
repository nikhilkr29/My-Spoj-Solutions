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

//Pure Adhoc Ques

string s;
 
 
void solve() {
 
 
  vi v, d;
  for (ll i = 0; i < s.length(); i++) {
    if (i % 2 == 0) {
      v.pb(1);
      d.pb(0);
    }
    else {
      v.pb(0);
      d.pb(1);
    }
  }
 
 
  vi giv;
  for (ll i = 0; i < s.length(); i++) {
    char x = s[i];
    if (x >= 'a' && x <= 'z') {
      giv.pb(0);
    }
    else {
      giv.pb(1);
    }
  }
 
 
  ll diff1 = 0, diff2 = 0;
  for (ll i = 0; i < s.length(); i++) {
    if (giv[i] != v[i]) {
      diff1++;
    }
    if (giv[i] != d[i]) {
      diff2++;
    }
  }
 
  cout << min(diff1, diff2) << "\n";
 
 
 
 
 
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  while (cin >> s) {
    solve();
  }
 
  return 0;
} 