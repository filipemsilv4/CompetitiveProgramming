#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <map>

using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        int n, m;
        cin >> n >> m;

        if (m > n){
            cout << "NO" << endl;
            continue;
        }

        if ((n - m) % 2 != 0){
            cout << "NO" << endl;
            continue;
        }

        cout << "YES" << endl;
    }
}
