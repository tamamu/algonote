#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define eps 0.000001

int main() {
  ll N; cin >> N;
  ll D; cin >> D;
  vector<vector<ll> > X(N, vector<ll>(D));
  for (ll j=0; j < N; ++j)
    for (ll k=0; k < D; ++k)
      cin >> X[j][k];

  ll count = 0;

  for (ll j=0; j < N; ++j) {
    for (ll k=j+1; k < N; ++k) {
      double d = 0;
      for (ll l=0; l < D; ++l) {
        d += (X[j][l] - X[k][l]) * (X[j][l] - X[k][l]);
      }
      d = sqrt(d);
      if (d - (ll)d < eps) count += 1;
    }
  }

  cout << count << endl;
  return 0;
}
