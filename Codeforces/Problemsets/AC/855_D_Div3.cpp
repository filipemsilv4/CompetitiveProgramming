/*
g++ -std=c++17 -o bin/out 855_D_Div3.cpp && ./bin/out
*/

#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <vector>

#define lli long long int
#define ulli unsigned long long int
#define endl "\n"
#define bilhao 1000*1000*1000

using namespace std;

int main() {
  lli t;
  cin >> t;
  while (t--) {
    lli n;
    string s;
    cin >> n >> s;

    // string hashing
    const lli p = 521, p2 = 1427, p3 = 101, p4 = 2203;
    const lli m = bilhao + 97, m2 = bilhao + 7, m3 = bilhao + 21, m4 = bilhao + 33;

    vector<lli> p_pow(n), p_pow2(n), p_pow3(n), p_pow4(n);
    p_pow[0] = p_pow2[0] = p_pow3[0] = p_pow4[0] = 1;

    for (lli i = 1; i < n; i++) {
      p_pow[i] = (p_pow[i - 1] * p) % m;
      p_pow2[i] = (p_pow2[i - 1] * p2) % m2;
      p_pow3[i] = (p_pow3[i - 1] * p3) % m3;
      p_pow4[i] = (p_pow4[i - 1] * p4) % m4;
    }

    vector<lli> h(n + 1, 0), h2(n + 1, 0), h3(n + 1, 0), h4(n + 1, 0);
    for (lli i = 0; i < n; i++) {
      h[i + 1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % m;
      h2[i + 1] = (h2[i] + (s[i] - 'a' + 1) * p_pow2[i]) % m2;
      h3[i + 1] = (h3[i] + (s[i] - 'a' + 1) * p_pow3[i]) % m3;
      h4[i + 1] = (h4[i] + (s[i] - 'a' + 1) * p_pow4[i]) % m4;
    }

    set<string> ans;

    for (lli i = 0; i <= n - 2; i++) {
      lli cur_h = (((h[n] - h[n - i] + (h[n - (i + 2)] * p_pow[2])) % m) + m) % m;
      lli cur_h2 = (((h2[n] - h2[n - i] + (h2[n - (i + 2)] * p_pow2[2])) % m2) + m2) % m2;
      lli cur_h3 = (((h3[n] - h3[n - i] + (h3[n - (i + 2)] * p_pow3[2])) % m3) + m3) % m3;
      lli cur_h4 = (((h4[n] - h4[n - i] + (h4[n - (i + 2)] * p_pow4[2])) % m4) + m4) % m4;

      // cout << (to_string(cur_h) + to_string(cur_h2) + to_string(cur_h3) + to_string(cur_h4)) << endl;
      ans.insert((to_string(cur_h) + to_string(cur_h2) + to_string(cur_h3) + to_string(cur_h4)));
    }

    cout << ans.size() << endl;
  }
}
