#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  ll r; cin >> r;
  ll D; cin >> D;
  ll x; cin >> x;
  for (ll j=0; j < 10; ++j) {
    x = r*x - D;
    cout << x << endl;
  }
  return 0;
}
