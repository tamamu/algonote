#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool table[201];

void make_table() {
  for (ll j=2; j < 201; ++j) {
    table[j] = true;
  }
  for (ll j=2; j < 201; ++j) {
    if (!table[j]) continue;
    for (ll k=j+j; k < 201; k+=j) {
      table[k] = false;
    }
  }
}

int main() {
  ll N; cin >> N;
  ll ans = 0;
  make_table();
  for (ll j=1; j <= N; j+=2) {
    ll num = j;
    ll count = 1;
    for (ll k=j-1; k > 0; --k) {
      if (!table[k]) continue;
      ll ex = 0;
      while (num > 0 && num % k == 0) {
        num /= k;
        ex += 1;
      }
      count *= ex+1;
    }
    if (count == 8) {
      ans += 1;
    }
  }
  cout << ans << endl;
  return 0;
}
