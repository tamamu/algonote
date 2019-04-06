#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  ll X; cin >> X;
  ll Y; cin >> Y;
  ll Z; cin >> Z;
  ll K; cin >> K;
  vector<ll> A(X);
  for (ll j=0; j < X; ++j) cin >> A[j];
  vector<ll> B(Y);
  for (ll j=0; j < Y; ++j) cin >> B[j];
  vector<ll> C(Z);
  for (ll j=0; j < Z; ++j) cin >> C[j];
  vector<ll> D, E;

  priority_queue<ll> q;
  for (ll j=0; j < X; ++j) {
    for (ll k=0; k < Y; ++k) {
      D.push_back(A[j] + B[k]);
    }
  }
  sort(D.rbegin(), D.rend());

  ll len = min(K, static_cast<ll>(D.size()));
  for (ll j=0; j < len; ++j) {
    for (ll k=0; k < Z; ++k) {
      E.push_back(D[j] + C[k]);
    }
  }
  sort(E.rbegin(), E.rend());

  for (ll j=0; j < K; ++j) {
    cout << E[j] << endl;
  }
  return 0;
}
