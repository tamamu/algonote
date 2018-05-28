#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int solve()
{
    int n, m, result=0;
    cin >> n >> m;
    if (n == 0 && m == 0) return -1;

    vector<int> a(n);
    int expensiveCount = 0;
    for (int j=0; j < n; ++j) {
        cin >> a[j];
        if (a[j] > m) expensiveCount++;
    }
    if (expensiveCount >= n-1) {
        cout << "NONE" << endl;
    } else {
        for (int j=0; j < n; ++j) {
            for (int k=j+1; k < n; ++k) {
                int sum = a[j]+a[k];
                if (sum <= m) result = max(result, sum);
            }
        }
        if (result > 0) {
            cout << result << endl;
        } else {
            cout << "NONE" << endl;
        }
    }
    
    return 0;
}

int main()
{
    while(solve() != -1);
}
