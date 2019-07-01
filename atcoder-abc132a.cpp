#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  string S; cin >> S;
  set<char> m;
  for (char c : S) {
    m.insert(c);
  }
  cout << (m.size() == 2 ? "Yes" : "No") << endl;
  return 0;
}
