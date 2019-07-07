#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  ll L; cin >> L;
  ll R; cin >> R;
  ll _L = L % 2019;
  ll _R = R % 2019;
  if (R-L >= 2019) _R += 2019;
  if (_L > _R) swap(_L, _R);
  ll m = 1000000000;
  for (ll j=_L; j <= _R; ++j) {
    for (ll k=j+1; k <= _R; ++k) {
      m = min(m, (j*k)%2019);
    }
  }
  cout << m << endl;
  return 0;
}
