#include <iostream>

int main()
{
    using namespace std;
    int32_t K, S;
    cin >> K >> S;
    
    int32_t count = 0;
    
    for (auto X = 0; X <= K; ++X) {
        for (auto Y = 0; Y <= K; ++Y) {
            auto Z = S - X - Y;
            if (0 <= Z && Z <= K) {
                count += 1;
            }
        }
    }
    
    cout << count << endl;
}
