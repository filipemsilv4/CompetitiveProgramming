/*
g++ -std=c++17 -o bin/out string_hashing.cpp && ./bin/out
*/

#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <map>

#define lli long long int
#define ulli unsigned long long int

using namespace std;

int main(){
    string s;
    lli q;
    cin >> s >> q;

    // HASHING
    const lli p = 31;
    const lli p2 = 30000;
    const lli m = 1e9 + 9;
    const lli m2 = 1e9 + 7;
    const lli n = s.size();
    lli S = s.size();

    vector<lli> p_pow(S);
    vector<lli> p_pow2(S);
    p_pow2[0] = p_pow[0] = 1;
    for (lli i = 1; i < p_pow.size(); i++){
        p_pow[i] = (p_pow[i - 1] * p) % m;
        p_pow2[i] = (p_pow2[i - 1] * p2) % m2;
    }
    vector<lli> h(n + 1, 0);
    vector<lli> h2(n + 1, 0);
    for (lli i = 0; i < n; i++){
        h[i+1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % m;
        h2[i+1] = (h2[i] + (s[i] - 'a' + 1) * p_pow2[i]) % m2;
    }

    while (q--){
        lli l, r;
        cin >> l >> r;

        lli cur_h = (h[r] + m - h[l]) % m;
        cur_h = (cur_h * p_pow[n-l-1]) % m;
        lli cur_h2 = (h2[r] + m2 - h2[l]) % m2;
        cur_h2 = (cur_h2 * p_pow2[n-l-1]) % m2;

        // cout << "---> ";
        cout << cur_h << cur_h2 << endl;
    }
}
