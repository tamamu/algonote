#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

int main()
{
    using namespace std;
    int64_t N, left=0, right=1e9;
    cin >> N;
    vector<int64_t> a(N);
    
    for (auto j = 0; j < N; j++) {
        cin >> a[j];
        left = max(left, a[j]);
    }
    
    sort(a.begin(), a.end());
    
    left = a[N-1];
    int32_t min = left;
    for (auto j = 0; j < N-1; j++) {
        auto d = abs(a[j] - left/2);
        if (d <= min) {
            min = d;
            right = a[j];
        }
    }
    
    cout << left << " " << right << endl;
}
