#include <iostream>
#include <vector>

int main()
{
    using namespace std;
    int32_t n;
    cin >> n;
    
    vector<int32_t> a(n+1, 0);
    for (auto iter = a.begin()+1; iter != a.end(); ++iter) {
        cin >> *iter;
    }
    
    int32_t count = 0, light = 1;
    while (count <= n && light != 2) {
        light = a[light];
        count++;
    }
    
    if (count > n) {
        count = -1;
    }
    
    cout << count << endl;
}
