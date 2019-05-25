#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  ll A; cin >> A;
  ll B; cin >> B;
  if (A < 13) {
    B /= 2;
  }
  if (A <= 5) {
    B = 0;
  }
  cout << B << endl;
  return 0;
}
