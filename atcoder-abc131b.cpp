#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  ll N; cin >> N;
  ll L; cin >> L;
  ll m = 0;
  for (ll j=0; j < N; ++j) {
    m += j+L;
  }
  ll mm = 1000000000;
  ll x = -10000000;
  for (ll j=0; j < N; ++j) {
    if (mm > abs(m-(m-j-L))) {
      mm = abs(m-(m-j-L));
      x = j+L;
    }
  }
  cout << (m-x) << endl;
}
