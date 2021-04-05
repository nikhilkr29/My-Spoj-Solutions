#include<bits/stdc++.h>
using namespace std;
#define ll long long int
 
 
void merge(ll a[], ll s, ll e) {
 
	ll m = s + (e - s) / 2;
	ll i = s, j = m + 1, k = s;
	ll temp[100005];
 
	while (i <= m && j <= e) {
		if (a[i] <= a[j]) {
			temp[k++] = a[i++];
		}
		else {
			temp[k++] = a[j++];
		}
	}
	while (i <= m) {
		temp[k++] = a[i++];
	}
	while (j <= e) {
		temp[k++] = a[j++];
	}
 
	for (ll i = s; i <= e; i++) {
		a[i] = temp[i];
	}
 
 
}
 
void merge_sort(ll a[], ll s, ll e) {
 
	if (s >= e) {
		return;
	}
 
	ll mid = s + (e - s) / 2;
	merge_sort(a, s, mid);
	merge_sort(a, mid + 1, e);
	merge(a, s, e);
}
 
bool ispossible(ll a[], ll mid, ll c, ll n) {
 
	ll co = 1, re = a[0];
 
	for (ll i = 1; i < n; i++) {
		if (a[i] - re >= mid) {
			co++;
			re = a[i];
		}
		if (co == c) {
			return true;
		}
	}
	return false;
 
}
void solve() {
 
	ll n, c;
	cin >> n >> c;
	ll a[n];
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
	}
	merge_sort(a, 0, n - 1);
 
	ll s = 1, e = a[n - 1];
 
	ll ans = 1;
 
	while (s <= e) {
 
		ll mid = s + (e - s) / 2;
		if (ispossible(a, mid, c, n)) {
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
	freopen("output.txt", "w", stdout);
#endif
 
	ll t;
	cin >> t;
	while (t--) {
		solve();
	}
 
 
	return 0;
} 