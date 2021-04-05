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
 
 
void solve() {
 
	ll n;
	cin >> n;
 
	set1 s, d;
	while (n--) {
		ll id;
		cin >> id;
		d.ins(id);
 
		ll no;
		cin >> no;
		for (ll i = 0; i < no; i++) {
			ll x;
			cin >> x;
			s.ins(x);
		}
	}
 
	for (auto x : d) {
		if (s.find(x) != s.end()) {
			s.erase(x);
		}
	}
 
	cout << s.size() << "\n";
 
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