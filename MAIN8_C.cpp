#include<bits/stdc++.h>
using namespace std;
#define  vi vector<long int>
#define  set1 set<long long int>
#define  pb push_back
#define  map1 map<long long int,long long int>
#define  ll long int
#define  mp make_pair
#define  inf 1e9
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
 
bool isval(vi &a, ll mid, ll n, ll k) {
 
	ll co = 0;
	for (ll i = 0; i < n && co < k; i++) {
		if (a[i] >= mid) {
			co += a[i] / mid;
		}
	}
 
 
	if (co >= k) {
		return true;
	}
	return false;
}
 
void solve() {
 
	ll n, k;
	cin >> n >> k;
 
	ll s = 0, e = 0, ans = 0;
 
	vi a(n);
 
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
		e += a[i];
	}
 
	sort(a.begin(), a.end(), greater<int>());
 
	while (s <= e) {
		ll mid = s + (e - s + 1) / 2;
 
		if (mid == 0) {
			cout << 0 << "\n";
			return;
		}
 
		if (isval(a, mid, n, k)) {
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