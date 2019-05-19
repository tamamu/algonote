#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  string S; cin >> S;
  bool yymm = false, mmyy = false;
  if ((S[2] == '0' && S[3] != '0') || (S[2] == '1' && (S[3] == '1' || S[3] == '2' || S[3] == '0'))) yymm = true;
  if ((S[0] == '0' && S[1] != '0') || (S[0] == '1' && (S[1] == '1' || S[1] == '2' || S[1] == '0'))) mmyy = true;
  if (yymm && mmyy) {
    cout << "AMBIGUOUS" << endl;
  } else if (yymm) {
    cout << "YYMM" << endl;
  } else if (mmyy) {
    cout << "MMYY" << endl;
  } else {
    cout << "NA" << endl;
  }
  return 0;
}
