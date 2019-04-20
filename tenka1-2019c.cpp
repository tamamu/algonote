#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  ll N; cin >> N;
  string S; cin >> S;
  ll black = 0, white = 0, ans = N;
  for (ll j=0; j < N; ++j) {
    if (S[j] == '#') {
      black += 1;
    } else {
      white += 1;
    }
  }
  ll tb = 0, tw = 0;
  for (ll j=0; j < N; ++j) {
    ans = min(ans, tb + (white-tw));
    if (S[j] == '#') {
      tb += 1;
    } else {
      tw += 1;
    }
  }
  ans = min(ans, tb + (white-tw));
  cout << ans << endl;
  return 0;
}
