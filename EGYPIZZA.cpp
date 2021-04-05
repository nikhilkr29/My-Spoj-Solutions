#include<bits/stdc++.h>
#include<stdio.h>
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
 
 
void solve() {
 
	ll n;
	cin >> n;
	ll co = 1;
 
	if (n == 1) {
		cout << 0 << "\n";
		return;
	}
 
 
 
 
	ll a = 0, b = 0, c = 0;
 
	for (ll i = 0; i < n; i++) {
		string x;
		cin >> x;
		if (x == "3/4")a++;
		else if (x == "1/2")b++;
		else c++;
	}
 
 
	co += a;
 
	c -= min(c, a);
 
	if (b > 0) {
 
		if (b == 1) {
			co++;
			c -= min(c, 2ll);
		}
		else {
			co += (b / 2);
			if (b % 2 != 0) {
				co += 1;
				c -= min(c, 2ll);
			}
		}
	}
 
	if (c > 0) {
		if (c < 4)co++;
		else {
			co += c / 4;
			if (c % 4 != 0) {
				co++;
			}
		}
	}
 
	cout << co << "\n";
 
 
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