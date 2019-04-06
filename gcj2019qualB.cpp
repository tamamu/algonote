#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve(ll x, ll N, string P) {
  for (ll j=0; j < P.length(); ++j) {
    P[j] = P[j] == 'E' ? 'S' : 'E';
  }
  cout << "Case #" << x << ": " << P << endl;
}

int main() {
  ll T; cin >> T;
  vector<ll> N(T);
  vector<string> P(T);
  for (ll j=0; j < T; ++j) cin >> N[j] >> P[j];
  for (ll j=0; j < T; ++j) solve(j+1, N[j], P[j]);
  return 0;
}
