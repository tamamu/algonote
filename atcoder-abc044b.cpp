#include <iostream>
#include <vector>

int main()
{
    using namespace std;
    string w;
    cin >> w;
    
    vector<char> count(26);
    bool flag = true;
    
    for (auto iter = w.begin(); iter != w.end(); ++iter) {
        auto idx = *iter - 'a';
        count[idx] += 1;
    }
    
    for (auto iter = count.begin(); iter != count.end(); ++iter) {
        if (*iter % 2 != 0) {
            flag = false;
            break;
        }
    }
    
    if (flag) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
