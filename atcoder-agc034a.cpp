#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  ll N; cin >> N;
  ll A; cin >> A;
  ll B; cin >> B;
  ll C; cin >> C;
  ll D; cin >> D;
  string S; cin >> S;
  bool jumpable = false;
  ll cnt = 0;
  for (ll j=B-2; j < D+1; ++j) {
    if (S[j] == '.') {
      cnt += 1;
      if (cnt >= 3) {
        jumpable = true;
        break;
      }
    } else {
      cnt = 0;
    }
  }
  bool sunuke = false, funuke = false;
  ll j;
  for (j=A-1; j < C-1; ++j) {
    if (S[j+1]=='#' && S[j+2]=='#') {
      break;
    }
  }
  if (j == C-1) sunuke = true;
  if (C > D && !jumpable) sunuke = false;
  for (j=B-1; j < D-1; ++j) {
    if (S[j+1]=='#' && S[j+2]=='#') {
      break;
    }
  }
  if (j == D-1) funuke = true;
  cout << (sunuke && funuke ? "Yes" : "No") << endl;
  return 0;
}
