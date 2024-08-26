/*
g++ -std=c++17 -o bin/out 166_D_Div2.cpp && ./bin/out
*/

#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <unordered_set>
#include <vector>

#define lli long long int
#define ulli unsigned long long int

using namespace std;

string s, good_alphabet;
vector<lli> bad_prefix_sum;

bool is_good(char c) { return good_alphabet[c - 'a'] == '1'; }

lli bads_between(lli i, lli j) {
  if (i == 0)
    return bad_prefix_sum[j];
  return bad_prefix_sum[j] - bad_prefix_sum[i - 1];
}

int main() {
  lli max_acc_bad;
  cin >> s >> good_alphabet >> max_acc_bad;
  bad_prefix_sum.resize(s.size() + 5);

  if (!is_good(s[0]))
    bad_prefix_sum[0]++;
  for (int i = 1; i < s.size(); i++) {
    bad_prefix_sum[i] = bad_prefix_sum[i - 1];
    if (!is_good(s[i]))
      bad_prefix_sum[i]++;
  }

  // HASHING
  lli m = 1e9 + 9;
  lli p = 31;
  lli n = s.size();

  vector<lli> p_pow(n);
  p_pow[0] = 1;
  for (lli i = 1; i < n; i++) {
    p_pow[i] = (p_pow[i - 1] * p) % m;
  }

  vector<lli> h(n + 1, 0);
  for (lli i = 0; i < n; i++) {
    h[i + 1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % m;
  }

  lli cnt = 0;
  for (lli l = 1; l <= n; l++) {
    unordered_set<lli> hs;
    for (lli i = 0; i <= n - l; i++) {
      if (bads_between(i, i + l - 1) > max_acc_bad)
        continue;
      lli cur_h = (h[i + l] + m - h[i]) % m;
      cur_h = (cur_h * p_pow[n - i - 1]) % m;

      // if (hs.find(cur_h) == hs.end()) {
      //   for (int k = i; k < i + l; k++) {
      //     cout << s[k];
      //   }
      //   cout << " [" << bads_between(i, i + l - 1) << "]";
      //   cout << " | i: " << i << ", l: " << l << ", i+l: " << i + l;
      //   cout << endl;
      // }

      hs.insert(cur_h);
    }
    cnt += hs.size();
  }

  cout << cnt << endl;
}
