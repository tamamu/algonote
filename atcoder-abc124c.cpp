#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  string S; cin >> S;
  ll f0 = 0;
  ll f1 = 0;
  for (ll j=0; j < S.length(); ++j) {
    if (j % 2 == 0) {
      if (S[j] == '1') {
        f0 += 1;
      }
    } else {
      if (S[j] == '0') {
        f0 += 1;
      }
    }
  }
  for (ll j=0; j < S.length(); ++j) {
    if (j % 2 == 0) {
      if (S[j] == '0') {
        f1 += 1;
      }
    } else {
      if (S[j] == '1') {
        f1 += 1;
      }
    }
  }
  cout << min(f0, f1) << endl;
  return 0;
}
