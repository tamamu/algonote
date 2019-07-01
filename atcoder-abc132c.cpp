#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  ll N; cin >> N;
  vector<ll> d(N);
  for (ll j=0; j < N; ++j) cin >> d[j];
  sort(d.begin(), d.end());
  cout << (d[N/2]-d[N/2-1]) << endl;
  return 0;
}
