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
 
ll n, m;
 
struct edge {
 
	ll a, b, w;
};
 
 
vector<edge> v;
vector<ll> par;
 
 
 
bool comp(edge e1, edge e2) {
	return e1.w < e2.w;
}
 
 
 
ll getp(ll x) {
 
	if (par[x] == -1) {
		return x;
	}
	return par[x] = getp(par[x]);
}
 
 
void unite(ll x, ll y) {
 
	x = getp(x);
	y = getp(y);
	par[x] = y;
}
 
 
void solve() {
 
	v.clear();
	par.clear();
	v.resize(m + 1);
	par.assign(n + 1, -1);
 
	ll tot = 0;
	for (ll i = 0; i < m; i++) {
		cin >> v[i].a >> v[i].b >> v[i].w;
		tot += v[i].w;
	}
 
	sort(v.begin(), v.end(), comp);
 
	ll res = 0;
	for (ll i = 0; i < m; i++) {
		if (getp(v[i].a) != getp(v[i].b)) {
			unite(v[i].a, v[i].b);
			res += v[i].w;
		}
	}
 
	cout << tot - res << "\n";
 
 
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("inp.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	while (1) {
		cin >> n >> m;
		if (n == 0 && m == 0) {
			break;
		}
		solve();
	}
	return 0;
} 