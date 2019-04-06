#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main() {
  double N; cin >> N;
  vector<double> t(5);
  for (ll j=0; j < 5; ++j) cin >> t[j];
  ll time;
  sort(t.begin(), t.end());
  if (t[0] >= N) {
    time = 5;
  } else {
    time = static_cast<ll>(ceil(N/t[0])) + 4;
  }
  cout << time << endl;
  return 0;
}
