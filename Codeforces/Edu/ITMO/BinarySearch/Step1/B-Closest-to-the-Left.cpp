/*
g++ -std=c++17 -o bin/out B-Closest-to-the-Left.cpp && ./bin/out
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
#define bi 1000000000

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    vector<int> vec(n);
    for (int i = 0; i < n; i++){
        cin >> vec[i];
    }

    for (int i = 0, q; i < k; i++){
        cin >> q;
        // cout << "\n -------- " << q << " -------\n";
        int m;
        int l = -1, r = n;
        while (r > l + 1){
            m = (l + r) / 2;
            // cout << "m = " << l << "+" << r << "/2  =  " << m << "\n";
            if (vec[m] > q){
                r = m;
                continue;
            }
            l = m;
        }

        // cout << "----> ";

        if (l < 0 || l >= n){
            cout << "0\n";
            continue;
        }

        cout << l+1 << "\n";
    }
}
