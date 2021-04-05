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
#define  w(t) long long int t;cin>>t;while(t--)
 
vector<vector<ll>> adj;
 
bool isprime(ll x) {
 
	for (ll i = 2; i <= sqrt(x); i++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}
 
 
bool isvalid(ll x, ll y) {
 
	ll co = 0;
	while (x > 0) {
		ll rem = x % 10;
		ll rem1 = y % 10;
		if (rem != rem1) {
			co++;
		}
		x /= 10;
		y /= 10;
	}
	if (co == 1) {
		return true;
	}
	return false;
}
 
 
void solve() {
 
	ll x, y;
	cin >> x >> y;
 
	if (x == y) {
		cout << 0 << "\n";
		return;
	}
 
	ll dis[100005];
	memset(dis, 0, sizeof(dis));
 
	dis[x] = 0;
	queue<ll> q;
	q.push(x);
 
 
 
	while (q.empty() == false && dis[y] == 0) {
 
		ll node = q.front();
		q.pop();
 
		for (auto x1 : adj[node]) {
			if (dis[x1] == 0) {
				dis[x1] = dis[node] + 1;
				q.push(x1);
			}
		}
	}
 
	cout << dis[y] << "\n";
 
 
 
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("inp.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
 
	adj.resize(100000);
 
	vi primes;
 
 
	for (ll i = 1000; i <= 9999; i++) {
		if (isprime(i)) {
			primes.pb(i);
		}
	}
 
 
	for (ll i = 0; i < primes.size(); i++) {
		for (ll j = i + 1; j < primes.size(); j++) {
			if (isvalid(primes[i], primes[j])) {
				adj[primes[i]].pb(primes[j]);
				adj[primes[j]].pb(primes[i]);
			}
		}
	}
 
 
	w(t) {
		solve();
	}
	return 0;
} 