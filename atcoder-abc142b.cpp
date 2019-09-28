#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  ll N; cin >> N;
  ll K; cin >> K;
  vector<ll> h(N);
  for (ll j=0; j < N; ++j) cin >> h[j];
  sort(h.begin(), h.end());
  ll ans = 0;
  for (ll j=0; j < N; ++j) {
    if (h[j] >= K) ans++;
  }
  cout << ans << endl;
  return 0;
}
