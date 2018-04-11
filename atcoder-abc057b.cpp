#include <iostream>
#include <vector>
#include <tuple>
#include <limits>

int main()
{
    using namespace std;
    int32_t n, m;
    cin >> n;
    cin >> m;
    
    vector<tuple<int32_t, int32_t>> students(n), check(m);
    for (auto j = 0; j < n; ++j) {
        int32_t x, y;
        cin >> x;
        cin >> y;
        students[j] = make_tuple(x, y);
    }

    for (auto j = 0; j < m; ++j) {
        int32_t x, y;
        cin >> x;
        cin >> y;
        check[j] = make_tuple(x, y);
    }
    
    for (auto iter = students.begin(); iter != students.end(); ++iter) {
        int32_t x1, y1;
        tie(x1, y1) = *iter;
        int32_t nearest_diff = numeric_limits<int32_t>::max();
        auto nearest = -1;
        for (auto j = 0; j < m; ++j) {
            int32_t x2, y2;
            tie(x2, y2) = check[j];
            auto diff = abs(x1-x2) + abs(y1-y2);
            if (diff < nearest_diff) {
                nearest_diff = diff;
                nearest = j+1;
            }
        }
        cout << nearest << endl;
    }
}
