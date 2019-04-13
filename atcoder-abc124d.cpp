#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  ll N; cin >> N;
  ll K; cin >> K;
  string S; cin >> S;
  vector<ll> seq;
  ll initial = S[0] - '0';
  ll stat = 1;
  for (ll j=1; j < N; ++j) {
    if (S[j-1] == S[j]) {
      stat += 1;
    } else {
      seq.push_back(stat);
      stat = 1;
    }
  }
  if (stat > 0) seq.push_back(stat);
  ll ans = 0;
  if (seq.size() == 1) {
    cout << seq[0] << endl;
  } else {
    for (ll j=1; )
  }
  return 0;
}
