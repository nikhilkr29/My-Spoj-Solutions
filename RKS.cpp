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
 
map<ll, ll> when;
 
bool comp(pair1 p1, pair1 p2) {
 
	if (p1.second == p2.second) {
 
		return when[p1.first] < when[p2.first];
	}
	return p1.second > p2.second;
 
}
 
 
void solve() {
 
	ll n, k;
	cin >> n >> k;
 
	ll a[n];
 
	map1 m;
 
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
		if (when.find(a[i]) == when.end()) {
			when[a[i]] = i;
		}
		m[a[i]]++;
	}
 
	vector<pair1> v;
	for (auto it = m.begin(); it != m.end(); it++) {
		v.pb({it->first, it->second});
	}
 
	sort(v.begin(), v.end(), comp);
 
	ll idx = 0;
	for (auto x : v) {
		for (ll i = 0; i < x.second; i++) {
			a[idx++] = x.first;
		}
	}
	for (ll i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
 
 
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