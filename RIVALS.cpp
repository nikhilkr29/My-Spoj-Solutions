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
 
 
ll power(ll a, ll x) {
 
	if (x == 0) {
		return 1;
	}
	if (x == 1) {
		return a;
	}
 
	ll half = power(a, x / 2);
	ll ans = (half % mod * half % mod) % mod;
 
 
	if (x % 2 == 0) {
		return ans % mod;
	}
	return (ans % mod * a % mod) % mod;
 
 
}
 
 
ll modinv(ll a, ll b) {
 
 
	ll k = power(b, mod - 2);
 
	return (a * k) % mod;
 
}
 
 
 
ll fact[2000005];
 
void solve() {
 
	ll x, y;
	cin >> x >> y;
 
	if (x == 0 && y == 0) {
		cout << 1 << "\n";
		return;
	}
 
	ll num = fact[x + y];
 
	ll fir = modinv(num, fact[x]);
 
 
 
	ll ans = modinv(fir, fact[y]);
 
	cout << ans << "\n";
 
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("inp.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
 
	fact[0] = 1;
	fact[1] = 1;
 
	for (ll i = 2; i <= 2000000; i++) {
		fact[i] = ((fact[i - 1] % mod) * (i % mod)) % mod;
	}
 
	w(t) {
		solve();
	}
	return 0;
} 