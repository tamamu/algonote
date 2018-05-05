#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> v(3);
    cin >> v[0] >> v[1] >> v[2];
    int k;
    cin >> k;
    sort(v.begin(), v.end());
    int sum = v[2];
    for (auto i=0; i < k; ++i) {
        sum *= 2;
    }
    sum += v[0] + v[1];
    cout << sum << endl;
}
