/*
g++ -std=c++17 -o bin/out c1.cpp && ./bin/out
*/

#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <math.h>
#include <iomanip>

#define lli long long int
#define ulli unsigned long long int
#define endl "\n"
#define bi 1000000000

using namespace std;

int main(){
    lli t;
    cin >> t;
    while (t--){
        lli n, m; cin >> n >> m;
        vector<lli> a(n);
        vector<lli> b(m);

        for (lli i = 0; i < n; i++) cin >> a[i];
        for (lli i = 0; i < m; i++) cin >> b[i];

        // cout << "-----> ";

        if (a[0] > b[0] - a[0]) a[0] = b[0] - a[0];
        bool ok = false;
        for (lli i = 1; i < n; i++){
            lli op = b[0] - a[i];
            // cout << "a[i]=" << a[i] << " | a[i-1]=" << a[i-1] << " | op=" << op << "\n";

            if (a[i] < a[i-1]) a[i] = op;
            if (op < a[i] && op >= a[i-1]) a[i] = op;
            if (a[i-1] > a[i]){
                cout << "NO" << "\n";
                ok = true;
                break;
            }
        }

        if (ok) continue;

        cout << "YES" << "\n";
    }
}
