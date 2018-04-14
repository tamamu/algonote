    #include <iostream>
    #include <vector>
    #include <algorithm>
    #include <queue>
     
    int main()
    {
        using namespace std;
        int32_t N;
        cin >> N;
     
        vector<int32_t> X1(N), X2(N);
        for (auto j=0; j < N; ++j) {
            int32_t n;
            cin >> n;
            X1[j] = X2[j] = n;
        }
        
        int32_t half = N / 2;
        
        sort(X1.begin(), X1.end());
        int32_t left=X1[half-1], right=X1[half];
        
        for (auto j = 0; j < N; j++) {
            if (X2[j] < right) {
                cout << right << endl;
            } else {
                cout << left << endl;
            }
        }
        
    }
