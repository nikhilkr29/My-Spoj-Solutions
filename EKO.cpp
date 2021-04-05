#include<bits/stdc++.h>
using namespace std;
#define  vi vector<long long int>
#define  set1 set<long long int>
#define  pb push_back
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
 
bool isvalid(ll a[], ll mid, ll n, ll m) {
	ll co = 0;
	for (ll i = 0; i < n; i++) {
		if (a[i] >= mid) {
			co += (a[i] - mid);
		}
	}
 
	if (co >= m) {
		return true;
	}
	return false;
}
 
void solve() {
 
	ll n, m;
	cin >> n >> m;
 
	ll a[n];
 
	ll mx = 0;
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
		mx = max(mx, a[i]);
	}
 
	ll s = 0, e = mx, ans = 0;
 
	while (s <= e) {
		ll mid = s + (e - s) / 2;
		if (isvalid(a, mid, n, m)) {
			ans = mid;
			s = mid + 1;
		}
		else {
			e = mid - 1;
		}
	}
 
	cout << ans << "\n";
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