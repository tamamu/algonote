#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ll N, red=0;
  string s;
  cin >> N >> s;
  for (ll j=0; j < N; ++j) {
    if (s[j] == 'R') {
      red += 1;
    }
  }
  cout << (red > N-red ? "Yes" : "No") << endl;
}
