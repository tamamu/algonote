#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  string S; cin >> S;
  ll K; cin >> K;
  ll count1 = 0;
  for (ll j=0; j < S.length(); ++j) {
    if (S[j] == '1') {
      count1 += 1;
    } else {
      break;
    }
  }
  if (K <= count1) {
    cout << 1 << endl;
  } else {
    cout << S[count1] << endl;
  }
  return 0;
}
