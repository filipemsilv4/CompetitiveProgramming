#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

bool cmp_pair(const pair<bool, int> &a, const pair<bool, int> &b) {
  return a.second < b.second;
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    string s;

    cin >> n >> s;

    vector<pair<char, int>> s_vec(26); // value, timestamp

    int count = 0;
    for (auto const &c : s) {
      if (!s_vec[c - 'a'].first) {
        s_vec[c - 'a'].first = c;
        s_vec[c - 'a'].second = ++count;
      }
    }

    sort(s_vec.begin(), s_vec.end(), cmp_pair);

    string r_s;
    for (int i = 0; i < s_vec.size(); i++) {
      if (s_vec[i].first) {
        r_s += s_vec[i].first;
      }
    }

    string r = r_s;
    sort(r.begin(), r.end());
    sort(r_s.rbegin(), r_s.rend());

    map<char, char> mp;

    for (int i = 0; i < r.size(); i++) {
      mp[r_s[i]] = r[i];
    }

    // cout << "---> ";
    for (int i = 0; i < s.size(); i++) {
      cout << mp[s[i]];
    }

    cout << endl;
  }
}
