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

  ll n, k;
  cin >> n >> k;

  ll a[n], b[n];
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (ll i = 0; i < n; i++) {
    cin >> b[i];
  }

  ll prev;
  ll i = 1;

  for (i = 1; i < n; i++) {
    prev = a[i]; //a[i] ko abhi modify krdenge islie iska pichla value store krke rkhna zrrori hai

    //Options for a[i]
    ll opa1 = a[i] + a[i - 1]; //Pichle a[i-1] station se a[i] pr aa jae
    ll opa2 = a[i] + b[i - 1] + b[i]; //Pehle b wale station pr tha waha se b[i] pr aaya or ab waha se a[i] pr
    a[i] = min(opa1, opa2); //Dono Option me jo min hoga woh krega

    //Options for b[i]
    ll opb1 = b[i] + b[i - 1]; //Pichle b[i-1] station se  b[i] pr aa jae
    ll opb2 = b[i] + a[i - 1] + prev; //Pehle a[i-1] wale station pr tha waha se a[i] pr aaya or ab waha se b[i] pr
    //But humne a[i] ko modify kr dia hai islie prev use kr rhe a[i] k place pr
    b[i] = min(opb1, opb2); //Dono Option me jo min hoga woh krega

    if (min(a[i], b[i]) > k) {
      break; //Agr min a[i] or b[i] ka K se zyada ho gya hai toh we will simply break
    }
  }

  //Ab hum jo i pr hai uska value ya toh n hoga ya aisa station hoga jiska min value k se zyada hai
  //Islie hum iske ek pehle wala station pr jaenge lekin station ka idx print krte tym humlog ith print krenge
  //Kyuki idx 1th base hai ques me or humlog 0th base lekr chal rhe but value of people  min(a[i-1],b[i-1])


  cout << i << " " << min(a[i - 1], b[i - 1]) << "\n";

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