#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  string S; cin >> S;
  ll count = 0;
  for (char c : S) {
    if (c == 'o') {
      count += 1;
    }
  }
  cout << (count+(15-S.length()) >= 8 ? "YES" : "NO") << endl;
  return 0;
}
