/*
g++ -std=c++17 -o bin/out NHAY.cpp && ./bin/out
*/

#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

#define lli long long int
#define ulli unsigned long long int

using namespace std;

vector<lli> rabin_karp(string const &s, string const &t) {
  const lli p = 31;
  const lli m = 1e9 + 9;
  lli S = s.size(), T = t.size();

  vector<lli> p_pow(max(S, T));
  p_pow[0] = 1;
  for (lli i = 1; i < (lli)p_pow.size(); i++)
    p_pow[i] = (p_pow[i - 1] * p) % m;

  vector<lli> h(T + 1, 0);
  for (lli i = 0; i < T; i++)
    h[i + 1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % m;
  lli h_s = 0;
  for (lli i = 0; i < S; i++)
    h_s = (h_s + (s[i] - 'a' + 1) * p_pow[i]) % m;

  vector<lli> occurences;
  for (lli i = 0; i + S - 1 < T; i++) {
    lli cur_h = (h[i + S] + m - h[i]) % m;
    if (cur_h == h_s * p_pow[i] % m)
      occurences.push_back(i);
  }
  return occurences;
}

int main() {
  lli needle_len;
  while (cin >> needle_len) {
    string needle, haystack;
    cin >> needle >> haystack;

    vector<lli> ans = rabin_karp(needle, haystack);

    for (auto &i : ans) {
      cout << i << endl;
    }
    cout << endl;
  }
}
