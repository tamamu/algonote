#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  string S; cin >> S;
  char pre = ' ';
  bool flag = false;
  for (char ch : S) {
    if (ch == pre) {
      flag = true;
      break;
    }
    pre = ch;
  }
  cout << (flag ? "Bad" : "Good") << endl;
  return 0;
}
