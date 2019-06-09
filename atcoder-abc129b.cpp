#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  ll N; cin >> N;
  vector<ll> W(N);
  ll sum = 0;
  for (ll j=0; j < N; ++j){
    cin >> W[j];
    sum += W[j];
  }
  ll ans = 100000001;
  ll acc = 0;
  for (ll j=0; j < N; ++j) {
    acc += W[j];
    ans = min(ans, abs((sum-acc)-acc));
  }
  cout << ans << endl;
  return 0;
}
