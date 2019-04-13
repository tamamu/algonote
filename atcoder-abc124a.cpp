#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  ll A; cin >> A;
  ll B; cin >> B;
  ll x = max(A, B);
  if (x == A) {
    A--;
  } else {
    B--;
  }
  x += max(A, B);
  cout << x << endl;
  return 0;
}
