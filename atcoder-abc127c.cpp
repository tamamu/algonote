#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  ll N; cin >> N;
  ll M; cin >> M;
  vector<ll> L(M);
  vector<ll> R(M);
  for (ll j=0; j < M; ++j) cin >> L[j] >> R[j];
  sort(L.rbegin(), L.rend());
  sort(R.begin(), R.end());
  ll ans = R[0]-L[0]+1;
  cout << (ans >= 0?ans:0) << endl;
  return 0;
}
