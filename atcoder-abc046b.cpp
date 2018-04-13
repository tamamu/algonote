#include <iostream>
#include <cmath>

int main()
{
    using namespace std;
    int32_t N, K, result;
    cin >> N >> K;
    
    result = K;
    
    for (auto j = 0; j < N-1; j++) {
        result *= K-1;
    }
    
    cout << result << endl;
}
