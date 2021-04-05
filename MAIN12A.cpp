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
 
vi v;
 
void solve() {
 
	ll n;
	cin >> n;
	n -= 1;
	cout << v[n] << "\n";
 
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("inp.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
 
	v.pb(1);
	ll cur = 2;
 
 
	for (ll i = 0; i < v.size() && v.size() < 1000000; i++) {
		ll x = v[i];
		for (ll i = 0; i < x && v.size() < 1000000; i++) {
			v.pb(cur);
		}
		if (v.size() >= 1000000) {
			break;
		}
		cur++;
	}
 
 
 
	ll co = 1;
 
	w(t) {
		cout << " Case #" << co << ": ";
		solve();
		co += 1;
	}
	return 0;
} 