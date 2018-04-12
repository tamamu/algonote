#include <iostream>
#include <algorithm>

int main()
{
    using namespace std;
    int32_t N;
    string S;
    cin >> N;
    cin >> S;
    
    int32_t x=0, xmax=0;
    for (auto iter = S.begin(); iter != S.end(); ++iter) {
        if (*iter == 'I') {
            x += 1;
        } else {
            x -= 1;
        }
        xmax = max(x, xmax);
    }
    
    cout << xmax << endl;
}
