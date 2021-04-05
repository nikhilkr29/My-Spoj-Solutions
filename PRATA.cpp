#include<bits/stdc++.h>
using namespace std;
#define  vi vector<long long int>
#define  set1 set<long long int>
#define  pb push_back
#define  map1 map<long long int,long long int>
#define  ll   long long int
#define  mp make_pair
#define  inf INT_MAX
#define  minf INT_MIN
#define  setbits(x) __builtin_popcountll(x)
#define  pres(x,y) fixed<<setprecision(y)<<x
#define  pair1 pair<long long int,long long int>
#define  mk(arr,n,type) type *arr=new type[n];
#define  mod 1000000007
#define  w(t) long long int t;cin>>t; while(t--)
#define ins insert
 
bool isvalid(ll a[], ll n, ll m, ll p) {
 
	ll r = 0;
	for (ll i = 0; i < n; i++) {
		ll k = a[i], b = 0;
		while (b + k <= m) {
			r++;
			if (r >= p) {
				break;
			}
 
			b += k;
			k += a[i];
			//cout << b << " " << a[i] << " " << m << "\n";
		}
 
		if (r >= p) {
			break;
		}
	}
	if (r >= p) {
		return true;
	}
	return false;
 
 
}
 
void solve() {
 
	ll p;
	cin >> p;
	ll n;
	cin >> n;
	ll a[n];
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
	}
 
	sort(a, a + n);
 
	ll res = 0, st = 0, k = a[0];
	while (st < p) {
		res += k;
		k += a[0];
		st++;
	}
 
	ll s = 0, e = res, ans = res;
	while (s <= e) {
		ll mid = s + (e - s) / 2;
		if (isvalid(a, n, mid, p)) {
			ans = mid;
			e = mid - 1;
		}
		else {
			s = mid + 1;
		}
	}
	cout << ans << "\n";
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
#endif
	w(t) {
		solve();
	}
	return 0;
} 