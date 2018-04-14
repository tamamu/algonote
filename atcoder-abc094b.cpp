#include <iostream>
#include <vector>

int main()
{
    using namespace std;
    int32_t N, M, X;
    cin >> N >> M >> X;

    vector<int32_t> A(N+1, 0);
    for (auto j=0; j < M; ++j) {
        int32_t idx;
        cin >> idx;
        A[idx] = 1;
    }
    
    int32_t left=0, right=0;
    for (auto j=X; j < N; ++j) {
        right += A[j];
    }
    
    for (auto j=X; 0 < j; --j) {
        left += A[j];
    }
    
    cout << min(left, right) << endl;
}
