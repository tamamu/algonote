#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  ll n; cin >> n;
  vector<ll> p(n);
  for (ll j=0; j < n; ++j) cin >> p[j];
  ll count = 0;
  for (int j=1; j < n-1; ++j) {
    vector<ll> v = {p[j-1], p[j], p[j+1]};
    sort(v.begin(), v.end());
    if (v[1] == p[j]) count++;
  }
  cout << count << endl;
  return 0;
}
