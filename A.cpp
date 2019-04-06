#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  vector<ll> p(5);
  for (ll j=0; j < 5; ++j) cin >> p[j];
  ll k; cin >> k;
  bool flag = true;
  for (ll j=0; j < 4; ++j) {
    for (ll l=j+1; l < 5; ++l) {
      if (p[l] - p[j] > k) {
        flag = false;
        break;
      }
    }
  }
  cout << (flag ? "Yay!" : ":(") << endl;

  return 0;
}
