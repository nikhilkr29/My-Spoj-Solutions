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

ll a[10000];

//Precomputing for all values from 1 to 10000
void precomp() {


  //Initializing with a very large number
  for (ll i = 1; i <= 1000; i++) {
    a[i] = inf;
  }

  //Base Cases

  a[0] = 0;
  a[1] = 1;
  a[2] = 2;
  a[3] = 3;


  //For all the perfect square from 1 to 1000 value will be 1
  for (ll i = 1; i <= 35; i++) {
    a[i * i] = 1;
  }

  //Starting from 4
  for (ll i = 4; i <= 1000; i++) {
    //If it is a perfect square then simply continue
    if (a[i] == 1) {
      continue;
    }
    //Otherwise for all value less than i find the min possible ans
    for (ll j = 1; j < i; j++) {
      //Either a[i] is min or a[j]+a[i-j] is min
      //Time Complexity is O(N^2) O(10^6) very much doable in 1 sec
      a[i] = min(a[i], a[j] + a[i - j]);
    }
  }

}

void solve() {

  ll n;
  cin >> n;
  cout << a[n] << "\n";


}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif

  precomp();

  w(t) {
    solve();
  }
  return 0;
}
