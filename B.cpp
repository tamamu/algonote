#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  vector<ll> t(5);
  for (ll j=0; j < 5; ++j) cin >> t[j];
  sort(t.begin(), t.end(), [](ll x, ll y) -> bool {
        string xstr = to_string(x), ystr = to_string(y);
        if (xstr.back() == '0') {
          return true;
        }
        if (ystr.back() == '0') {
          return false;
        }
        return xstr.back() > ystr.back();
      });
  ll acc = t[0];
  for (ll j=1; j < 5; ++j) {
    acc += (acc % 10 == 0 ? 0 : (10 - (acc % 10))) + t[j];
  }
  cout << acc << endl;
  return 0;
}
