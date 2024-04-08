#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

void testcase() {
  int n, c, d;
  cin >> n >> c >> d;

  vector<int> s_vec;
  vector<vector<int>> s(n, vector<int>(n));
  vector<vector<int>> correct(n, vector<int>(n));

  int smallest = INT_MAX;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> s[i][j];
      s_vec.push_back(s[i][j]);
      if (s[i][j] < smallest)
        smallest = s[i][j];
    }
  }

  correct[0][0] = smallest;

  for (int j = 1; j < n; j++) {
    correct[0][j] = correct[0][j - 1] + d;
  }

  for (int i = 1; i < n; i++) {
    for (int j = 0; j < n; j++) {
      correct[i][j] = correct[i - 1][j] + c;
      // cout << "correct[" << i << "][" << j << "] = " << correct[i][j] <<
      // endl;
    }
  }

  vector<int> corr_vec;
  // cout << "correct: ";
  for (auto v : correct) {
    for (auto c : v)
      // cout << c << " ";
      corr_vec.push_back(c);
  }
  // cout << endl;

  sort(corr_vec.begin(), corr_vec.end());
  sort(s_vec.begin(), s_vec.end());

  if (corr_vec == s_vec) {
    cout << "YES" << endl;
    return;
  }

  cout << "NO" << endl;
  return;

  // this is so ugly
}

int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    testcase();
  }
}
