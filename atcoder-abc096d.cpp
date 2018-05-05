#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool IsPrime(int num)
{
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false;

    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2)
    {
        if (num % i == 0)
        {
            return false;
        }
    }

    return true;
}

int main() {
    int N;
    cin >> N;
    vector<int> s(N);
    int n = 0;
    for (int j=2; n < N; j++) {
        if ((j-1) % 10 == 0 && IsPrime(j)) {
            s[n] = j;
            n++;
        }
    }
    for (int j=0; j < N; j++) {
        if (j==N-1) {
            cout << s[j] << endl;
        } else {
            cout << s[j] << " ";
        }
    }
}
