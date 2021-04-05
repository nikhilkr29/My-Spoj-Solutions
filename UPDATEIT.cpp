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
 
//Range Sum Query with Updates using A Fenwick Tree
 
ll bit[10002], a[10002];
void update(ll i, ll inc, ll n) {
	while (i <= n) {
		bit[i] += inc;
		i += (i & -i);
	}
}
 
ll quer(ll i) {
	ll sum = 0;
	while (i > 0) {
		sum += bit[i];
		i -= (i & -i);
	}
	return sum;
}
 
void solve() {
 
	ll n, q;
	cin >> n >> q;
	for (ll i = 0; i < q; i++) {
		ll l, r, val;
		cin >> l >> r >> val;
		l++, r++;
		update(l, val, n);
 
		update(r + 1, -val, n);
	}
	ll qu;
	cin >> qu;
	for (ll i = 0; i < qu; i++) {
		ll x;
		cin >> x;
		x++;
		cout << quer(x) << "\n";
	}
 
 
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	w(t) {
		memset(a, 0, sizeof(a));
		memset(bit, 0, sizeof(bit));
		solve();
	}
	return 0;
} 
