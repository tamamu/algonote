#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  ll H; cin >> H;
  ll W; cin >> W;
  vector<ll> P(H*W*2);
  vector<vector<ll> > X(H, vector<ll>(W));
  vector<vector<ll> > Y(H, vector<ll>(W));
  vector<string> S(H);
  for (ll j=0; j < H; ++j) cin >> S[j];
  ll iter = 0;
  for (ll j=0; j < W; ++j) {
    for (ll k=0; k < H; ++k) {
      if (S[k][j] == '#') {
        iter += 1;
      } else {
        P[iter] += 1;
        Y[k][j] = iter;
      }
    }
    iter += 1;
  }
  iter += 1;
  for (ll j=0; j < H; ++j) {
    for (ll k=0; k < W; ++k) {
      if (S[j][k] == '#') {
        iter += 1;
      } else {
        P[iter] += 1;
        X[j][k] = iter;
      }
    }
    iter += 1;
  }

  ll ans = 0;
  for (ll j=0; j < H; ++j) {
    for (ll k=0; k < W; ++k) {
      ans = max(ans, P[X[j][k]]+P[Y[j][k]]-1);
    }
  }
  cout << ans << endl;
  return 0;
}
