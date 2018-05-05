#include <iostream>
#include <vector>
#include <cmath>
#include <tuple>
#include <algorithm>

using namespace std;

int main()
{
    int c = 0;
    vector<int> n(5), m(10);
    for (auto i = 0; i < 5; ++i) {
        cin >> n[i];
    }
    for (auto j = 0; j < 5; ++j) {
        for (auto k = j+1; k < 5; ++k) {
            for (auto l = k+1; l < 5; ++l) {
                m[c] = n[j] + n[k] + n[l];
                c += 1;
            }
        }
    }

    sort(m.begin(), m.end());
    
    cout << m[7] << endl;
}
