/*
g++ -std=c++17 -o bin/out a.cpp && ./bin/out
*/

#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <map>

#define lli long long int
#define ulli unsigned long long int
#define endl "\n"

using namespace std;

int main(){
    lli t;
    cin >> t;
    while (t--){
        // The only line of each test case contains four integers a, b, x, y
        // (1 ≤ a, b ≤ 100, 1 ≤ x, y ≤ 10^7)
        // — the two integers given to you and the respective costs of two types of operations.
        lli a, b, x, y; cin >> a >> b >> x >> y;

        // cout << "----> ";

        if (a == b){
            cout << 0 << endl;
            continue;
        }

        if (a > b){
            if (a % 2 != 0 && a == b + 1){
                cout << y << endl;
                continue;
            }
            cout << -1 << endl;
            continue;
        }

        lli diff = b - a;

        if (x <= y) {
            cout << diff * x << endl;
        } else {
            lli ans;
            if (a % 2 == 0) {
                ans = ((diff + 1) / 2) * y + (diff / 2) * x;
            } else {
                ans = ((diff + 1) / 2) * x + (diff / 2) * y;
            }
            cout << ans << endl;
        }
    }
}
